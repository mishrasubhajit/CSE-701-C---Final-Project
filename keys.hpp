/**
 * @file keys.hpp
 * @author Subhajit Mishra (subhajitmishra007@gmail.com)
 * @brief generates a vector object containing keys
 * @version 0.1
 * @date 2020-12-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once
#include "PrimeGenerator.hpp"
#include "MultiplicativeInverse.hpp"

using namespace std;

class keys
{

public:
    static vector<BigInt> private_modularNum_Euler();
};