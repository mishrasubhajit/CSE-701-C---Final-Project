/**
 * @file main.cpp
 * @author Subhajit Mishra (subhajitmishra007@gmail.com)
 * @brief The following program encrypts and decrypts a txt file using rsa algorithm
 * @version 0.1
 * @date 2020-12-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <chrono>
#include "BigInt.h"
#include "rsa.hpp"

using namespace std;
/**
 * @brief writing as binary files with sizeof(char)
 * 
 * @param out 
 * @param v 
 */
void write_vector(ofstream &out, const vector<char> &v)
{
    size_t s{v.size()};
    out.write(static_cast<char *>((void *)&s), sizeof(size_t));
    for (const char &i : v)
        out.write(static_cast<char *>((void *)&i), sizeof(char));
}
/**
 * @brief writing as binary files with sizeof(BigInt)
 * 
 * @param out 
 * @param v 
 */
void write_vector(ofstream &out, const vector<BigInt> &v)
{
    size_t s{v.size()};
    out.write(static_cast<char *>((void *)&s), sizeof(size_t));
    for (const BigInt &i : v)
        out.write(static_cast<char *>((void *)&i), sizeof(BigInt));
}

/**
 * @brief reading as binary files with sizeof(BigInt)
 * 
 * @param in 
 * @param v 
 */
void read_vector(ifstream &in, vector<BigInt> &v)
{
    size_t s{0};
    in.read(static_cast<char *>((void *)&s), sizeof(size_t));
    v.resize(s);
    for (size_t i{0}; i < s; i++)
        in.read(static_cast<char *>((void *)&v[i]), sizeof(BigInt));
}

int main()
{
    ifstream input{"test.txt", ios::binary};
    ofstream inout{"encrypt.bin", ios::binary};
    ofstream output{"decrypt.bin", ios::binary};
    if (!inout)
    {
        perror("Error: inout");
        return -1;
    }
    /**
 * @brief key-creates a vector of keys. Some other vectors are also initialized for the later use.
 * 
 */
    vector<BigInt> key{keys::private_modularNum_Euler()}, v, w, u, r;
    vector<char> c;
    /**
 * @brief reads the input file as sizeof 8-bit and stores in vector v
 * 
 */
    uint8_t s;
    while (input.read(static_cast<char *>((void *)&s), sizeof(uint8_t)))
        v.push_back(s);
    /**
 * @brief computes M^e(mod n) using M.GetPowerMod(e,n) and stores in a vector w
 * 
 */
    for (size_t i{0}; i < v.size(); ++i)
        w.push_back(v[i].GetPowerMod(key[0], key[2]));
    /**
 * @brief writes the data in the file inout - this is the encrypted file
 * 
 */
    write_vector(inout, w);
    inout.close();

    ifstream inout1{"encrypt.bin", ios::binary};
    /**
 * @brief reads from the encrypted file inout1 and stores in r
 * 
 */
    read_vector(inout1, r);
    /*
    if (w == r)
        cout << "Yes";
    else
        cout << "No";
*/

    /**
 * @brief computed C^d (Mod n) using C.GetPowerMod(d, n) and stores in a vector<BigInt> object
 * 
 */
    for (size_t i{0}; i < r.size(); ++i)
        u.push_back(r[i].GetPowerMod(key[1], key[2]));

    //for (size_t i{0}; i < w.size(); ++i)
    //    u.push_back(w[i].GetPowerMod(key[1], key[2]));

    /**
 * @brief each element of the vector<BigInt> object is converted into a string using ToString(), then is converted into an ul int using stoul
 * then converted into a char and appended in c
 */
    for (size_t i{0}; i < w.size(); ++i)
        c.push_back(char(stoul(u[i].ToString())));
    //cout << u;

    /**
 * @brief writes the vector<char> object c into output file - the decrypted file
 * 
 */
    write_vector(output, c);
    /*
    if (v == u)
        cout << "Yesss";
    else
        cout << "Nosss";*/
    inout1.close();
    output.close();

    input.close();
    cout << "Encrypted File is in encrypt.bin\n";

    cout << "Decrypted File is in decrypt.bin\n";
}

/**
 * @brief The foloowing commented out program didn't give the expected result for the decryption, even though both of these programs are same
 * The problem is happening while calling rsa::decryptFile function. While using debugger, I saw the problem was happening while reading the 
 * input file for decryption (I believe it is reading nothing) And hence, I believe a segmentation fault while computing C^d (mod n) and pushing back
 */

/*
string char_to_string(const char *c)
{
    string s;
    stringstream ss;
    ss << c;
    ss >> s;
    ss.clear();
    return s;
}



int main([[maybe_unused]] int argc, char *argv[])

{


    if (char_to_string(argv[1]) == "encrypt")
    {
        cout << "encryption going on...\n";
        rsa::encryptFile("test.txt", "encrypt.bin");
    }

    if (char_to_string(argv[1]) == "decrypt")
    {
        rsa::decryptFile("encrypt.bin", "decrypt.bin");

        
    }
}
*/

/*
cout << "Decryption going on...\n";
        ifstream inputStream{"encrypt.bin", ios::binary};
        ofstream outputStream{"decrypt.bin", ios::binary};
        ifstream inputKeys{"keys.txt"};
        if (!inputStream)
        {
            perror("Error: inputStream for decryption\n");
        }
        if (!outputStream)
        {
            perror("Error: outputStream for decryption\n");
        }
        if (!inputKeys)
            perror("Error: inputKeys for decryption");

        vector<BigInt> vec_keys, r, u;
        vector<char> c;
        string s;
        while (getline(inputKeys, s))
            vec_keys.push_back(s);
        cout << vec_keys;
        read_vector(inputStream, r);
        for (size_t i{0}; i < r.size(); ++i)
            u.push_back(r[i].GetPowerMod(vec_keys[1], vec_keys[2]));

        for (size_t i{0}; i < u.size(); ++i)
            c.push_back(char(stoul(u[i].ToString())));

        write_vector(outputStream, c);

        outputStream.close();
        inputStream.close();
        inputKeys.close();*/