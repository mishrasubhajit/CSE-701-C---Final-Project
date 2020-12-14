/**
 * @file MultiplicativeInverse.hpp
 * @author Subhajit Mishra (subhajitmishra007@gmail.com)
 * @brief Computes d in  ed ≡ 1 (mod n)
 * @version 0.1
 * @date 2020-12-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once
#include "BigInt.h"
#include <iostream>
#include "vector_overloads.hpp"

using namespace std;

//class that solves x for ax ≡ 1 (mod n).
class MultiplicativeInverse
{
public:
    static vector<BigInt> multiplicative_inverse(const BigInt &, const BigInt &);
};