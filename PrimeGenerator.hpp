/**
 * @file PrimeGenerator.hpp
 * @author Subhajit Mishra (subhajitmishra007@gmail.com)
 * @brief Prime number generation using Miller Rabin Primality Test and Random Search
 * @version 0.1
 * @date 2020-12-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once
#include "BigInt.h"

class PrimeGenerator
{
public:
    //generate a probable prime using random search
    static BigInt prime_generate(const int &t);

private:
    //returns true or false depending on the candidate being prime or composite
    static bool miller_rabin(const BigInt &candidate, const int &t);
};

class even_number
{
};

class small_candidate_encountered
{
};