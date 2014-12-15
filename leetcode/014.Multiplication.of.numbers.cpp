#include <cstdio>
#include <iostream>

using namespace std;

void array_multiplication(int A[], int OUTPUT[], int n) 
{
	if(n == 0)
	{
		return;
	}
	if(n == 1)
	{
		OUTPUT[0] = 1;
		return;
	}
	int i = 0;
	int *pre = new int[n];
	int *pos = new int[n];

	for(i = 0; i < n; ++i)
	{
		pre[i] = pos[i] = 1;
	}

	for(i = 1; i < n; ++i)
	{
		pre[i] = A[i - 1] * pre[i - 1];
	}
	for(i = n - 2; i >= 0; --i)
	{
		pos[i] = A[i + 1] * pos[i + 1];
	}
	for(i = 0; i < n; ++i)
	{
		OUTPUT[i] = pre[i] * pos[i];
	}

	delete[] pre;
	delete[] pos;
}

void displayArray(int n, int a[])
{
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	const int n = 5;
	int a[n] = {4, 3, 2, 1, 2};
	int o[n] = {0, 0, 0, 0, 0};

	array_multiplication(a, o, n);

	displayArray(n, a);
	displayArray(n, o);

	return 0;
}