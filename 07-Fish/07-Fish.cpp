// 07-Fish.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <vector>

using namespace std;

int solution(vector<int> &A, vector<int> &B)
{
    // All fishes are alive
    vector<int> fishes;
    fishes.push_back(0);

    const int N = A.size();
    for (int i = 1; i < N; ++i)
    {
        bool nextFish = false;
        if (B[fishes.back() == 1] && B[i] == 0)
        {
            while (!fishes.empty() && !nextFish && B[fishes.back() == 1] && B[i] == 0)
            {
                if (A[fishes.back()] > A[i])
                {
                    // Last fish wins.
                    nextFish = true;
                }
                else
                {
                    // New fish wins.
                    fishes.pop_back();
                }
            }

            if (!nextFish)
            {
                fishes.push_back(i);
            }
        }
        else
        {
            fishes.push_back(i);
        }
    }

    return fishes.size();
}

int main()
{
    assert(solution(vector<int>({1}), vector<int>({0})) == 1);// only one fish
    assert(solution(vector<int>({ 1,2 }), vector<int>({ 0,0 })) == 2);// same direction
    assert(solution(vector<int>({ 1,2 }), vector<int>({ 1,0 })) == 1);// one will eat other
    assert(solution(vector<int>({ 1,2 }), vector<int>({ 0,1 })) == 2);// never met
    assert(solution(vector<int>({ 3,2,1 }), vector<int>({ 1,0,0 })) == 1);// one will eat other
    assert(solution(vector<int>({ 1,2,3 }), vector<int>({ 1,0,0 })) == 2);// one will eat other, but remaining two are same direction
    assert(solution(vector<int>({ 3,2,1,4 }), vector<int>({ 1,1,0,0 })) == 1);// one will eat other
    assert(solution(vector<int>({4,3,2,1,5}), vector<int>({0,1,0,0,0})) == 2);
    return 0;
}

