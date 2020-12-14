/**
 * @file MultiplicativeInverse.cpp
 * @author Subhajit Mishra (subhajitmishra007@gmail.com)
 * @brief Computes d in  ed ≡ 1 (mod n)
 * @version 0.1
 * @date 2020-12-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "MultiplicativeInverse.hpp"

/**
 * @brief solves ax ≡ 1 (mod b)
 * 
 * @param a 
 * @param b 
 * @return vector<BigInt> - the first element is the solution, the last element is the gcd(a,b)
 */
vector<BigInt> MultiplicativeInverse::multiplicative_inverse(const BigInt &a, const BigInt &b)
{
    vector<BigInt> v;
    vector<BigInt> v1{BigIntOne, BigIntZero, a};
    vector<BigInt> v2{BigIntZero, BigIntOne, b};
    BigInt q{a / b};
    if (a < b)
    {
        vector<BigInt> w;
        w = multiplicative_inverse(b, a);
        swap(w[0], w[1]);
        return w;
    }

    while ((v1[2] % v2[2]) > BigIntZero)
    {
        v = v1 - q * v2;
        v1 = v2;
        v2 = v;
        q = v1[2] / v2[2];
    }
    return v2;
}