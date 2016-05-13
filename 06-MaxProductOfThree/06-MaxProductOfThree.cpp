// 06-MaxProductOfThree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A)
{
    make_heap(A.begin(), A.end());
    sort_heap(A.begin(), A.end());

    int length = A.size();

    return max(
        A[0]*A[1]*A[length-1],
        A[length-3]*A[length-2]*A[length-1]
        );
}

int main()
{
    assert(solution(vector<int>({ -3,1,2,-2,5,6 })) == 60);

    return 0;
}

