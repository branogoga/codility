// 01-PermMissingElem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    const int N = A.size();

    vector<bool>    values(N + 2);
    for (auto value : values)
    {
        value = false;
    }

    for (int i = 0; i<N; i++)
    {
        values[A[i]] = true;
    }

    for (int i = 1; i<N + 2; ++i)
    {
        if (values[i] == false)
        {
            return i;
        }
    }

    return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
    vector<int> example = { 2,3,1,5 };
    assert(4 == solution(example));

	return 0;
}

