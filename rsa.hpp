/**
 * @file rsa.hpp
 * @author Subhajit Mishra (subhajitmishra007@gmail.com)
 * @brief This header file contains the information about encrypting and decrypting files. Unfortunately, the decryption function gives a segmentation fault.
 * Even though, both of the main function and this are same 
 * @version 0.1
 * @date 2020-12-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once
#include "keys.hpp"
#include <iostream>

using namespace std;

class rsa
{
private:
    rsa(){};
    rsa(const rsa &);
    rsa &operator=(const rsa &rsa);

public:
    static void encryptFile(const char *inputfile, const char *outputfile);
    static void decryptFile(const char *inputfile, const char *outputfile);
    static void write_vector(ofstream &, const vector<BigInt> &);
    static void write_vector(ofstream &, const vector<char> &);
    static void read_vector(ifstream &, vector<BigInt> &);
};