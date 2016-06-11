// 08-EquiLeader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <vector>

using namespace std;

int solution(vector<int>& A)
{
    // Find the leading value if any
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
        return 0;
    }

    // Check if the candidate is dominator
    int candidate = stack.back();

    // Count number of occurences of leading value using prefix-sums
    vector<int> count(A);
    count[0] = (A[0] == candidate) ? 1 : 0;
    for (int index = 1; index < A.size(); index++)
    {
        int increment = (A[index] == candidate) ? 1 : 0;
        count[index] = count[index-1] + increment;
    }

    // Go through the indexes and check, if count in both sub-sequences is at least half of the length of the sub-sequence
    int numberOfEquiLeaders = 0;
    for (int index = 1; index < A.size(); index++)
    {
        int numberOfLeaders1 = count[index-1];
        int numberOfLeaders2 = count.back() - count[index-1];

        int length1 = index;
        int length2 = A.size() - index;

        if((numberOfLeaders1 > length1/2)
            && (numberOfLeaders2 > length2/ 2))
        {
            ++numberOfEquiLeaders;
        }
    }

    return numberOfEquiLeaders;
}

int main()
{
    assert(2 == solution(vector<int>({ 4,3,4,4,4,2 })));
    assert(0 == solution(vector<int>({7})));
    assert(1 == solution(vector<int>({ 7,7 })));
    assert(0 == solution(vector<int>({ 7,8 })));
    assert(0 == solution(vector<int>({ 8,7 })));
    assert(2 == solution(vector<int>({ 7,7,7 })));
    assert(0 == solution(vector<int>({ 7,8,7 })));
    return 0;
}

