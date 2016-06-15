// 10 - MinPerimeterRectangle - Unfinished.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "assert.h"

#include <algorithm>
#include <cmath>
#include <limits.h>

int solution(int N)
{
    int minPerimeter = INT_MAX;
    for (int i = 1; i <= sqrt(N); ++i) {
        if (N%i == 0) {
            int perimeter = 2 * (i + (N / i));
            minPerimeter = std::min(minPerimeter, perimeter);
        }
    }

    return minPerimeter;
}

int main()
{
    assert(4 == solution(1));
    assert(6 == solution(2));
    assert(8 == solution(3));
    assert(8 == solution(4));
    assert(12 == solution(5));
    assert(10 == solution(6));
    assert(22 == solution(30));

    return 0;
}

