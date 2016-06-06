// 01-BinaryGap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>

int solution(int N)
{
    unsigned maxGap = 0;
    unsigned currentGap = 0;
    bool startCounting = false;

    while (N > 0) 
    {
        if (N % 2 == 1) 
        {
            if (startCounting)
            {
                if (currentGap > maxGap)
                {
                    maxGap = currentGap;
                }
            }
            else
            {
                startCounting = true;
            }
            currentGap = 0;
        }
        else
        {
            ++currentGap;
        }

        N = N / 2;
    }

    return maxGap;
}

int main()
{
    assert(2 == solution(9));
    assert(4 == solution(529));
    assert(1 == solution(20));
    assert(0 == solution(15));
    assert(5 == solution(1041));

    return 0;
}

