/**
 * There is a matrix, a path is defined a string, matrix[i][j] and its 8 neighbours can composed a path.
 * Now, judge a given string is a path of that matrix.
 * eg.
 * [A B C E]
 * [S F C S]
 * [A D E E]
 * ABCCED is a path of that matrix.
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int maxN = 100;
const int h = 3;
const int w = 4;
char board[maxN][maxN];
bool explore[maxN][maxN];
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
void geBoard()
{
	int i = 0, j = 0;
	memset(board, 0, sizeof(board));
	char sboard[h][w] = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
	for(i = 0; i < h; ++i)
	{
		for(j = 0; j < w; ++j)
		{
			board[i][j] = sboard[i][j];
		}
	}
}
bool dfs(int cur, int posX, int posY, const char *str)
{
	int i = 0, j = 0;
	if(cur == strlen(str))
	{
		for(i = 0; i < h; ++i)
		{
			for(j = 0; j < w; ++j)
			{
				cout << (explore[i][j] ? "*" : " ");
			}
			cout << endl;
		}
		cout << endl;
		return true;
	}
	int tpX = 0, tpY = 0;
	for(i = 0; i < 8; ++i)
	{
		tpX = posX + dx[i];
		tpY = posY + dy[i];
		if(tpX >= 0 && tpX < h && tpY >= 0 && tpY < w && board[tpX][tpY] == str[cur] && !explore[tpX][tpY])
		{
			explore[tpX][tpY] = true;
			if(dfs(cur + 1, tpX, tpY, str))
			{
				return true;
			}
			explore[tpX][tpY] = false;
		}
	}
	return false;
}
bool hasPath(const char *str)
{
	if(!str) { return true; }
	for(int i = 0; i < h; ++i)
	{
		for(int j = 0; j < w; ++j)
		{
			if(board[i][j] == str[0])
			{
				explore[i][j] = true;
				if(dfs(1, i, j, str))
				{
					return true;
				}
				explore[i][j] = false;
			}
		}
	}	
	return false;
}
int main()
{
	geBoard();

	char *str = "ABCCEDAS";

	bool judge = hasPath(str);

	cout << (judge ? "Yes" : "No") << endl;

	return 0;
}