#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 50;

char b[MAX][MAX];

int row = 0, col = 0, mine = 0;

void fill_board(int endRow, int endCol)
{
	int i = 0, j = 0;
	for(i = 0; i <= endRow; ++i)
	{
		for(j = 0; j <= endCol; ++j)
		{
			b[i][j] = '.';
		}
	}
}

int solve()
{
	int remain = 0;
	int i = 0, j = 0, k = 0;
	int blank = row * col - mine;	

	memset(b, '*', sizeof(b));

	if(blank == 1) { return 0; }

	if(row == 1 || col == 1)
	{
		if(row == 1) { fill_board(0, blank - 1); }
		if(col == 1) { fill_board(blank - 1, 0); }
		return 0;
	}
	if(row == 2 || col == 2)
	{
		if(blank >= 4 && blank % 2 == 0)
		{
			if(row == 2) { fill_board(1, (blank / 2) - 1); }
			else if(col == 2) { fill_board((blank / 2) - 1, 1); }
			return 0;
		}
			
		return -1;
	}

	if(blank % row == 0 && blank / row > 1)
	{
		fill_board(row - 1, blank / row - 1);
		return 0;
	}
	if(blank % col == 0 && blank / col > 1)
	{
		fill_board(blank / col - 1, col - 1);
		return 0;
	}

	if(blank == 2 || blank == 3 || blank == 5 || blank == 7)
	{
		return -1;
	}

	for(i = 1; i * i <= blank; ++i)
	{
		if(i * i == blank)
		{
			fill_board(i - 1, i - 1);
			return 0;
		}
	}

	for(i = row; i > 1; --i)
	{
		for(j = col; j > 1; --j)
		{
			if(i * j == blank)
			{
				fill_board(i - 1, j - 1);
				return 0;
			}
			else if(i * j < blank)
			{
				break;
			}
			else if(i * j > blank && i > 2 && j > 2 && (i - 1) * ( j - 1) < blank)
			{
				remain = blank - (i - 1) * (j - 1);
				if(remain == 1) { continue; }
				fill_board(i - 2, j - 2);
				if(remain <= i - 1)
				{
					for(k = 0; k < remain; ++k)
					{
						b[k][j - 1] = '.';
					}
				}
				else if(remain <= j - 1)
				{
					for(k = 0; k < remain; ++k)
					{
						b[i - 1][k] = '.';
					}
				}
				else
				{
					for(k = 0; k < i - 1 && k < j - 1 && remain >= 2; ++k, remain -= 2)
					{
						b[k][j - 1] = b[i - 1][k] = '.';
					}
					for(; k < i - 1 && remain > 0; ++k, remain -= 1) { b[k][j - 1] = '.'; }
					for(; k < j - 1 && remain > 0; ++k, remain -= 1) { b[i - 1][k] = '.'; }
				}
				return 0;
			}
		}
	}

	return -1;
}

int main()
{
	int t = 0, i = 0;
	int j = 0, k = 0;
	int ret = 0;

	FILE* in = freopen("D:/Lab/Contests/Contests/file/C-large.in", "r", stdin);
	FILE* out = freopen("D:/Lab/Contests/Contests/file/C-large.out", "w", stdout);

	fscanf(in, "%d", &t);

	for(i = 0; i < t; i++)
	{
		fscanf(in, "%d %d %d", &row, &col, &mine);	
		ret = solve();
		
		fprintf(out, "Case #%d:\n", (i + 1));
		if(ret == -1)
		{
			fprintf(out, "%s\n", "Impossible");
		}
		else
		{
			b[0][0] = 'c';
			for(j = 0; j < row; ++j)
			{
				for(k = 0; k < col; ++k)
				{
					fprintf(out, "%c", b[j][k]);
				}
				fprintf(out, "\n");
			}			
		}
	}

	fclose(out);
	fclose(in);
	return 0;
}