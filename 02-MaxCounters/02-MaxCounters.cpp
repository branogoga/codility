// 02-MaxCounters.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <vector>

using namespace std;

int g_max = 0;
int g_apply_max = 0;

void apply_last_max_counters(vector<int>& counters, const int index)
{
    if (counters[index] < g_apply_max)
    {
        counters[index] = g_apply_max;
    }
}

void increment(vector<int>& counters, const int index)
{
    apply_last_max_counters(counters, index);

    counters[index]++;

    if (counters[index] > g_max)
    {
        g_max = counters[index];
    }
}

void max_counters(vector<int>& counters)
{
    g_apply_max = g_max;
}

vector<int> solution(int N, vector<int> &A)
{
    vector<int> counters(N);
    for (auto& counter : counters)
    {
        counter = 0;
    }

    for (auto command : A)
    {
        if (command <= N)
        {
            increment(counters, command - 1);
        }
        else if (command == N + 1)
        {
            max_counters(counters);
        }
    }

    // Apply last max counters operation to all counters, which was not incremented since that time.
    for (int i = 0; i < counters.size(); ++i)
    {
        apply_last_max_counters(counters, i);
    }

    return counters;
}

// Wrong solution:
//  Complexity O(N*M) if all operations are max_counter !!!
int _tmain(int argc, _TCHAR* argv[])
{
    {
        vector<int> values = {3,4,4,6,1,4,4};
        vector<int> expected = {3,2,2,4,2};
        const int N = 5;
        vector<int> result = solution(N,values);

        assert(result.size() == N);
        for (size_t i = 0; i < result.size(); ++i)
        {
            assert(expected[i] == result[i]);
        }
    }

	return 0;
}

