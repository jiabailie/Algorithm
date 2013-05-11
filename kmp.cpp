#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#define DEBUG

using namespace std;

void calNext(int n, int* next, char pattern[])
{
    int i = 0, j = -1;
    next[0] = -1;
    while(i < n)
    {
        if(j == -1 || pattern[i] == pattern[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
    #ifdef DEBUG
    cout << "next array:" << endl;
    for(i = 0; i < n; i++)
    {
        cout << next[i] << endl;
    }
    #endif
}

void kmp(char pattern[], char source[], vector<int>& starts)
{
    int i = 0, j = 0;
    int lp = strlen(pattern), ls = strlen(source);
    int* next = (int*)malloc(sizeof(int) * lp);

    memset(next, 0, sizeof(int) * lp);
    calNext(lp, next, pattern);
    starts.clear();

    /* i represents the position of source */
    /* j represents the position of pattern */
    while(i + j < ls)
    {
        if(source[i + j] == pattern[j])
        {
            if(j == lp - 1)
            {
                /* if it has reached the end of pattern */
                /* push the substring's start position into the vector */
                starts.push_back(i);
                j = 0;
                i = i + j + 1; /* set the next search position in source */
                continue;
            }
            j = j + 1;
        }
        else
        {
            i = i + j - next[j]; /* if the position doesn't match, reset the source searching position */
            if(next[j] > -1)
            {
                j = next[j];
            }
            else
            {
                j = 0;
            }
        }
    }
}

/* using traditional method to get all start positions of matching substrings */
void simple(char pattern[], char source[], vector<int>& starts)
{
    int i = 0, j = 0;
    int lp = strlen(pattern), ls = strlen(source);

    starts.clear();
    for(i = 0; i < ls; i++)
    {
        for(j = 0; j < lp; j++)
        {
            if(pattern[j] != source[i + j])
            {
                break;
            }
        }
        if(j == lp)
        {
            starts.push_back(i);
        }
    }
}

int main()
{
    vector<int> starts;
    char pattern[] = "abc";
    char source[] = "ababcaaabcabc";

    /* using the traditional method to get all matching substrings' start positions */
    simple(pattern, source, starts);
    cout << "Using the simple method:" << endl;
    for(vector<int>::iterator it = starts.begin(); it != starts.end(); it++)
    {
        cout << (*it) << endl;
    }

    /* using kmp method to get all matching substrings' start positions */
    kmp(pattern, source, starts);
    cout << "Using kmp method:" << endl;
    for(vector<int>::iterator it = starts.begin(); it != starts.end(); it++)
    {
        cout << (*it) << endl;
    }

    return 0;
}
