/**
 * @file keys.cpp
 * @author Subhajit Mishra (subhajitmishra007@gmail.com)
 * @brief Generates a vector object containing keys
 * @version 0.1
 * @date 2020-12-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "keys.hpp"

using namespace std;

/**
 * @brief Generates a vector object containing keys
 * 
 * @return vector<BigInt> structure: (publickey, privatekey, modulusNumber(n), Euler Totient function)
 */
vector<BigInt> keys::private_modularNum_Euler()
{
    BigInt p{PrimeGenerator::prime_generate(10)};
    BigInt q{PrimeGenerator::prime_generate(10)};

    BigInt e{65537};
    BigInt modularNumber{p * q};
    BigInt EulerPhi{(p - BigIntOne) * (q - BigIntOne)};

    //calculating d in ed ≡ 1 (mod n), where v[0] is d
    vector<BigInt> v{MultiplicativeInverse::multiplicative_inverse(e, EulerPhi)};

    //if GCD is not 1, then it will call the function again!
    if (v[2] != 1)
    {
        return keys::private_modularNum_Euler();
    }

    //if v[0] turs out to be negative, make it positive
    int i{1};
    while (v[0] < BigIntZero)
    {
        v[0] = v[0] + (i * EulerPhi);
        i++;
    }

    vector<BigInt> vec{e, v[0], modularNumber, EulerPhi};
    return vec;
}
