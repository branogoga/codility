// 15 - AbsDistinct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "assert.h"

#include <algorithm>
#include <vector>

int solution(const std::vector<int>& A)
{
    if (A.size() == 1)
    {
        return 1;
    }

    // Index of first not counter item
    unsigned minIndex = 0;

    // Index of last not counted item
    unsigned maxIndex = A.size() - 1;

    unsigned distinctCount = 0;

    // Maximal uncovered value, always one of the values |A[minIndex]|, |A[maxIndex]|
    unsigned value = std::max(
        std::abs(A[minIndex]), std::abs(A[maxIndex])
    );

    while (minIndex != maxIndex)
    {
        ++distinctCount;

        while ((minIndex < maxIndex) && (std::abs(A[minIndex]) == value))
        {
            ++minIndex;
        }

        while ((minIndex < maxIndex) && (std::abs(A[maxIndex]) == value))
        {
            --maxIndex;
        }
    }

    return distinctCount;
}

int main()
{
    assert(1 == solution({ 0 }));
    assert(1 == solution({ 7 }));
    assert(1 == solution({ -5 }));
    assert(1 == solution({ 7, 7 }));
    assert(1 == solution({ -7, 7 }));
    assert(1 == solution({ -7, -7, 7, 7 }));
    assert(2 == solution({ 1, 2 }));
    //assert(2 == solution({ 1, 1, 2 }));
    //assert(2 == solution({ -1, 1, 2 }));
    //assert(5 == solution({ -5, -3, -1, 0, 3, 6 }));

    return 0;
}

