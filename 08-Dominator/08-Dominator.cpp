// 08-Dominator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <vector>

using namespace std;

const int NO_DOMINATOR = -1;

int solution(vector<int>& A)
{
    // Find dominator candidate
    vector<int> stack;

    for (int item : A)
    {
        stack.push_back(item);
        if (stack.size() >= 2)
        {
            if (stack[stack.size() - 1] != stack[stack.size() - 2])
            {
                stack.pop_back();
                stack.pop_back();
            }
        }
    }

    if (stack.empty())
    {
        // No dominator candidate
        return NO_DOMINATOR;
    }

    // Check if the candidate is dominator
    int candidate = stack.back();
    int candidateCount = 0;
    for (int item : A)
    {
        if (item == candidate)
        {
            ++candidateCount;
        }
    }

    if (candidateCount < (A.size() / 2 + 1))
    {
        return NO_DOMINATOR;
    }

    // Find the first dominator index
    for (int index = 0; index < A.size(); ++index)
    {
        if (A[index] == candidate)
        {
            return index;
        }
    }

    return NO_DOMINATOR;
}

int main()
{
    assert(NO_DOMINATOR == solution(vector<int>(0)));
    assert(0 == solution(vector<int>({ 1 })));
    assert(0 == solution(vector<int>({ 1,1 })));
    assert(NO_DOMINATOR == solution(vector<int>({ 1,2 })));
    assert(0 == solution(vector<int>({ 1,1,2 })));
    assert(1 == solution(vector<int>({ 1,2,2 })));
    assert(0 == solution(vector<int>({ 1,1,1,2 })));
    assert(NO_DOMINATOR == solution(vector<int>({ 1,1,2,2 })));

    assert(0 == solution(vector<int>({ 3,4,3,2,3,-1,3,3 })));

    return 0;
}

