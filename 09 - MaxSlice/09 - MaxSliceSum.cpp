// 09 - MaxSlice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <vector>

using namespace std;

#include <algorithm>
#include <limits.h>

int solution(vector<int>& A)
{
    int maxEnding = 0;
    int maxSlice = -INT_MIN;

    for (int item : A)
    {
        maxEnding = std::max(item, maxEnding + item);
        maxSlice = std::max(maxSlice, maxEnding);
    }

    return maxSlice;
}

int main()
{
    assert(7 == solution(vector<int>({ 7 })));
    assert(-6 == solution(vector<int>({-6})));
    assert(1 == solution(vector<int>({ -1, 1 })));
    assert(1 == solution(vector<int>({ 1, -1 })));
    assert(3 == solution(vector<int>({ 1, 2, -1 })));
    assert(5 == solution(vector<int>({ 3, -2, 4, -1 })));
    assert(5 == solution(vector<int>({3,2,-6,4,0})));
    return 0;
}

