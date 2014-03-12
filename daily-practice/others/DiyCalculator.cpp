/**
 * Calculate the input expressions, and the numbers are all non-negative integers.
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#define DEBUG

using namespace std;

// 0 correct
// 1 invalid expression
// 2 0 as divisior
int ERROR_FLAG = 0;

char separator[] = {'{', '}', '(', ')', '+', '-', '*', '/'};
char levels[4][2] = {{'+', '-'}, {'*', '/'}, {'(', ')'}, {'{', '}'}};

inline bool IsSeparator(char c)
{
    for(int i = 0; i < sizeof(separator); ++i)
    {
        if(c == separator[i])
        {
            return true;
        }
    }
    return false;
}

inline int GetSeparatorLevel(char c)
{
    int i = 0, j = 0, k = -1;
    for(i = 0; i < 4 && k == -1; ++i)
    {
        for(j = 0; j < 2 && k == -1; ++j)
        {
            if(c == levels[i][j])
            {
                k = i;
            }
        }
    }
    return k;
}

void Parsor(const char *expression, vector<string> &elems, vector<int> &priority)
{
    int i = 0;
    int len = strlen(expression);
    string elem;

    for(i = 0; i < len; )
    {
        if(IsSeparator(expression[i]) || expression[i] == ' ')
        {
            if(expression[i] != ' ')
            {
                elems.push_back(string(1, expression[i]));
                priority.push_back(GetSeparatorLevel(expression[i]));
            }
            i = i + 1;
        }
        
        while(expression[i] >= '0' && expression[i] <= '9')
        {
            elem.push_back(expression[i]);
            i += 1;
        }
        if(elem.size() > 0)
        {
            elems.push_back(string(elem.begin(), elem.end()));
            priority.push_back(-1);
            elem.clear();
        }
    }
}

void CalLevel(int mlevel, vector<string> &elems, vector<int> &priority)
{

}

int Cal(const char *expression)
{
    int mlevel = -1;
    vector<string> elems;
    vector<int> priority;

    Parsor(expression, elems, priority);

    for(vector<int>::iterator it = priority.begin(); it != priority.end(); it++)
    {
        if((*it) > mlevel)
        {
            mlevel = *it;
        }
    }

    return 0;
}

int main()
{
    string line("(1 + 2 * 5) * 3 - (902 - 89 * 2) * 5 + 6 * (9 + 1 * 2) + 9");
#ifndef DEBUG
    while(getline(cin, line), line.size() > 0)
    {
#endif
        int f = Cal(line.c_str());
#ifndef DEBUG
    }
#endif

    return 0;
}