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
        if ((unsigned)value < N+1)
        {
            values[value] = true;
        }
        else
        {
            return 0; // some value must be missing!
        }
    }

    bool isPermutation = true;
    for (unsigned i = 1; i<values.size(); ++i)
    {
        isPermutation &= values[i];
    }

    if (isPermutation == true)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    {
        vector<int> example = { 4,1,3,2 };
        assert(1 == solution(example));
    }

    {
        vector<int> example = { 4,1,3 };
        assert(0 == solution(example));
    }

    return 0;
}

