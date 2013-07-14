#include <cstdio>
#include <iostream>

using namespace std;

inline void swap(int& a, int& b) { int t = a; a = b; b = t; }

/*
 * k:      find kth largest number, larger than 1
 * start:  the start index of this operation
 * end:    the end index of this operation
 */
int getKthLargestNumber(int k, int start, int end, int d[])
{
    /* if k is illegal of the array length is less than k */
    if(k <= 0 || k > end - start + 1)
    {
        return -1;
    }

    /* if k equals 1 and start equals end, return d[start] */
    if(k == 1 && start == end)
    {
        return d[start];
    }

    int x = d[start];
    int i = start, j = start;

    for(i = start + 1; i <= end; i++)
    {
        if(d[i] >= x)
        {
            j = j + 1;
            swap(d[i], d[j]);
        }
    }
    swap(d[start], d[j]);

    int rank = j - start + 1;
    if(rank == k) { return d[j]; }
    if(rank > k && start < j) { return getKthLargestNumber(k,        start, j - 1, d); }
    if(rank < k && j < end)   { return getKthLargestNumber(k - rank, j + 1,   end, d); }

    return -1;
}

int main()
{
    int n = 10;
    int k = 0;
    int d[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    /* use k to test the function */
    for(k = -1; k < 12; k++)
    {
        cout << getKthLargestNumber(k, 0, 9, d) << endl;
    }

    return 0;
}
