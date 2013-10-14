/* Find the amount of connected components of a graph. */
#include <cstdio>
#include <iostream>
#include <queue>
#define DEBUG
#undef	DEBUG

using namespace std;

const int LEN = 100;
int N = 0;
int M = 0;
int cnt = 0;
#ifdef	DEBUG
char board[LEN][LEN] = {
	"##.....#.#.##",
	"...#....#...#",
	"..#.#.##...#.",
	"...#......#..",
	".........#...",
	"####....#....",
	"..##...#.....",
	"..#...#...###",
	"#..#.#.....#.",
	"......#..#.#.",
	"###...#....#."};
#else
char board[LEN][LEN];
#endif
int flag[LEN][LEN];

inline int project(int x, int y) { return x * LEN * 10 + y; }
inline int getx(int p) { return p / ( LEN * 10); }
inline int gety(int p) { return p % (LEN * 10); }

void findParts()
{
	int t = 0;
	int i = 0, j = 0;
	int m = 0, n = 0;
	int tx = 0, ty = 0;
	int ix = 0, iy = 0;
	queue<int> iqueue;

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			if(board[i][j] == '#' && flag[i][j] == 0)
			{
				iqueue.push(project(i, j));				
				cnt = cnt + 1;
				while(!iqueue.empty())
				{
					t = iqueue.front();
					iqueue.pop();
					tx = getx(t);
					ty = gety(t);
					flag[tx][ty] = cnt;
					for(m = -1; m <= 1; m++)
					{
						for(n = -1; n <= 1; n++)
						{
							ix = tx + m;
							iy = ty + n;
							if(ix >= 0 && ix < N && iy >= 0 && iy < M && board[ix][iy] == '#' && flag[ix][iy] == 0)
							{
								iqueue.push(project(ix, iy));
							}
						}
					}
				}
			}
		}
	}
#ifdef	DEBUG
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			cout << flag[i][j] << " ";
		}
		cout << endl;
	}
#endif
}

int main()
{
	int i = 0, j = 0;
	int parts = 0;

#ifdef DEBUG

	N = 10;
	M = 13;
	
#else

	cin >> N >> M;

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

#endif
	memset(flag, 0, sizeof(int) * LEN * LEN);

	findParts();
	cout << cnt << endl;

	return 0;
}
