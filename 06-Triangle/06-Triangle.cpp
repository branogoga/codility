// 06-Triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isTriangular(const vector<int>& A, unsigned p, unsigned q, unsigned r)
{
    return (A[p] + A[q] > A[r])
        && (A[q] + A[r] > A[p])
        && (A[r] + A[p] > A[q]);
}

int solution(vector<int>& A)
{
    if (A.size() < 3) {
        return 0;
    }

    make_heap(A.begin(), A.end());
    sort_heap(A.begin(), A.end());

    for (int p = 0; p < A.size() - 2; ++p) 
    {
        for (int q = p+1; q < A.size() - 1; ++q)
        {
            for (int r = q + 1; r < A.size(); ++r)
            {
                if (isTriangular(A, p, q, r)) 
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main()
{
    assert(solution(vector<int>({10,2,5,1,8,20})) == 1);
    assert(solution(vector<int>({10,50,5,1})) == 0);
}

