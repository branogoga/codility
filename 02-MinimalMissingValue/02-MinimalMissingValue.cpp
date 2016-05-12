// 02-MinimalMissingValue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
    const size_t N = A.size();
    vector<bool> values(N + 1);
    for (auto value : values)
    {
        value = false;
    }

    for (auto value : A)
    {
        if ((value >=0) && (value <= (int)N))
        {
            values[value] = true;
        }
    }

    // Missing value occurs in first N values, or it is N+1.
    for (unsigned i = 1; i<values.size(); ++i)
    {
        if (values[i] == false)
        {
            return i;
        }
    }

    return N + 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
    {
        vector<int> values = { -1 };
        assert(1 == solution(values));
    }

    {
        vector<int> values = {1,3,6,4,1,2};
        assert(5 == solution(values));
    }

    {
        vector<int> values = {};
        assert(1 == solution(values));
    }

    {
        vector<int> values = { 1 };
        assert(2 == solution(values));
    }

    {
        vector<int> values = { 1,2,3 };
        assert(4 == solution(values));
    }

    {
        vector<int> values = { 1,3 };
        assert(2 == solution(values));
    }

    {
        vector<int> values = { 1,3,6,4,1,2 };
        assert(5 == solution(values));
    }

    return 0;
}

