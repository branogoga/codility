// 01-FrogJump.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <cmath>

int solution(int X, int Y, int D) {
    int distance = Y - X;
    int numberOfSteps = (int)std::ceil(distance / (double)D);

    return numberOfSteps;
}

int _tmain(int argc, _TCHAR* argv[])
{
    assert( 3 == solution(10,85,30) );
	return 0;
}

