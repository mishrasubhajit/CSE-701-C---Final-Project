//Prime number generation using Miller Rabin Primality Test and Random Search
#include "BigInt.h"

class PrimeGenerator
{
public:
    //finds r in 2^d * r = n - 1
    //    static BigInt power2(const BigInt &candidate);

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