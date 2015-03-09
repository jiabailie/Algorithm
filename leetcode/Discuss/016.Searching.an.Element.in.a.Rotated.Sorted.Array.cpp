#include <cstdio>
#include <iostream>
#include <algorithm>

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

int rotated_binary_search(int A[], int N, int key) 
{
	int L = 0;
	int R = N - 1;

	while(L <= R)
	{
		int M = L + ((R - L) / 2);
		if(A[M] == key)
		{
			return M;
		}
		// the bottom half is sorted
		if(A[L] <= A[M])
		{
			if(A[L] <= key && key < A[M])
			{
				R = M - 1;
			}
			else
			{
				L = M + 1;
			}
		}
		// the upper half is sorted
		else
		{
			if(A[M] < key && key <= A[R])
			{
				L = M + 1;
			}
			else
			{
				R = M - 1;
			}
		}
	}

	return -1;
}

int main()
{
	const int n = 10;
	int A[n];

	for(int i = 0; i < n; ++i)
	{
		A[i] = rand() % 100;
	}

	sort(A, A + n);

	reverseArray(n, 4, A);

	for(int i = 0; i < n; ++i)
	{
		cout << i << ":" << rotated_binary_search(A, n, A[i]) << endl;
	}

	return 0;
}