// 12 - ChocolatesByNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>

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

int solution(int n, int m)
{
    return n / gcd(n, m);
}

int main()
{
    assert(1 == gcd(1,1));
    assert(1 == gcd(7, 1));
    assert(2 == gcd(2, 2));
    assert(1 == gcd(3, 2));
    assert(2 == gcd(4, 2));
    assert(3 == gcd(15, 6));
    assert(3 == gcd(6, 15));
    assert(5 == gcd(15, 10));
    assert(3 == gcd(15, 12));

    assert(5 == solution(10, 4));
    assert(15 == solution(15,2));
    assert(5 == solution(15, 3));
    assert(3 == solution(15, 5));
    assert(5 == solution(15, 6));

    return 0;
}

