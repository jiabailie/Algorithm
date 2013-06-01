/*
Let A = A[1], ... , A[n] be an array of n positive integers.
Let s = A[1] + ... + A[n] be the sum of all the numbers in the array.
For 1 <= i <= n, let S(i) = s - A[i].
Design a linear time algorithm (O(n)) to compute S[1], ... , S[n] only with plus operations
(you are not allowed to use the minus operation)
*/
#include <cstdio>
#include <iostream>
#include <cstring>

const int len = 4;

using namespace std;

int main()
{
    int sum = 0, i = 0;
    int data[len] = {1, 2, 3, 4};
    int xdat[len];

    memset(xdat, 0, sizeof(xdat));

    for(i = 0; i < len; i++)
    {
        sum += data[i];
    }

    for(i = 0; i < len; i++)
    {
        xdat[i] = sum + (~data[i] + 1);
    }

    for(i = 0; i < len; i++)
    {
        cout << xdat[i] << " ";
    }

    return 0;
}
