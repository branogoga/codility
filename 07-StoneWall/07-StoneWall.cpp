// 07-StoneWall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>

using namespace std;

#include <vector>

int solution(vector<int> &H)
{
    int numberOfBlocks = 0;
    vector<int> coveredLevel;

    for (int item : H)
    {
        int currentCoveredLevel = coveredLevel.empty() ? 0 : coveredLevel.back();

        if (currentCoveredLevel > item)
        {
            while (currentCoveredLevel > item)
            {
                coveredLevel.pop_back();
                currentCoveredLevel = coveredLevel.empty() ? 0 : coveredLevel.back();
            }
        }

        if (currentCoveredLevel < item)
        {
            ++numberOfBlocks;
            coveredLevel.push_back(item);
        }

    }

    return numberOfBlocks;
}

int main()
{
    assert(1 == solution(vector<int>({ 7 })));
    assert(1 == solution(vector<int>({ 7,7 })));
    assert(2 == solution(vector<int>({ 8,7 })));
    assert(2 == solution(vector<int>({ 7,8 })));
    assert(2 == solution(vector<int>({ 7,8,7 })));
    assert(3 == solution(vector<int>({ 1,2,3 })));
    assert(3 == solution(vector<int>({ 3,2,1 })));
    assert(3 == solution(vector<int>({ 2,1,3 })));
    assert(3 == solution(vector<int>({ 3,2,1,1,1 })));
    assert(3 == solution(vector<int>({ 1,2,3,1,1 })));
    assert(3 == solution(vector<int>({ 2,1,3,1,1 })));
    assert(7 == solution(vector<int>({8,8,5,7,9,8,7,4,8})));
    return 0;
}

