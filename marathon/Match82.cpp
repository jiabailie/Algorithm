/*
 * Reference: community.topcoder.com/longcontest/?module=ViewProblemStatement&compid=34370&rd=15825
 * Test tool: www.topcoder.com/contest/problem/ColorLinker/manual.html
 * Debug call: java -jar ColorLinkerVis.jar -exec clab.exe -seed 1
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <set>
#include <cmath>

#define DEBUG
#undef	DEBUG

using namespace std;

const int MAX = 61;
const int MAX_COLOR = 5;

const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};

const int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

struct point
{
	int x;
	int y;
	point(int _x, int _y) : x(_x), y(_y) {}
	point(const point& _point) : x(_point.x), y(_point.y){}
	point& operator=(const point& _point)
	{
		this->x = _point.x;
		this->y = _point.y;
		return *this;
	}
	~point(){}
};

inline int manhattanDis(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

inline int manhattanDis(point pa, point pb)
{
	return abs(pa.x - pb.x) + abs(pa.y - pb.y);
}

class ColorLinker
{
public:

#ifdef	DEBUG
	int cnt;
#endif	DEBUG

	int gridSize;

	vector<int> ret;

	vector<vector<char> > grid;

	map<int, vector<point> > statis;

	void adjust(int);

	vector<int> link(vector <string>, int);

	ColorLinker() : 
#ifdef	DEBUG
	cnt(0), 
#endif
	gridSize(0) 
	{ 
		statis.clear(); 
	}
};

void ColorLinker::adjust(int color)
{

}

vector<int> ColorLinker::link(vector<string> board, int penalty)
{
	int i = 0;
	int j = 0;
	
	gridSize = board.size();		

	for(i = 0; i < gridSize; i++)
	{
		vector<char> row;
		for(j = 0; j < gridSize; j++)
		{
			row.push_back(board[i][j]);

			if(board[i][j] != '-')
			{
#ifdef	DEBUG
				cnt += 3;
#endif

				ret.push_back(i);
				ret.push_back(j);
				ret.push_back(int(board[i][j] - '0'));

				statis[(board[i][j] - '0')].push_back(point(i, j));
			}
		}
		grid.push_back(row);
	}

	return ret;
}

int main()
{	
	int i = 0;
	int gridSize = 0;
	int penalty = 0;
	ColorLinker c;
	char grid[MAX][MAX];

	memset(grid, 0, sizeof(grid));
	
	cin >> gridSize;
	cin >> penalty;
	
	for(i = 0; i < gridSize; i++)
	{
		cin >> grid[i];
	}

	vector<string> board;
	for(i = 0; i < gridSize; i++)
	{
		string tmp(grid[i]);
		board.push_back(tmp);
	}
	
	vector<int> ret = c.link(board, penalty);

#ifdef	DEBUG
	cout << c.cnt << endl;
	
	for(map<int, vector<point> >::iterator imap = c.statis.begin(); imap != c.statis.end(); imap++)
	{
		for(vector<point>::iterator it = imap->second.begin(); it != imap->second.end(); it++)
		{
			cout << it->x << endl;
			cout << it->y << endl;
			cout << imap->first << endl;
		}
	}	
#endif
	return 0;
}
