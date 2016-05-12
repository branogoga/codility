// 03-CountDiv.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <math.h>

using namespace std;

// A >= 0
// K >= 1
int divisors(int A, int K)
{
    return (A / K) + 1 /*zero*/ + (((A>=1)&&(K>1)) ? 1 : 0) /*one*/;
}

int solution(int A, int B, int K)
{
    int result = 0;

    if (A*B <= 0)
    {
        // One positive or zero and one negative or zero
        return divisors(A, K) + divisors(B, K) - 1 /*zero*/;
    }
    else if (A>=0)
    {
        // Both positive
        return divisors(B,K) - divisors(A-1,K);
    }
    else
    {
        // Both negative
        return divisors(-A, K) - divisors(-B+1, K);
    }

    result += B/K - (A-1)/K;

    return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
    {
        assert(1 == divisors(0, 5)); // 0
        assert(2 == divisors(1, 5)); // 0,1
        assert(2 == divisors(2, 5));
        assert(2 == divisors(3, 5));
        assert(2 == divisors(4, 5));
        assert(3 == divisors(5, 5)); // 0,1,5
        assert(3 == divisors(6, 5)); 
        assert(3 == divisors(7, 5)); 
        assert(3 == divisors(8, 5)); 
        assert(3 == divisors(9, 5)); 
        assert(4 == divisors(10, 5)); // 0,1,5, 10

        assert(1 == divisors(0, 1)); // 0
        assert(2 == divisors(1, 1)); // 0,1
        assert(3 == divisors(2, 1)); // 0,1,2
        assert(4 == divisors(3, 1)); // 0,1,2,3
        assert(5 == divisors(4, 1)); // 0,1,2,3,4
    }

    assert(3==solution(6,11,2));

    assert(21 == solution(1, 345, 17));
    assert(20 == solution(2, 345, 17));
    assert(20 == solution(11, 345, 17));
    assert(20 == solution(16, 345, 17));
    assert(20 == solution(17, 345, 17));
    assert(19 == solution(18, 345, 17));

    assert(2 == solution(2, 4, 2));
    assert(0 == solution(6, 9, 5));

    assert(1 == solution(10, 10, 5));
    assert(0 == solution(10, 10, 7));
    assert(0 == solution(10, 10, 11));
    assert(1 == solution(0, 0, 11));
    assert(2 == solution(0, 1, 11));
    assert(1 == solution(1, 1, 11));

    assert(2 == solution(0, +2, 2));
    assert(2 == solution(-2, 0, 2));
    assert(2 == solution(-2, 2, 2));
    assert(3 == solution(-11, -6, 2));
    assert(2 == solution(-4, -2, 2));

	return 0;
}

