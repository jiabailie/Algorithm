#include <cstdio>
#include <iostream>
#include <string>
#define MAX 100

using namespace std;

int dp[MAX][MAX];

inline int imax(int a, int b) { return a > b ? a : b; }

/* Longest common substring */
int lcs(int& p, string a, string b)
{
  int i = 0, j = 0;
	int max = -1;
	memset(dp, 0, sizeof(dp));
	for(i = 1; i <= a.length(); i++)
	{
		for(j = 1; j <= b.length(); j++)
		{
			/* if a[i] == b[j], dp[i][j] = dp[i - 1][j - 1] + 1 */
			if(a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if(dp[i][j] > max) { max = dp[i][j]; p = i - 1; }
			}
			/* if a[i] == b[j], dp[i][j] = 0 */
			else
			{
				dp[i][j] = 0;
			}
		}
	}
	return max;
}

/* Longest common subsequence */
int lcss(string a, string b)
{
	int i = 0, j = 0;
	int max = 0;
	memset(dp, 0,sizeof(dp));

	for(i = 1; i <= a.length(); i++)
	{
		for(j = 1; j <= b.length(); j++)
		{
			/* if a[i] == b[j], dp[i][j] = dp[i - 1][j - 1] + 1 */
			if(a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			/* if a[i] == b[j], dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) */
			else
			{
				dp[i][j] = imax(dp[i - 1][j], dp[i][j - 1]);
				if(dp[i][j] > max) { max = dp[i][j]; }
			}
		}
	}

	return max;
}

void test_lcs()
{
	string a("abcedfg");
	string b("acedghe");
	int p = 0;
	int l = lcs(p, a, b);
	for(int i = l - 1; i >= 0; i--)
	{
		cout << a[p - i];
	}
	cout << endl;
}

void test_lcss()
{
	string a("abcedfg");
	string b("acedghe");

	int l = lcss(a, b);	
}

int main()
{
	return 0;
}
