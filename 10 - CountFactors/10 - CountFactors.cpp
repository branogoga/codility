// 10 - CountFactors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "assert.h"

#include <cmath>

int solution(int N)
{
    int numberOfDivisors = (N>1) ? 2 : 1; // 1 or 1 and N.
    for (int i = 2; i <= sqrt(N); ++i) {
        if (N%i == 0) {
            ++numberOfDivisors;
            if (i != sqrt(N)) {
                ++numberOfDivisors;
            }
        }
    }

    return numberOfDivisors;
}

int main()
{
    assert(1 == solution(1));
    assert(2 == solution(2));
    assert(2 == solution(3));
    assert(3 == solution(4));
    assert(2 == solution(5));
    assert(4 == solution(6));
    assert(2 == solution(7));
    assert(4 == solution(8));
    assert(8 == solution(24));

    return 0;
}

