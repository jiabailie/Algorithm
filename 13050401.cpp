/*
You have k lists of sorted integers. Find the smallest range that includes at least one number from each of
the k lists.

For example,
List 1: [4, 10, 15, 24, 26]
List 2: [0, 9, 12, 20]
List 3: [5, 18, 22, 30]

The smallest range here would be [20, 24] as it contains 24 from list 1, 20 from list 2, and 22 from list 3.
*/
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct pn
{
    int n; /* belong to which array */
    int d; /* the data value */
    pn(int _n, int _d) { n = _n; d = _d; }
    pn(const pn& _pn) { n = _pn.n; d = _pn.d; }
};

inline void swap(pn& a, pn& b) { pn c = a; a = b; b = c; }

void adjust(int n, pn a[])
{
    int i = 0, max = 0;
    int l = 0, r = 0;
    for(i = n / 2; i >= 0; i--)
    {
        max = i;
        l = 2 * i + 1;
        r = 2 * i + 2;
        if(l < n && a[l].d > a[max].d) { max = l; }
        if(r < n && a[r].d > a[max].d) { max = r; }
        if(max != i) { swap(a[max], a[i]); }
    }
}

void heapsort(int n, pn a[])
{
    int i = 0;
    adjust(n, a);
    for(i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        adjust(i, a);
    }
}

bool isend(int n, int m, int cur[])
{
    bool f = true;
    for(int i = 0; i < n && f; i++)
    {
        if(cur[i] != m) { f = false; }
    }
    return f;
}

int main()
{
    int i = 0, j = 0;
    const int m = 3;
    const int n = 5;
    int ms = 0, me = 0;
    int ts = 0, te = 0;
    int a[m][n] = { {4, 10, 15, 24, 26}, {0, 9, 12, 20, 35}, {5, 18, 22, 30, 50} };
    int cur[m] = { 1, 1, 1 }; /* record the current positions of each array which haven't been used */
    pn heap[m] = { pn(0, a[0][0]), pn(1, a[1][0]), pn(2, a[2][0]) };

    heapsort(m, heap);
    ms = heap[0].d;
    me = heap[m - 1].d;
    //while(!isend(m, n, cur))
    while(true)
    {
        heapsort(m, heap);
        ts = heap[0].d;
        te = heap[m - 1].d;
        /* if the current range is smaller than the minimum range */
        if(te - ts < me - ms) { ms = ts; me = te; }

        /* if the sub-array which the smallest element comes from hasn't to the end */
        if(cur[heap[0].n] != n)
        {
            heap[0].d = a[heap[0].n][cur[heap[0].n]];
            cur[heap[0].n] += 1;
        }
        else
        {
            break;
        }
    }
    cout << ms << endl;
    cout << me << endl;
    return 0;
}
