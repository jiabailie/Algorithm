#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define PRINT_PATH
#undef  PRINT_PATH

using namespace std;

const int LEN = 100;

char a[LEN];
char b[LEN];

int dp[LEN];
int path[LEN][LEN];

template<typename T>
T imax(T a, T b)
{
	return a > b ? a : b;
}

int main()
{
	int i = 0, j = 0;
	int n = 0, m = 0;
	int t = 0, e = 0;
	int x = 0, y = 0;
	vector<char> common;

	cin >> n >> m;

	cin >> a;
	cin >> b;

	memset(dp, 0, sizeof(dp));
	memset(path, 0, sizeof(path));

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(a[i] == b[j])
			{
				dp[j + 1] = dp[j] + 1;
				path[i + 1][j + 1] = i * LEN + j;
			}
			else
			{
				if(dp[j] > dp[j + 1])
				{
					dp[j + 1] = dp[j];
				}
			}
		}
	}

	cout << dp[m] << endl;

#ifdef	PRINT_PATH
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= m; j++)
		{
			cout << path[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
#endif

	t = dp[m];
	x = n;
	y = m;

	while(t > 0)
	{
		while(path[x][y] == 0)
		{
			y--;
		}
		common.push_back(a[x - 1]);		
		e = path[x][y];
		x = e / LEN;
		y = e % LEN;
		t--;
	}

	for(vector<char>::reverse_iterator it = common.rbegin(); it != common.rend(); it++)
	{
		cout << (*it);
	}

	cout << endl;

	return 0;
}