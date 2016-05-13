// 06-Distinct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>& A)
{
    if (A.empty())
    {
        return 0;
    }

    make_heap(A.begin(), A.end());
    sort_heap(A.begin(), A.end());

    int lastValue = A[0];
    int distinct = 1;

    for (auto value : A)
    {
        if (value != lastValue)
        {
            ++distinct;
            lastValue = value;
        }
    }

    return distinct;
}

int main()
{
    assert(solution(vector<int>({ 2,1,1,2,3,1 })) == 3);

    return 0;
}

