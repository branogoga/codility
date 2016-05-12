// 03-MinAvgTwoSlices.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

double average(const vector<int>& prefixSums, const unsigned sliceSize, const unsigned P)
{
    unsigned Q = P + sliceSize - 1;
    int sum = prefixSums[Q] - ((P>0) ? prefixSums[P - 1] : 0);
    return sum / (double)sliceSize;
}

int solution(vector<int> &A)
{
    //// Dump A
    //cout << "A[]:";
    //for (auto value : A)
    //{
    //    cout << value << ",";
    //}
    //cout << endl;

    // Calculate prefix sums
    vector<int> prefixSums(A.size());

    prefixSums[0] = A[0];
    for (size_t i = 1; i<A.size(); i++)
    {
        prefixSums[i] = prefixSums[i - 1] + A[i];
    }

    //// Dump prefixSums
    //cout << "prefixSums[]:";
    //for (auto value : prefixSums)
    //{
    //    cout << value << ",";
    //}
    //cout << endl;

    // Calculate slice averages
    unsigned sliceSize = 2;
    vector<double> averages2(A.size()-sliceSize+1);
    for (unsigned P = 0; P < A.size() - sliceSize + 1; P++)
    {
        averages2[P] = average(prefixSums, sliceSize, P);
    }

    sliceSize = 3;
    vector<double> averages3(A.size() - sliceSize + 1);
    for (unsigned P = 0; P < A.size() - sliceSize + 1; P++)
    {
        averages3[P] = average(prefixSums, sliceSize, P);
    }

    //// Dump averages
    //cout << "averages[]:";
    //for (auto value : averages)
    //{
    //    cout << value << ",";
    //}
    //cout << endl;

    // Find minimal average of slice length 2
    const double MAXIMAL_AVERAGE = 10000;
    double minimalAverage = MAXIMAL_AVERAGE;
    unsigned minimalIndex = 0;
    for (size_t i = 0; i < averages2.size(); i++)
    {
        if (averages2[i] < minimalAverage)
        {
            minimalIndex = i;
            minimalAverage = averages2[i];
        }
    }

    // Find minimal average of slice length 2
    for (size_t i = 0; i < averages3.size(); i++)
    {
        if (averages3[i] < minimalAverage)
        {
            minimalIndex = i;
            minimalAverage = averages3[i];
        }
    }

    return minimalIndex;
}

int main()
{
    {
        vector<int> A = { 4,2,2,5,1,5,8 };
        int result = solution(A);
        assert(1 == result);
    }

    {
        vector<int> A = { 9,9,9,6,8,5,9 };
        int result = solution(A);
        assert(3 == result);
    }

    return 0;
}

