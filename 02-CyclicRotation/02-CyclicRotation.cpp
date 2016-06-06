// 02-CyclicRotation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, int K)
{
    vector<int> result(A.size());
    for (size_t i = 0; i < result.size(); ++i)
    {
        int index = i - K;

        while(index < 0) 
        {
            index += A.size();
        }

        while (index > A.size() - 1)
        {
            index -= A.size();
        }

        result[i] = A[index];
    }

    return result;
}

void testSolution(
    vector<int>& input,
    int K,
    vector<int>& expected
    )
{
    cout << "Solution: " << endl;
    cout << " - input = { ";
    for (auto item : input)
    {
        cout << item << ",";
    }
    cout << "}" << endl;

    cout << " - K = " << K << endl;

    cout << " - expected = { ";
    for (auto item : expected)
    {
        cout << item << ",";
    }
    cout << "}" << endl;

    vector<int> result = solution(input, K);

    cout << " - result = { ";
    for (auto item : result)
    {
        cout << item << ",";
    }
    cout << "}" << endl;

    assert(result.size() == input.size());
    for (size_t i = 0; i < result.size(); ++i)
    {
        assert(result[i] == expected[i]);
    }
}

int main()
{
    testSolution(
        vector<int>({ 3,8,9,7,6 }),
        1,
        vector<int>({ 6,3,8,9,7 })
    );

    testSolution(
        vector<int>({ 3,8,9,7,6 }),
        3,
        vector<int>({ 9,7,6,3,8 })
        );

    testSolution(
        vector<int>({ 3,8,9,7,6 }),
        11,
        vector<int>({ 6,3,8,9,7 })
        );

    testSolution(
        vector<int>({ 5, -1000 }),
        1,
        vector<int>({ -1000, 5 })
    );

    return 0;
}

