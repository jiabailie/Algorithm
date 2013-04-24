/* heap sort, use big heap */
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

inline void swap(int& a, int& b) { int c = a; a = b; b = c; }

/* big heap */
void buildheap(int n, int a[])
{
    int i = 0;
    int max = 0, l = 0, r = 0;
    for(i = n / 2; i >= 0; i--)
    {
        max = i;
        l = 2 * i + 1;
        r = 2 * i + 2;
        if(l < n && a[l] > a[max]) { max = l; }
        if(r < n && a[r] > a[max]) { max = r; }
        if(max != i) { swap(a[max], a[i]); }
    }
}
void heapsort(int n, int a[])
{
    int i = 0;
    buildheap(n, a);

    for(i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        buildheap(i, a);
    }
}

int main()
{
    int a[10] = {15, 2, 3, 91, 8, 4, 5, 6, 65, 7 };

    heapsort(10, a);

    for(int i = 0; i < 10; i++){ cout << a[i] << " "; }

    return 0;
}
