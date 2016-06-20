// 10 - Peaks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include "assert.h"

using namespace std;

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

bool covers(vector<int>& peaks, int N, int numberOfBlocks)
{
    int blockSize = N / numberOfBlocks;

    vector<int> blocks(numberOfBlocks, 0);
    for (int peak : peaks)
    {
        ++blocks[peak / blockSize];
    }

    for (int peaksInBlock : blocks)
    {
        if (peaksInBlock == 0)
        {
            return false;
        }
    }

    return true;
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
    int N = A.size();
    vector<int> divisors = getDivisors(A.size());

    //
    // Binary search over potential candidates
    //
    int minNumberOfBlocks = 1;
    int maxNumberOfBlocks = A.size();
    int currentNumberOfBlocks = maxNumberOfBlocks;

    while (maxNumberOfBlocks - minNumberOfBlocks > 1)
    {
        if (covers(peaks, A.size(), currentNumberOfBlocks))
        {
            minNumberOfBlocks = currentNumberOfBlocks;
        }
        else
        {
            maxNumberOfBlocks = currentNumberOfBlocks;
        }

        currentNumberOfBlocks = (minNumberOfBlocks + maxNumberOfBlocks) / 2;
    }

    return currentNumberOfBlocks;
}

int main()
{
    assert(0 == solution(vector<int>({ 1 })));
    assert(0 == solution(vector<int>({ 1,1 })));
    assert(0 == solution(vector<int>({ 1,1,1 })));
    assert(1 == solution(vector<int>({ 1,2,1})));
    assert(3 == solution(vector<int>({1,2,3,4,3,4,1,2,3,4,6,2})));
    return 0;
}

