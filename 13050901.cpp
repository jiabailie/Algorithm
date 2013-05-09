/*
Given an array find the next greatest element to the right of it. [4, 5, 2, 25]
Element NextGreatestElement
4 --> 5
5 --> 25
2 --> 25
25 --> -1

Ask to solve in o(n).
*/
#include <cstdio>
#include <cstdlib>
#define MAX 100
using namespace std;

struct pn
{
    int d;
    int n;
    pn() {}
    pn(int _d, int _n) { d = _d; n = _n; }
};

int main()
{
    const int len = 4;
    int i = 0, top = -1;

    int data[len] = {4, 5, 2, 25};
    int next[len];
    pn stack[MAX];

    for(i = 0; i < len; i++)
    {
        if(top == -1) { stack[++top] = pn(data[i], i); }
        else
        {
            while(top > -1 && stack[top].d < data[i])
            {
                next[stack[top].n] = data[i];
                top--;
            }
            stack[++top] = pn(data[i], i);
        }
    }
    while(top > -1)
    {
        next[stack[top--].n] = -1;
    }

    for(i = 0; i < len; i++)
    {
        printf("%d->%d\n", data[i], next[i]);
    }

    return 0;
}
