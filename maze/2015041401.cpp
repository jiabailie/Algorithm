#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>
#include "ImageOper.h"
#include "GenerateSampleImages.h"

using namespace std;

const int n = 100;
const int FULL_MASK = 15;

unsigned char maze[n][n];
bool visited[n][n];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

enum dir
{
	N = 0,
	S = 1,
	W = 2,
	E = 3
};

inline int getPos(int x, int y) { return x * n + y; }

inline void setPos(int p, int &x, int &y) { x = p / n; y = p % n; }

inline void removeWall(int x, int y)
{
	if(!visited[x][y])
	{
		int d = rand() % 4;
		maze[x][y] &= (FULL_MASK ^ (1 << d));
	}
}

void iniMaze()
{
	memset(maze, 0x0f, sizeof(maze));
}

void generateMaze(int sx, int sy)
{
	iniMaze();
	stack<int> ista;
	int top = 0;
	int i = 0;
	int x = 0, y = 0;
	int cx = 0, cy = 0;
	memset(visited, 0, sizeof(visited));
	ista.push(getPos(sx, sy));
	while(!ista.empty())
	{
		top = ista.top();
		setPos(top, x, y);
		ista.pop();
		if(visited[x][y]) { continue; }
		removeWall(x, y);
		visited[x][y] = true;
		for(i = 0; i <= 3; ++i)
		{
			cx = x + dx[i];
			cy = y + dy[i];
			if(cx >= 0 && cx < n && cy >= 0 && cy < n && !visited[cx][cy])
			{
				ista.push(getPos(cx, cy));
			}
		}
	}
}

BYTE* generateInfra(int w, int h, const BYTE *f)
{
	BYTE *data = (BYTE*)malloc(sizeof(BYTE) * w * h * 3);
	int i = 0, j = 0, k = 0;
	for(i = 0; i < h; ++i)
	{
		for(j = 0; j < w; ++j)
		{
			k = (i * w + j) * 3;
			data[k + 0] = data[k + 1] = data[k + 2] = f[i * w + j];
		}
	}
	return data;
}

void printMaze()
{
	int i = 0, j = 0;
	int w = 2 * n + 1;
	int h = 2 * n + 1;
	while(w % 4 != 0) { w += 1; }
	BYTE *f = (BYTE*)malloc(sizeof(BYTE) * w * h);
	memset(f, c_BLACK, sizeof(BYTE) * w * h);

	for(i = 1; i < 2 * n + 1; i += 2)
	{
		for(j = 1; j < 2 * n + 1; j += 2)
		{
			f[i * w + j] = c_WHITE;
		}
	}
	int px = 0, py = 0;
	int pos = 0;
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			px = 2 * i + 1;
			py = 2 * j + 1;
			pos = px * w + py;
			// (2 * i + 1, 2 * j + 1)
			// remove north wall 
			if(maze[i][j] & (1 << N))
			{
				f[pos - w] = c_WHITE;
			}
			// remove south wall
			if(maze[i][j] & (1 << S))
			{
				f[pos + w] = c_WHITE;
			}
			// remove west wall
			if(maze[i][j] & (1 << W))
			{
				f[pos - 1] = c_WHITE;
			}
			// remove east wall
			if(maze[i][j] & (1 << E))
			{
				f[pos + 1] = c_WHITE;
			}
		}
	}
	BYTE *data = generateInfra(w, h, f);

	Save("E:/Projects/lab/clab/file/1.bmp", w, h, data);

	free(f);
	free(data);
	f = 0;
	data = 0;
}

void printMazeTxt()
{
	int i = 0;
	int j = 0;

	ofstream of("E:/Projects/lab/clab/file/1.txt");
	if(!of) { return; }
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			of << int(maze[i][j]) << "\t";
		}
		of << endl;
	}
	of.close();
}

int main()
{
	int sx = 0;
	int sy = 0;

	generateMaze(sx, sy);
	printMazeTxt();
	printMaze();

	return 0;
}