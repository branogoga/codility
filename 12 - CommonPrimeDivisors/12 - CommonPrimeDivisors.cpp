// 12 - CommonPrimeDivisors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (a%b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a%b);
    }
}

bool hasSamePrimeDivisors(int a, int b);

bool containsAllPrimeDivisorsOf(int a, int b)
{
    if (a % b == 0)
    {
        return true;
    }

    int greatestCommonDivisor = gcd(a, b);

    return hasSamePrimeDivisors(a, greatestCommonDivisor);
}

bool hasSamePrimeDivisors(int a, int b)
{
    int greatestCommonDivisor = gcd(a, b);

    if (greatestCommonDivisor == 1)
    {
        if (a != 1 || b != 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    if (!containsAllPrimeDivisorsOf(a / greatestCommonDivisor, greatestCommonDivisor))
    {
        return false;
    }

    if (!containsAllPrimeDivisorsOf(b / greatestCommonDivisor, greatestCommonDivisor))
    {
        return false;
    }

    return true;
}

int solution(vector<int>& A, vector<int>& B)
{
    int count = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        if (hasSamePrimeDivisors(A[i], B[i]))
        {
            ++count;
        }
    }

    return count;
}

int main()
{
    assert(containsAllPrimeDivisorsOf(1,1));
    assert(!containsAllPrimeDivisorsOf(1, 2));
    assert(!containsAllPrimeDivisorsOf(1, 3));
    assert(!containsAllPrimeDivisorsOf(1, 4));
    assert(!containsAllPrimeDivisorsOf(1, 5));
    assert(!containsAllPrimeDivisorsOf(1, 6));

    assert(containsAllPrimeDivisorsOf(2, 2));
    assert(!containsAllPrimeDivisorsOf(2, 3));
    assert(containsAllPrimeDivisorsOf(2, 4));
    assert(!containsAllPrimeDivisorsOf(2, 5));
    assert(!containsAllPrimeDivisorsOf(2, 6));

    assert(hasSamePrimeDivisors(2,4));
    assert(hasSamePrimeDivisors(15, 75));
    assert(!hasSamePrimeDivisors(10, 30));
    assert(!hasSamePrimeDivisors(3, 5));
    assert(hasSamePrimeDivisors(6, 12));
    assert(hasSamePrimeDivisors(6, 18));
    assert(hasSamePrimeDivisors(6, 24));
    assert(hasSamePrimeDivisors(6, 36));

    assert(hasSamePrimeDivisors(1, 1));
    assert(!hasSamePrimeDivisors(1, 2));
    assert(!hasSamePrimeDivisors(1, 3));
    assert(!hasSamePrimeDivisors(1, 4));
    assert(!hasSamePrimeDivisors(1, 5));
    assert(!hasSamePrimeDivisors(1, 6));
    assert(!hasSamePrimeDivisors(1, 7));
    assert(!hasSamePrimeDivisors(1, 8));
    assert(!hasSamePrimeDivisors(1, 9));
    assert(!hasSamePrimeDivisors(1, 10));

    assert(hasSamePrimeDivisors(2, 2));
    assert(!hasSamePrimeDivisors(2, 3));
    assert(hasSamePrimeDivisors(2, 4));
    assert(!hasSamePrimeDivisors(2, 5));
    assert(!hasSamePrimeDivisors(2, 6));
    assert(!hasSamePrimeDivisors(2, 7));
    assert(hasSamePrimeDivisors(2, 8));
    assert(!hasSamePrimeDivisors(2, 9));
    assert(!hasSamePrimeDivisors(2, 10));

    assert(hasSamePrimeDivisors(3, 3));
    assert(!hasSamePrimeDivisors(3, 4));
    assert(!hasSamePrimeDivisors(3, 5));
    assert(!hasSamePrimeDivisors(3, 6));
    assert(!hasSamePrimeDivisors(3, 7));
    assert(!hasSamePrimeDivisors(3, 8));
    assert(hasSamePrimeDivisors(3, 9));
    assert(!hasSamePrimeDivisors(3, 10));

    assert(hasSamePrimeDivisors(4, 4));
    assert(!hasSamePrimeDivisors(4, 5));
    assert(!hasSamePrimeDivisors(4, 6));
    assert(!hasSamePrimeDivisors(4, 7));
    assert(hasSamePrimeDivisors(4, 8));
    assert(!hasSamePrimeDivisors(4, 9));
    assert(!hasSamePrimeDivisors(4, 10));

    assert(hasSamePrimeDivisors(5, 5));
    assert(!hasSamePrimeDivisors(5, 6));
    assert(!hasSamePrimeDivisors(5, 7));
    assert(!hasSamePrimeDivisors(5, 8));
    assert(!hasSamePrimeDivisors(5, 9));
    assert(!hasSamePrimeDivisors(5, 10));

    assert(hasSamePrimeDivisors(6, 6));
    assert(!hasSamePrimeDivisors(6, 7));
    assert(!hasSamePrimeDivisors(6, 8));
    assert(!hasSamePrimeDivisors(6, 9));
    assert(!hasSamePrimeDivisors(6, 10));

    assert(hasSamePrimeDivisors(7, 7));
    assert(!hasSamePrimeDivisors(7, 8));
    assert(!hasSamePrimeDivisors(7, 9));
    assert(!hasSamePrimeDivisors(7, 10));

    assert(hasSamePrimeDivisors(8, 8));
    assert(!hasSamePrimeDivisors(8, 9));
    assert(!hasSamePrimeDivisors(8, 10));

    assert(hasSamePrimeDivisors(9, 9));
    assert(!hasSamePrimeDivisors(9, 10));

    assert(hasSamePrimeDivisors(10, 10));

    return 0;
}

