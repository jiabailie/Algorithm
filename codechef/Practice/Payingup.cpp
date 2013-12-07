/* References : www.codechef.com/problems/MARCHA1/ */
#include <stdio.h>
#include <string.h>

int dp[20010];

inline int imax(int a, int b) { return a > b ? a : b; }

int main()
{
	int t = 0, k = 0;
	int i = 0, j = 0;
	int n = 0, m = 0;
	int w[21];

	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%d", &n);
		scanf("%d", &m);

		for(j = 0; j < n; j++)
		{
			scanf("%d", &w[j]);
		}

		memset(dp, 0, sizeof(dp));

		for(k = 0; k < n; k++)
		{
			for(j = m; j >= w[k]; j--)
			{
				dp[j] = imax(dp[j], dp[j - w[k]] + w[k]);
			}
		}
		if(dp[m] == m)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
