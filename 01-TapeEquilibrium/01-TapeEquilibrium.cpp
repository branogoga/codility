#include "stdafx.h"
#include <assert.h>
#include <vector>

using namespace std;

int abs(int number)
{
    if (number < 0)
    {
        return -number;
    }
    else
    {
        return number;
    }
}

int solution(vector<int> &A) {

    const unsigned N = A.size();

    vector<int> sums(N);
    vector<int> rev_sums(N+1);
    vector<int> difs(N);

    sums[0] = A[0];
    rev_sums[N - 1] = A[N - 1];
    for (unsigned i = 1; i<N; ++i)
    {
        sums[i] = sums[i - 1] + A[i];
        rev_sums[N - 1 - i] = rev_sums[N - i] + A[N - 1 - i];
    }

    for (unsigned i = 0; i<N; ++i)
    {
        difs[i] = abs(sums[i] - rev_sums[i + 1]);
    }

    int min = difs[0];
    for (unsigned i = 1; i < N; ++i)
    {
        if (difs[i] < min)
        {
            min = difs[i];
        }
    }

    return min;
}
int _tmain(int argc, _TCHAR* argv[])
{
    vector<int> example = { 3,1,2,4,3 };
    assert( 1 == solution(example));

	return 0;
}

