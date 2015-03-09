#include <cstdio>
#include <iostream>

using namespace std;

void reversePart(int start, int end, int d[])
{
	while(start < end)
	{
		d[start] ^= d[end];
		d[end] ^= d[start];
		d[start] ^= d[end];
		++start;
		--end;
	}
}

void reverseArray(int n, int k, int d[])
{
	reversePart(0, n - 1, d);
	reversePart(0, k - 1, d);
	reversePart(k, n - 1, d);
}

void displayArray(int n, int d[])
{
	for(int i = 0; i < n; ++i)
	{
		cout << d[i] << " ";
	}
	cout << endl;
}
int main()
{
	int d[] = {1, 2, 3, 4, 5, 6, 7};

	int n = sizeof(d) / sizeof(int);

	int k = 3;

	displayArray(n, d);

	reverseArray(n, k, d);

	displayArray(n, d);

	return 0;
}
