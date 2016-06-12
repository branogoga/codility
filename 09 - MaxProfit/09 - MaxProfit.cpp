// 09 - MaxProfit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <vector>

using namespace std;

#include <algorithm>

int solution(vector<int>& A)
{
    if (A.empty())
    {
        return 0;
    }

    int maxProfit = 0;
    int maxEnding = 0;

    for (int i = 1; i < A.size(); ++i)
    {
        maxEnding = std::max(0, maxEnding + (A[i] - A[i-1]));
        maxProfit = std::max(maxProfit, maxEnding);
    }

    return maxProfit;
}

int main()
{
    assert(0 == solution(vector<int>()));
    assert(0 == solution(vector<int>({0})));
    assert(0 == solution(vector<int>({ 7,7 })));
    assert(1 == solution(vector<int>({ 7,8 })));
    assert(0/*-1*/ == solution(vector<int>({ 8,7 })));
    assert(1 == solution(vector<int>({ 7,8,7 })));
    assert(3 == solution(vector<int>({ 8,9,7,9,8,10,9,8 })));
    assert(356 == solution(vector<int>({ 23171, 21011, 21123, 21366, 21013, 21367 })));
    return 0;
}

