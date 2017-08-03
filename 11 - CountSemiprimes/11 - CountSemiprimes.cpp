// 11 - CountSemiprimes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <vector>

using namespace std;

/// Find smallest prime divisor for each number
vector<int> sieveOfEratosthenes(int N)
{
    vector<int> sieve(N+1, 0); // +1 zero indexed
    sieve[0] = 0; // number 2 is a prime
    int i = 2;
    while (i*i <= N)
    {
        if (sieve[i] == 0)
        {
            int k = i*i;
            while (k <= N)
            {
                if (sieve[k] == 0)
                {
                    sieve[k] = i;
                }
                k += i;
            }
        }
        i += 1;
    }

    return sieve;
}

bool isPrime(int N, const vector<int>& sieve)
{
    return (N > 1) && (sieve[N] == 0);
}

bool isSemiprime(int N, const vector<int>& sieve)
{
    int smallestPrimeDivisor = sieve[N];
    if (smallestPrimeDivisor == 0)
    {
        return false;
    }

    return isPrime(smallestPrimeDivisor, sieve) && isPrime(N / smallestPrimeDivisor, sieve);
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q)
{
    vector<int> sieve = sieveOfEratosthenes(N+1);

    // Precalc number of semiprimes up to the index (modification of prefix-sums)
    vector<int> numberOfSemiprimes(N+1, 0);
    numberOfSemiprimes[0] = 0;
    for (int i = 1; i < N+1; ++i)
    {
        numberOfSemiprimes[i] = numberOfSemiprimes[i - 1];
        if (isSemiprime(i, sieve))
        {
            numberOfSemiprimes[i]++;
        }
    }

    // Go through the queries and store the answer
    vector<int> answers(P.size(), 0);
    for (int i = 0; i < P.size(); ++i)
    {
        int p = P[i];
        int q = Q[i];
        answers[i] = numberOfSemiprimes[q] - numberOfSemiprimes[p-1];
    }

    return answers;
}

int main()
{
    // Test sieve
    assert(vector<int>({0,0,0,0,2,0,2,0,2,3,2,0,2,0,2,3,2,0,2,0,2}) == sieveOfEratosthenes(20));

    // Test isPrime
    vector<int> sieve = sieveOfEratosthenes(26);
    assert(!isPrime(0, sieve));
    assert(!isPrime(1, sieve));
    assert(isPrime(2, sieve));
    assert(isPrime(3, sieve));
    assert(!isPrime(4, sieve));
    assert(isPrime(5, sieve));
    assert(!isPrime(6, sieve));
    assert(isPrime(7, sieve));
    assert(!isPrime(8, sieve));
    assert(!isPrime(9, sieve));
    assert(!isPrime(10, sieve));
    assert(isPrime(11, sieve));
    assert(!isPrime(12, sieve));
    assert(isPrime(13, sieve));
    assert(!isPrime(14, sieve));
    assert(!isPrime(15, sieve));
    assert(!isPrime(16, sieve));
    assert(isPrime(17, sieve));
    assert(!isPrime(18, sieve));
    assert(isPrime(19, sieve));

    // Test isSemiprime
    assert(!isSemiprime(0, sieve));
    assert(!isSemiprime(1, sieve));
    assert(!isSemiprime(2, sieve));
    assert(!isSemiprime(3, sieve));
    assert(isSemiprime(4, sieve));
    assert(!isSemiprime(5, sieve));
    assert(isSemiprime(6, sieve));
    assert(!isSemiprime(7, sieve));
    assert(!isSemiprime(8, sieve));
    assert(isSemiprime(9, sieve));
    assert(isSemiprime(10, sieve));
    assert(!isSemiprime(11, sieve));
    assert(!isSemiprime(12, sieve));
    assert(!isSemiprime(13, sieve));
    assert(isSemiprime(14, sieve));
    assert(isSemiprime(15, sieve));
    assert(!isSemiprime(16, sieve));
    assert(!isSemiprime(17, sieve));
    assert(!isSemiprime(18, sieve));
    assert(!isSemiprime(19, sieve));
    assert(!isSemiprime(20, sieve));
    assert(isSemiprime(21, sieve));
    assert(isSemiprime(22, sieve));
    assert(!isSemiprime(23, sieve));
    assert(!isSemiprime(24, sieve));
    assert(isSemiprime(25, sieve));
    assert(isSemiprime(26, sieve));

    // Test solution
    assert(vector<int>({ 10,4,0 }) == solution(26, vector<int>({ 1,4,16 }), vector<int>({ 26,10,20 })));

    return 0;
}

