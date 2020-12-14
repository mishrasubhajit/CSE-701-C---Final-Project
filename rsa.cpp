/**
 * @file rsa.cpp
 * @author Subhajit Mishra (subhajitmishra007@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-12-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "rsa.hpp"
#include <fstream>
using namespace std;

void rsa::write_vector(ofstream &out, const vector<BigInt> &v)
{
    size_t s{v.size()};
    out.write(static_cast<char *>((void *)&s), sizeof(size_t));
    for (const BigInt &i : v)
        out.write(static_cast<char *>((void *)&i), sizeof(BigInt));
}

void rsa::write_vector(ofstream &out, const vector<char> &v)
{
    size_t s{v.size()};
    out.write(static_cast<char *>((void *)&s), sizeof(size_t));
    for (const char &i : v)
        out.write(static_cast<char *>((void *)&i), sizeof(char));
}

void rsa::read_vector(ifstream &in, vector<BigInt> &v)
{
    size_t s{0};
    in.read(static_cast<char *>((void *)&s), sizeof(size_t));
    v.resize(s);
    for (size_t i{0}; i < s; i++)
        in.read(static_cast<char *>((void *)&v[i]), sizeof(BigInt));
}

void rsa::encryptFile(const char *inputfile, const char *outputfile)
{
    vector<BigInt> key{keys::private_modularNum_Euler()};
    ifstream inputStream{inputfile, ios::binary};
    ofstream outputStream{outputfile, ios::binary};
    ofstream keysTxt{"keys.txt"};
    if (!inputStream)
    {
        perror("Error: inputStream for Encryption\n");
    }
    if (!outputStream)
    {
        perror("Error: outputStream for Encryption\n");
    }
    if (!keysTxt)
        perror("Error: keysTxt for encryption");

    for (const BigInt &i : key)
        keysTxt << i << '\n';

    vector<BigInt> v, w;
    uint8_t s;
    while (inputStream.read(static_cast<char *>((void *)&s), sizeof(uint8_t)))
        v.push_back(s);
    cout << v;
    for (size_t i{0}; i < v.size(); ++i)
        w.push_back(v[i].GetPowerMod(key[0], key[2]));
    cout << w;
    rsa::write_vector(outputStream, w);

    keysTxt.close();
    outputStream.close();
    inputStream.close();
}

void rsa::decryptFile(const char *inputfile, const char *outputfile)
{
    ifstream inputStream{inputfile, ios::binary};
    ofstream outputStream{outputfile, ios::binary};
    ifstream inputKeys{"keys.txt"};
    if (!inputStream)
    {
        perror("Error: inputStream for decryption\n");
    }
    if (!outputStream)
    {
        perror("Error: outputStream for decryption\n");
    }
    vector<BigInt> r, u, vec_keys;
    vector<char> c;
    string s;

    while (getline(inputKeys, s))
        vec_keys.push_back(s);
    cout << vec_keys;

    rsa::read_vector(inputStream, r);
    //cout << r;
    u.resize(r.size());

    for (size_t i{0}; i < r.size(); ++i)
        u[i] = r[i].GetPowerMod(vec_keys[1], vec_keys[2]);

    for (size_t i{0}; i < u.size(); ++i)
        c.push_back(char(stoul(u[i].ToString())));
    //cout << c;

    rsa::write_vector(outputStream, c);

    outputStream.close();
    inputKeys.close();
    inputStream.close();
}
