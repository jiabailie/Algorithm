/* Google 2013 Online Test Round B
 * Source: code.google.com/codejam/contest/2929486/dashboard
 * Idea: DP + BFS
 */
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int len = 100;
int pre[len][len];	// pre-node position in the shortest path
int dist[len][len];	// the distance from start point
int value[len][len];	// the power till this point it gathered
int board[len][len];
int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, 1, 0, -1 };

inline int project(int x, int y) { return x * 1000 + y; }
inline int getx(int p) { return p / 1000; }
inline int gety(int p) { return p % 1000; }

inline void judgeResult(int N, int M, int enx, int eny, int exx, int exy)
{
	int i = 0, top = 0;
	int x = 0, y = 0;
	int tx = 0, ty = 0;
	int tmp = 0;
	queue<int> iqueue;
	iqueue.push(project(enx, eny));
	pre[enx][eny] = project(enx, eny);
	dist[enx][eny] = 0;
	value[enx][eny] = board[enx][eny];

	while(!iqueue.empty())
	{
		top = iqueue.front();
		x = getx(top);
		y = gety(top);
		iqueue.pop();

		for(i = 0; i < 4; i++)
		{
			tx = x + dirX[i];
			ty = y + dirY[i];
			tmp = project(tx, ty);
			if(tx >= 0 && tx < N && ty >= 0 && ty < M && tmp != pre[x][y] && board[tx][ty] != -1) // position valid
			{
				if(pre[tx][ty] == -1) // if it has not been visited.
				{
					pre[tx][ty] = top;
					dist[tx][ty] = dist[x][y] + 1;
					value[tx][ty] = value[x][y] + board[tx][ty];
					iqueue.push(tmp);
				}
				else if(pre[tx][ty] != -1) // if it has been visited
				{
					// if (x,y) has shorter distance from (enx, eny) as its previous node, or it has more power can be gathered.
					if(dist[x][y] + 1 < dist[tx][ty] || (dist[x][y] + 1 == dist[tx][ty] && value[x][y] + board[tx][ty] > value[tx][ty]))
					{
						pre[tx][ty] = top;
						dist[tx][ty] = dist[x][y] + 1;
						value[tx][ty] = value[x][y] + board[tx][ty];
						iqueue.push(tmp);
					}
				}
			}
		}
	}
}

int main()
{
	int N = 0, M = 0, T = 0;
	int i = 0, j = 0, k = 0;
	int enx = 0, eny = 0, exx = 0, exy = 0;

	FILE* in = freopen("E:\\Projects\\lab\\lab\\file\\D-large-practice.in", "r", stdin);
	FILE* out = freopen("E:\\Projects\\lab\\lab\\file\\D-large-practice.out", "w", stdout);

	fscanf(in, "%d", &T);
	for(k = 0; k < T; k++)
	{
		fscanf(in, "%d %d", &N, &M);
		fscanf(in, "%d %d %d %d", &enx, &eny, &exx, &exy);

		memset(pre, -1, sizeof(int) * len * len);
		memset(dist, INT_MAX, sizeof(int) * len * len);
		memset(board, 0, sizeof(int) * len * len);
		memset(value, INT_MIN, sizeof(int) * len * len);

		for(i = 0; i < N; i++)
		{
			for(j = 0; j < M; j++)
			{
				fscanf(in, "%d", &board[i][j]);
			}
		}

		judgeResult(N, M, enx, eny, exx, exy);

		if(pre[exx][exy] == -1)
		{
			fprintf(out, "Case #%d: %s\n", (k + 1), "Mission Impossible.");
		}
		else
		{
			fprintf(out, "Case #%d: %d\n", (k + 1), value[exx][exy]);
		}
	}

	fclose(in);
	fclose(out);

	return 0;
}
