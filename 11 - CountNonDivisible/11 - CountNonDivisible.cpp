// 11 - CountNonDivisible.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <vector>

using namespace std;

/// Find smallest prime divisor for each number
vector<int> sieveOfEratosthenes(int N)
{
    vector<int> sieve(N + 1, 0); // +1 zero indexed
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

int findNumberOfDivisors(int item, const vector<int>& sieve, const vector<int>& elementCount)
{
    int divisors = 0;

    // Are there other occurences of same value?
    int numberOfOccurences = elementCount[item];
    if (numberOfOccurences > 1)
    {
        divisors += (numberOfOccurences - 1);
    }

    if (item > 1)
    {
        divisors += elementCount[1]; // 1 is divisor of every number
    }

    // Count other divisors
    int smallestPrimeDivisor = sieve[item];
    if(smallestPrimeDivisor > 0)
    {
        divisors += elementCount[smallestPrimeDivisor];
        int otherDivisor = item / smallestPrimeDivisor;
        divisors += findNumberOfDivisors(otherDivisor, sieve, elementCount);
    }

    return divisors;
}

vector<int> solution(vector<int>& A)
{
    vector<int> sieve = sieveOfEratosthenes(2 * (A.size() + 1));

    // Count number of elements in array A
    vector<int> elementCount(2*(A.size()+1), 0);
    for (int element : A)
    {
        elementCount[element]++;
    }

    // Find number of divisors for each number in array
    vector<int> numberOfDivisors(A.size(), 0);
    for (int i = 0; i < numberOfDivisors.size(); ++i)
    {
        numberOfDivisors[i] = findNumberOfDivisors(A[i], sieve, elementCount);
    }

    // Find number of non-divisors
    vector<int> numberOfNonDivisors(numberOfDivisors.size(), 0);
    for (int i = 0; i < numberOfDivisors.size(); ++i)
    {
        numberOfNonDivisors[i] = A.size() - 1 /*self*/ - numberOfDivisors[i];
    }

    return numberOfNonDivisors;
}

int main()
{
    // Test sieve
    assert(vector<int>({ 0,0,0,0,2,0,2,0,2,3,2,0,2,0,2,3,2,0,2,0,2 }) == sieveOfEratosthenes(20));

    // Test solution
    //assert(vector<int>({ 0 }) == solution(vector<int>({ 1 })));
    //assert(vector<int>({ 0, 0 }) == solution(vector<int>({ 1,1 })));
    //assert(vector<int>({ 1, 0 }) == solution(vector<int>({ 1,2 })));
    assert(vector<int>({ 7,7,7,7,7,7,7,7 }) == solution(vector<int>({ 2,3,5,7,11,13,17,19 })));
    assert(vector<int>({2,4,3,2,0}) == solution(vector<int>({3,1,2,3,6})));

    return 0;
}

