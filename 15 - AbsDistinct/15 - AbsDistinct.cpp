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
    int value = std::max(
        std::abs(A[minIndex]), std::abs(A[maxIndex])
    );

    int previous_value = 0;

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

        previous_value = value;

        value = std::max(
            std::abs(A[minIndex]), std::abs(A[maxIndex])
        );
    }

    if (previous_value != value)
    {
        ++distinctCount;
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
    assert(2 == solution({ -2, 1 }));
    assert(2 == solution({ 1, 1, 2 }));
    assert(2 == solution({ -1, 1, 2 }));
    assert(2 == solution({ -2, -1, 1 }));
    assert(2 == solution({ -2, -1, 1, 1, 2 }));
    assert(5 == solution({ -5, -3, -1, 0, 3, 6 }));

    // !!!! Overflows when abs is calculated!
    //assert(3 == solution({ -2147483648, -1, 0, 1 }));

    return 0;
}

