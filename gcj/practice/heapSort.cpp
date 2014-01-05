#include "heapSort.h"
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

inline void swap(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void adjustSmall(int c, int n, int a[])
{
	int s = 0;
	int p = 0;
	while(c > 0)
	{
		s = ((c & 1) == 0 ? c - 1 : c + 1);
		p = c >> 1;

		if(s < n && a[s] < a[c])
		{
			c = s;
		}
		if(p >= 0 && a[c] < a[p])
		{
			swap(a[c], a[p]);
		}
		c = p;
	}
}

int main()
{
	int i = 0;
	int n = 0;
	int* a = NULL;

	cin >> n;
	a = new int[n];

	for(i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for(i = n - 1; i > 0; i--)
	{
		adjustSmall(i, n, a);
		swap(a[0], a[i]);
	}

	cout << endl;

	for(i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cin >> n;

	return 0;
}