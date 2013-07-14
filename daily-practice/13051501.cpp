/*
Given a string, find the longest possible even palindrome (length of palindrome is even) from it.
Eg:
Input: abcicbbcdefggfed
Output: defggfed (length is 8)

Available palindromes are
1) bcicb - has odd length
2) cbbc - even length
3) defggfed - longest palindrome with even length
*/
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#define MAX 100

using namespace std;

int getLongestEvenPalindrome(char source[], int& end)
{
    int i = 0, top = -1;
    int max = -1, pop = 0;
    int tmp = 0, tend = 0;
    int len = strlen(source);
    char stack[MAX];

    for(i = 0; i < len; i++)
    {
        if(top > -1)
        {
            if(source[i] == stack[top])
            {
                if(pop == 0)
                {
                    pop = 1;
                    tmp = 2;
                    tend = i;
                }
                else if(pop == 1)
                {
                    tmp += 2;
                    tend = i;
                }
                top--;
            }
            else if(source[i] != stack[top])
            {
                if(pop == 1)
                {
                    top = -1;
                    pop = 0;
                    stack[++top] = source[i];

                    if(tmp > max)
                    {
                        max = tmp;
                        end = tend;
                    }
                    tmp = 0;
                }
                else if(pop == 0)
                {
                    stack[++top] = source[i];
                }
            }
        }
        else if(top == -1)
        {
            stack[++top] = source[i];
        }
    }
    if(tmp > max)
    {
        max = tmp;
        end = tend;
    }

    return max;
}

int main()
{
    int end = 0;
    char source[MAX] = "abcicbbcdefggfed";
    int max = getLongestEvenPalindrome(source, end);

    cout << max << endl;
    for(int i = max - 1; i >= 0; i--)
    {
        cout << source[end - i];
    }

    return 0;
}
