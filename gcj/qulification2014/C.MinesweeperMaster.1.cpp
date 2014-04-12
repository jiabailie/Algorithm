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
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int solve()
{
	int find = -1, top = 0;
	int tx = 0, ty = 0;
	int ax = 0, ay = 0;
	int i = 0, j = 0;
	int k = 0, n = 0;
	int bsize = row * col;
	queue<int> iqueue;

	for(i = 0; i < row && find == -1; ++i)
	{
		for(j = 0; j < col && find == -1; ++j)
		{
			k = 1;
			memset(b, false, sizeof(b));
			b[i][j] = true;
			
			iqueue.push(i * 100 + j);
			while(!iqueue.empty())
			{
				if(k + mine == bsize)
				{
					find = i * 100 + j;
					break;
				}
				top = iqueue.front();
				iqueue.pop();
				tx = top / 100;
				ty = top % 100;

				for(n = 0; n < 8; ++n)
				{
					ax = tx + dx[n];
					ay = ty + dy[n];
					if(ax >= 0 && ax < row && ay >= 0 && ay < col && !b[ax][ay])
					{
						k += 1;
						b[ax][ay] = true;
						iqueue.push(ax * 100 + ay);
					}
				}
			}
		}
	}

	return find;
}

int main()
{
	int t = 0, i = 0, j = 0, k = 0;
	int ret = 0, rx = 0, ry = 0;
	char buffer[2048];

	FILE* in = freopen("D:/Lab/Contests/Contests/file/C-small-attempt1.in", "r", stdin);
	FILE* out = freopen("D:/Lab/Contests/Contests/file/C-small-attempt1.out", "w", stdout);

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
			rx = ret / 100;
			ry = ret % 100;
			for(j = 0; j < row; ++j)
			{
				for(k = 0; k < col; ++k)
				{
					if(j == rx && k == ry)
					{
						fprintf(out, "c");
					}
					else
					{
						if(b[j][k])
						{
							fprintf(out, ".");
						}
						else
						{
							fprintf(out, "*");
						}
					}
				}
				fprintf(out, "\n");
			}			
		}
	}

	fclose(out);
	fclose(in);
	return 0;
}