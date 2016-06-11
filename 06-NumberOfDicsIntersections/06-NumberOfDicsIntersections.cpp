// 06-NumberOfDicsIntersections.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long int_64;
typedef map<int_64, int_64> EventMap;

void update(EventMap& events, const int key, const int diff)
{
    if (events.find(key) == events.end())
    {
        events[key] = 0;
    }

    events[key] += diff;
}

int solution(vector<int> &A)
{
    EventMap  events;
    for (int i = 0; i < A.size(); ++i)
    {
        update(events, i - A[i], +1);
        update(events, i + A[i], -1);
    }

    int numberOfIntersections = 0;
    int currentNumberOfIntersections = 0;
    for (auto event : events)
    {
        if (event.second == +1)
        {
            numberOfIntersections += currentNumberOfIntersections;
        }

        currentNumberOfIntersections += event.second;
    }

    return numberOfIntersections;
}

int main()
{
    assert(solution(vector<int>({ 2,1 })) == 1);
    assert(solution(vector<int>({ 2,2 })) == 1);
    assert(solution(vector<int>({ 1,1 })) == 1);
    assert(solution(vector<int>({ 3,0 })) == 1);
    //assert(solution(vector<int>({1,5,2,1,4,0})) == 11);
    return 0;
}