// 03-MinAvgTwoSlices.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<char> &S, vector<int>& P, vector<int>& Q)
{
    // Prefix sums
    vector<int> A(S.size() + 1, 0);
    vector<int> C(S.size() + 1, 0);
    vector<int> G(S.size() + 1, 0);
    vector<int> T(S.size() + 1, 0);

    for (int i = 0; i < S.size(); ++i) 
    {
        if (S[i] == 'A') {
            A[i + 1] = A[i] + 1;
            C[i + 1] = C[i];
            G[i + 1] = G[i];
            T[i + 1] = T[i];
        } else if (S[i] == 'C') {
            A[i + 1] = A[i];
            C[i + 1] = C[i] + 1;
            G[i + 1] = G[i];
            T[i + 1] = T[i];
        } else if (S[i] == 'G') {
            A[i + 1] = A[i];
            C[i + 1] = C[i];
            G[i + 1] = G[i] + 1;
            T[i + 1] = T[i];
        } else if (S[i] == 'T') {
            A[i + 1] = A[i];
            C[i + 1] = C[i];
            G[i + 1] = G[i];
            T[i + 1] = T[i] + 1;
        }
    }

    // Process queries
    vector<int> result(P.size());
    for (int i = 0; i < P.size(); ++i) {
        int low = P[i];
        int high = Q[i];

        // Is there A nucleotid on in <low, high> ?
        if (A[low] < A[high+1]) {
            result[i] = 1;
        }
        else if (C[low] < C[high+1]) {
            result[i] = 2;
        }
        else if (G[low] < G[high+1]) {
            result[i] = 3;
        }
        else if (T[low] < T[high+1]) {
            result[i] = 4;
        }
    }

    return result;
}

int main()
{
    vector<char> S = {'C','A','G','C','C','T','A'};
    vector<int> P = {2,5,0};
    vector<int> Q = {4,5,6};
    vector<int> result = solution(S,P,Q);

    vector<int> expected = { 2,4,1 };
    assert(result.size() == expected.size());
    for (int i = 0; i < result.size(); ++i) 
    {
        assert(result[i]==expected[i]);
    }

    return 0;
}

