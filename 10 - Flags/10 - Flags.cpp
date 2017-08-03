// 10 - Flags.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include "assert.h"

using namespace std;

#include <cmath>

vector<int> getDivisors(int N)
{
    vector<int> divisors;
    vector<int> divisors2;
    divisors.push_back(1);
    if (N > 1)
    {
        divisors2.push_back(N);
    }

    int sqrtN = sqrt(N);
    for (int i = 2; i <= sqrtN; ++i) {
        if (N%i == 0) {
            divisors.push_back(i);

            if (i != sqrtN)
            {
                divisors2.push_back(N / i);
            }
        }
    }
    divisors.insert(
        divisors.end(),
        divisors2.rbegin(),
        divisors2.rend()
        );

    return divisors;
}

int distance(int p, int q)
{
    return abs(p - q);
}

bool canSetup(const vector<int>& peaks, int numberOfFlags)
{
    return false;
}

int solution(vector<int>& A)
{
    //
    // Calculate peaks
    //
    vector<int> peaks;
    for (int i = 1; i < A.size() - 1; ++i)
    {
        if ((A[i - 1] < A[i]) && (A[i + 1] < A[i])) {
            peaks.push_back(i);
        }
    }

    if (peaks.empty())
    {
        return 0;
    }

    //
    // Calculate potential number of blocks (divisors of input array size)
    //
    //vector<int> divisors = getDivisors(A.size());

    //
    // Binary search over potential candidates
    //
    int minNumberOfFlags = 1;
    int maxNumberOfFlags = peaks.size();

    int currentNumberOfFlags = minNumberOfFlags;

    while (maxNumberOfFlags - minNumberOfFlags > 1)
    {
        if (canSetup(peaks, currentNumberOfFlags))
        {
            minNumberOfFlags = currentNumberOfFlags;
        }
        else
        {
            maxNumberOfFlags = currentNumberOfFlags;
        }

        currentNumberOfFlags = (minNumberOfFlags + maxNumberOfFlags) / 2;
    }

    return currentNumberOfFlags;
}

int main()
{
    assert(0 == solution(vector<int>({ 1 })));
    assert(0 == solution(vector<int>({ 1,1 })));
    assert(0 == solution(vector<int>({ 1,1,1 })));
    assert(1 == solution(vector<int>({ 1,2,1 })));
    assert(2 == solution(vector<int>({ 1,2,1,2,1 })));
    assert(2 == solution(vector<int>({ 1,2,1,2,1,2,1 })));
    assert(2 == solution(vector<int>({ 1,2,1,2,1,2,1,2,1 })));
    assert(3 == solution(vector<int>({ 1,2,1,1,2,1,1,2,1 })));
    assert(3 == solution(vector<int>({ 1,2,1,2,1,2,1,2,1,2,1 })));
    assert(3 == solution(vector<int>({ 1,5,3,4,3,4,1,2,3,4,6,2 })));
    return 0;
}

