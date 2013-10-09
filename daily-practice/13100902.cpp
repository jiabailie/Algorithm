#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#define DEBUG
//#undef	DEBUG

typedef long long LL;

using namespace std;

template<typename T>
void mallocDoubleArray(T w, T h, T**& pointer)
{
	pointer = new T*[w];
	for(int i = 0; i < w; i++)
	{
		pointer[i] = new T[h];
	}
}

template<typename T>
void releaseDoubleArray(T w, T**& pointer)
{
	if(!pointer)
	{
		cout << "The pointer is null." << endl;
		return;
	}
	for(int i = 0; i < w; i++)
	{
		if(pointer[i])
		{
			delete[] pointer[i];
		}
	}
	delete[] pointer;
}

template<typename T>
int getZeroBitAmount(T x)
{
	int ret = 0;
	while(x)
	{
		ret++;
		x &= (x - 1);
	}
	return ret;
}

template<typename T>
int getZeroAmount(T x)
{
	int tmp = 0;
	int ret = 0;
	while(x > 0)
	{
		tmp = x % 10;
		if(tmp == 1) { ret++; }
		if(tmp > 1) { ret = 0; break; }
		x /= 10;
	}
	return ret;
}

template<typename T>
int getNumberLength(T x)
{
	if(x < 0) { x = -x; }
	if(x == 0) { return 1; }
	return int((log(x * 1.0) / log(10.0)) + 1);
}

LL solveDP(int n)
{
	LL ret = 0;
	int i = 0, j = 0;
	int** dp = 0;

	mallocDoubleArray(n, n, dp);

	dp[0][0] = 0;
	for(i = 1; i < n; i++)
	{
		dp[0][i] = 1;
		dp[i][0] = 1;
	}

	for(i = 1; i < n; i++)
	{
		for(j = 1; j < n; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j -1];
		}
	}

	ret = dp[n - 1][n - 1];

	releaseDoubleArray(n, dp);

	return ret;
}

LL solveGeneral(int n)
{
	LL i = 0;
	LL ret = 0;

	n = n - 1;
	if(n == 0) { return 0; }

	LL start = pow(10.0, n - 1);
	LL end = pow(10.0, n << 1);

	for(i = start; i < end; i++)
	{
		if(getZeroAmount(i) == n)
		{
			ret++;
		}
	}

	return ret;
}

int main()
{
	int n = 0;
	LL ret = 0;

#ifdef DEBUG
	n = 5;
#else
	cout << "Please input the n:";
	cin >> n;
#endif

	ret = solveDP(n);
	cout << ret << endl;

	ret = solveGeneral(n);
	cout << ret << endl;

	return 0;
}
