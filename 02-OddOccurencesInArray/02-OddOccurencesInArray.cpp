// 02-OddOccurencesInArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <vector>

using namespace std;

int solution(vector<int>& A) {

    int val = 0;
    for (int i = 0; i < A.size(); i++) {
        val ^= A[i]; // XOR
    }

    return val;
}

int main()
{
    vector<int> input = {9,3,9,3,9,7,9};
    assert(solution(input) == 7);

    return 0;
}

