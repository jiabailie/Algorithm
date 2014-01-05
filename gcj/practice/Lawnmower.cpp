#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include <vector>
#include<climits>

using namespace std;

int board[101][101];

inline int MIN(int a, int b) { return a < b ? a : b; }

int main()
{
	int t = 0, f = 1;
	int n = 0, m = 0;
	int i = 0, j = 0, k = 0;

	FILE* in = freopen("E:\\Practice\\GCJ\\file\\B-small-attempt3.in", "r", stdin);
	FILE* out = freopen("E:\\Practice\\GCJ\\file\\B-small-attempt3.out", "w", stdout);

	fscanf(in, "%d", &t);
	for(k = 0; k < t; k++)
	{
		f = 1;
		fscanf(in, "%d %d", &n, &m);
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < m; j++)
			{
				fscanf(in, "%d", &board[i][j]);
			}
		}
		for(i = 0; i < n && f; i++)
		{
			for(j = 0; j < m && f; j++)
			{
				if((board[i][j] == board[0][j] && board[i][j] == board[n - 1][j] && board[0][j] == MIN(board[0][j], board[i][0])) || 
				   (board[i][j] == board[i][0] && board[i][j] == board[i][m - 1] && board[i][0] == MIN(board[0][j], board[i][0])))
				{
					continue;
				}
				else { f = 0; }
			}
		}
		fprintf(out, "Case #%d: %s\n", (k + 1), (f ? "YES" : "NO"));
	}

	fclose(in);
	fclose(out);

	return 0;
}