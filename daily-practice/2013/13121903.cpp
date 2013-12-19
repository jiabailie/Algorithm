#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

const int n = 10;

struct point
{
	int x;
	int y;

	point() : x(0), y(0) {}

	point(int _x, int _y) : x(_x), y(_y) {}

	point(const point& _point) : x(_point.x), y(_point.y) {}

	point& operator=(const point& _point)
	{
		if(this != &_point)
		{
			this->x = _point.x;
			this->y = _point.y;

			return *this;
		}

		return *this;
	}

	~point(){}
};

int main()
{
	int i = 0, j = 0;
	int map[n][n];
	int val[n][n];
	int dir[n][n];
	bool pat[n][n];
	
	int sX = 0, sY = 0;
	int eX = 9, eY = 9;
	int nx = 0, ny = 0;

	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};

	point top;

	queue<point> iqueue;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			map[i][j] = rand() % n;
		}
	}

	memset(val, 0x7f, sizeof(val));
	memset(dir, 0, sizeof(dir));
	memset(pat, 0, sizeof(pat));

	val[sX][sY] = 0;
	pat[sX][sY] = true;

	iqueue.push(point(sX, sY));

	while(!iqueue.empty())
	{
		top = iqueue.front();
		iqueue.pop();

		for(i = 0; i < 4; i++)
		{
			nx = top.x + dx[i];
			ny = top.y + dy[i];

			if(nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if(val[top.x][top.y] + map[nx][ny] < val[nx][ny])
				{
					val[nx][ny] = val[top.x][top.y] + map[nx][ny];
					dir[nx][ny] = top.x * 100 + top.y;
					iqueue.push(point(nx, ny));
				}
			}
		}
	}

	nx = eX;
	ny = eY;	

	while(!(nx == sX && ny == sY))
	{		
		i = dir[nx][ny];
		pat[nx][ny] = true;
		nx = i / 100;
		ny = i % 100;
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cout << val[i][j] << " ";
		}
		cout << endl;
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cout << (pat[i][j] ? "1" : "0");
		}
		cout << endl;
	}

	return 0;
}
