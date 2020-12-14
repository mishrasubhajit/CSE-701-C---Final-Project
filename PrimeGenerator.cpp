#include "PrimeGenerator.hpp"
#include <random>
#include <chrono>

using namespace std;

/*
//finds r in 2^d * r = n - 1
BigInt PrimeGenerator::power2(const BigInt &candidate)
{
    if (!candidate.IsOdd())
        throw even_number{};
    if (candidate < 4)
        throw small_candidate_encountered{};

    BigInt countt;
    BigInt r{candidate - BigIntOne};
    while (r % 2 == BigIntZero)
    {
        r = r / 2;
        countt++;
    }
    return r;
}
*/

bool PrimeGenerator::miller_rabin(const BigInt &candidate, const int &t)
{

    if (!candidate.IsOdd())
        throw even_number{};
    if (candidate < 4)
        throw small_candidate_encountered{};

    BigInt countt;
    BigInt r{candidate - BigIntOne};
    while (r % 2 == BigIntZero)
    {
        r = r / 2;
        countt++;
    }

    //generating a random number //mt19937 mt_rand(chrono::steady_clock::now().time_since_epoch().count());
    random_device rd;
    mt19937 mt32(rd());

    //BigInt r{power2(candidate)};
    for (int i{0}; i <= t; ++i)
    {
        //random number between (2, candidate - 3)
        BigInt random_number{(mt32() % (candidate - 4)) + 2};

        //calculating random_number^r (mod candidate) using square and multiply algorithm
        BigInt y{random_number.GetPowerMod(r, candidate)};

        if ((y != BigIntOne) && (y != candidate - 1))
        {
            BigInt j{1};
            while ((j <= countt - 1) && (y != candidate - 1))
            {
                y = y.GetPowerMod(2, candidate);
                if (y == 1)
                    return false; //composite
                j++;
            }
            if (y != candidate - 1)
                return false; //composite
        }
    }
    return true; //probably prime

    /*
        cout << random_number << endl
             << r << endl
             << s << endl << countt;*/

    /*
    catch (const even_number &e)
    {
        cerr << "Error: the prime candidate is even\n";
    }
    catch (const small_candidate_encountered &e)
    {
        cerr << "Error: the prime candidate is small (<= 3)\n";
    }
    */
    //return 0;
}

BigInt PrimeGenerator::prime_generate(const int &t)
{
    try
    {
        random_device rd;
        mt19937 mt32(rd());

        //odd random number
        BigInt random_number{2 * mt32() + 1};
        int i{0};
        while (i >= 0)
        {
            if (miller_rabin(random_number, t))
                return random_number;
            random_number = mt32() * 2 + 1;
            ++i;
        }
    }
    catch (const even_number &e)
    {
        cerr << "Error: the prime candidate is even\n";
    }
    catch (const small_candidate_encountered &e)
    {
        cerr << "Error: the prime candidate is small (<= 3)\n";
    }
    return -1;
}