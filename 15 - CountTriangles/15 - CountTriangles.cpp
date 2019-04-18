// 15 - CountTriangles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "assert.h"
#include <algorithm>
#include <vector>

using namespace std;

bool isTriangular(int a, int b, int c)
{
    return (a + b > c)
        && (a + c > b)
        && (b + c > a);
}

int slow_solution(vector<int>& A)
{
    if (A.size() < 3)
    {
        return 0;
    }

    std::sort(A.begin(), A.end());

    unsigned minIndex = 0;
    unsigned middleIndex = 1;
    unsigned maxIndex = 2;

    int numberOfTriangles = 0;

    for (minIndex = 0; minIndex < A.size() - 2; ++minIndex)
    {
        for (middleIndex = minIndex + 1; middleIndex < A.size() - 1; ++middleIndex)
        {
            for (maxIndex = middleIndex + 1; maxIndex < A.size(); ++maxIndex)
            {
                if (isTriangular(A[minIndex], A[middleIndex], A[maxIndex]))
                {
                    ++numberOfTriangles;
                }
            }

        }
    }

    return numberOfTriangles;
}

int fast_solution(vector<int>& A)
{
    if (A.size() < 3)
    {
        return 0;
    }

    std::sort(A.begin(), A.end());

    int numberOfTriangles = 0;

    for (unsigned minIndex = 0; minIndex < A.size() - 2; ++minIndex)
    {
        unsigned middleIndex = minIndex + 1;
        unsigned maxIndex = middleIndex + 1;

        // Find max index, which is still triangular
        while ((maxIndex < A.size())
            && isTriangular(A[minIndex], A[middleIndex], A[maxIndex])
            )
        {
            maxIndex++;
        }

        if (isTriangular(A[minIndex], A[middleIndex], A[maxIndex]))
        {
            numberOfTriangles += pow(2, maxIndex - minIndex - 1) - 1;
        }
    }

    return numberOfTriangles;
}

int solution(vector<int>& A)
{
    return fast_solution(A);
}

int main()
{
    assert(0 == solution(vector<int>({})));
    assert(0 == solution(vector<int>({ 1 })));
    assert(0 == solution(vector<int>({ 1, 1 })));
    assert(0 == solution(vector<int>({ 1, 1, 100 })));
    assert(1 == solution(vector<int>({ 1, 1, 1 })));
    assert(3 == solution(vector<int>({ 1, 1, 1, 1 })));
    assert(4 == solution(vector<int>({ 10, 2, 5, 1, 8, 12 })));
    return 0;
}