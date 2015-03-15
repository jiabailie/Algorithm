/**
 * RMQ (range minimum query) and LCA (Lowest Common Ancestor)
 * reference: community.topcoder.com/tc?module=Static&d1=tutorials&d2=lowestCommonAncestor
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include "lib\common.h"
#define SIZE(x) static_cast<int>(x.size())

using namespace std;

const int MAXN = 100;

int dp[MAXN][MAXN];
int dp2[MAXN][MAXN];

int findRMQ1(int s, int e, vector<int> &queue)
{
	int n = SIZE(queue);
	if (s < 0 || e >= n || s > e)
	{
		return -1;
	}
	if (s == e)
	{
		return s;
	}
	int minIndex = s;
	for (int i = s + 1; i <= std::min(n - 1, e); ++i)
	{
		if (queue[i] < queue[minIndex])
		{
			minIndex = i;
		}
	}
	return minIndex;
}

// time complexity O(1), space complexity O(N^2)
void findRMQ2(vector<int> &queue)
{
	memset(dp, 0, sizeof(dp));
	int n = SIZE(queue);
	int i = 0, j = 0;

	for (i = 0; i < n; ++i)
	{
		dp[i][i] = i;
	}
	for (i = 0; i < n; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (queue[dp[i][j - 1]] <= queue[j])
			{
				dp[i][j] = dp[i][j - 1];
			}
			else
			{
				dp[i][j] = j;
			}
		}
	}
}

// time complexity O(1), space complexity O(N * logN)
void initRMQ3(vector<int> &queue)
{
	int n = SIZE(queue);
	int i = 0, j = 0;
	// initialize M for the intervals with length 1
	for (i = 0; i < n; ++i)
	{
		dp2[i][0] = i;
	}
	// compute values from smaller to bigger intervals
	for (j = 1; (1 << j) <= n; ++j)
	{
		for (i = 0; i + (1 << j) - 1 < n; ++i)
		{
			if (queue[dp2[i][j - 1]] <= queue[dp2[i + (1 << (j - 1))][j - 1]])
			{
				dp2[i][j] = dp2[i][j - 1];
			}
			else
			{
				dp2[i][j] = dp2[i + (1 << (j - 1))][j - 1];
			}
		}
	}
}
int findRMQ3(int s, int e, vector<int> &queue)
{
	int k = log(double(e - s + 1));
	//int r = e - s + 1;
	//while ((1 << k) <= r) { k += 1; }
	if (queue[dp2[s][k]] <= queue[dp2[e - (1 << k) + 1][k]])
	{
		return dp2[s][k];
	}
	return dp2[e - (1 << k) + 1][k];
}

int main()
{
	vector<int> queue;
	makeArray(queue);

	int i = 0, j = 0;
	int m = 0, n = 0, z = 0;

	findRMQ2(queue);

	initRMQ3(queue);

	for (i = 0; i < SIZE(queue); ++i)
	{
		for (j = i + 1; j < SIZE(queue); ++j)
		{
			m = findRMQ1(i, j, queue);
			n = dp[i][j];
			z = findRMQ3(i, j, queue);
			cout << i << " " << j << ":" << m << "=" << n << "=" << z << " " << ((m == n && m == z) ? "YES" : "NO") << endl;
		}
	}

	return 0;
}