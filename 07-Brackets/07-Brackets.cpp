// 07-Brackets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <string>
#include <vector>

using namespace std;

const int SUCCESS = 1;
const int FAILURE = 0;

int solution(string &S)
{
    vector<char>    opened_brackets;

    for (char c : S)
    {
        if ((c == '(')
            || (c == '[')
            || (c == '{')
            )
        {
            // Open new bracket
            opened_brackets.push_back(c);
        }
        else if ((c == ')')
            || (c == ']')
            || (c == '}')
            )
        {
            if (opened_brackets.empty())
            {
                return FAILURE;
            }

            // Check, that we close 
            if (c == ')' && opened_brackets.back() == '(') {
                opened_brackets.pop_back();
            } 
            else if (c == ']' && opened_brackets.back() == '[') {
                opened_brackets.pop_back();
            }
            else if (c == '}' && opened_brackets.back() == '{') {
                opened_brackets.pop_back();
            }
        }
    }

    return opened_brackets.empty();
}

int main()
{
    assert(solution(string("")) == SUCCESS);
    assert(solution(string("()")) == SUCCESS);
    assert(solution(string("[]")) == SUCCESS);
    assert(solution(string("{}")) == SUCCESS);
    assert(solution(string("([{}])")) == SUCCESS);
    assert(solution(string("()()")) == SUCCESS);
    assert(solution(string(")")) == FAILURE);
    assert(solution(string("(")) == FAILURE);
    assert(solution(string("())")) == FAILURE);
    assert(solution(string("()(")) == FAILURE);
    assert(solution(string("([)")) == FAILURE);

    assert(solution(string("{[()()]}")) == SUCCESS);
    assert(solution(string("([)()]")) == FAILURE);

    return 0;
}

