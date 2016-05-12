// 02-FrogRiverOne.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <vector>

using namespace std;

bool canCrossTheRiver(const vector<bool>& river)
{
    static int maxReachableIndex = 1;
    for (size_t i = maxReachableIndex; i<river.size(); ++i)
    {
        if (river[i] == false)
        {
            return false;
        }
        else
        {
            maxReachableIndex = i;
        }
    }

    return true;
}

int solution(int X, vector<int>& A)
{
    const int N = A.size();

    vector<bool> river(X + 1);
    for (int i = 0; i<X + 1; ++i)
    {
        river[i] = false;
    }

    for (int i = 0; i<N; ++i)
    {
        river[A[i]] = true;

        if (canCrossTheRiver(river) == true)
        {
            return i;
        }
    }

    return -1;
}

int _tmain(int argc, _TCHAR* argv[])
{
    vector<int> leafs = {1,3,1,4,2,3,5,4};
    assert(6 == solution(5, leafs));
	return 0;
}

