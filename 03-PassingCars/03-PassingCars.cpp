// 03-PassingCars.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
    // Calculate postfix sums
    for (int i = A.size() - 2; i >= 0; --i)
    {
        A[i] = A[i] + A[i + 1];
    }

    //for(auto value : A)
    //{
    //    cout << value << ",";
    //}
    //cout<<endl;

    int numberOfPairs = 0;
    for (int i = 0; i<A.size() - 1; ++i)
    {
        if (A[i] == A[i + 1])
        {
            numberOfPairs += A[i];
        }

        if (numberOfPairs > 1000000000)
        {
            return -1;
        }
    }

    return numberOfPairs;
}

int _tmain(int argc, _TCHAR* argv[])
{
    vector<int> cars = { 0,1,0,1,1 };
    assert(5 == solution(cars));

	return 0;
}

