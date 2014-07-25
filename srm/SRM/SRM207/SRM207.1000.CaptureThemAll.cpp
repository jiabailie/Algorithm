#include <string>
#include <cstring>
#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

const int n = 8;

int dirX[n] = {-2, -2, 2, 2, -1, 1, -1, 1};
int dirY[n] = {-1, 1, -1, 1, -2, -2, 2, 2};

int costRook[n][n];
int costQueen[n][n];

inline int set(int x, int y) { return x * n + y; }
inline void get(int &x, int &y, int d) { x = d / n; y = d % n; }

void bfs(int posX, int posY, int (&cost)[n][n])
{
	int front = 0;
	int i = 0, j = 0;
	int px = 0, py = 0;
	int tx = 0, ty = 0;	

	queue<int> ique;
	ique.push(set(posX, posY));

	memset(cost, 0x7f, sizeof(cost));
	cost[posX][posY] = 0;

	while(!ique.empty())
	{
		front = ique.front();
		ique.pop();
		get(px, py, front);
		for(i = 0; i < n; ++i)
		{
			tx = px + dirX[i];
			ty = py + dirY[i];
			if(tx >= 0 && tx < n && ty >= 0 && ty < n && cost[px][py] + 1 < cost[tx][ty])
			{
				cost[tx][ty] = cost[px][py] + 1;
				ique.push(set(tx, ty));
			}
		}
	}
}

class CaptureThemAll
{
public:
	int fastKnight(string knight, string rook, string queen)
	{
		int kx = knight[0] - 'a';
		int ky = knight[1] - '1';
		int rx = rook[0] - 'a';
		int ry = rook[1] - '1';
		int qx = queen[0] - 'a';
		int qy = queen[1] - '1';

		bfs(rx, ry, costRook);
		bfs(qx, qy, costQueen);

		int res1 = costRook[qx][qy] + costQueen[kx][ky];
		int res2 = costQueen[rx][ry] + costRook[kx][ky];

		return std::min(res1, res2);
	}
};

int main()
{
	CaptureThemAll cta;

	int t[5];
	int c[5] = {2, 3, 6, 3, 6};

	t[0] = cta.fastKnight("a1", "b3", "c5");
	t[1] = cta.fastKnight("b1", "c3", "a3");
	t[2] = cta.fastKnight("a1", "a2", "b2");
	t[3] = cta.fastKnight("a5", "b7", "e4");
	t[4] = cta.fastKnight("h8", "e2", "d2");
	
	for(int i = 0; i < 5; ++i)
	{
		if(t[i] == c[i]) { cout << i << " is passed." << endl; }
		else { cout << i << " is failed." << endl; }
	}

	return 0;
}