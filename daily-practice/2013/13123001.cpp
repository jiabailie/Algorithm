#include <cstdio>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;

int board[100001][11];

inline int imax(int a, int b) { return a > b ? a : b; }

inline int imax(int a, int b, int c) { return imax(imax(a, b), c); }

int main()
{	
	int n = 0;	
	int i = 0, j = 0;
	int x = 0, t = 0, mt = 0;

	while(scanf("%d", &n), n)
	{
		memset(board, 0, sizeof(board));

		for(i = 0; i < n; i++)
		{
			scanf("%d %d", &x, &t);
			board[t][x] += 1;
			if(mt < t)
			{
				mt = t;
			}
		}

		for(i = mt - 1; i >= 0; i--)
		{
			board[i][0] += imax(board[i + 1][0], board[i + 1][1]);

			for(j = 1; j < 10; j++)
			{
				board[i][j] += imax(board[i + 1][j - 1], board[i + 1][j], board[i + 1][j + 1]);
			}

			board[i][10] += imax(board[i + 1][9], board[i + 1][10]);
		}

		printf("%d\n", board[0][5]);
	}

	return 0;
}
