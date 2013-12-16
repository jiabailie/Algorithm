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
#include <climits>

#define DEBUG
//#undef	DEBUG
using namespace std;

const int MAX = 61;

const int MAX_COLOR = 5;

const int MAX_DIS = 10000;

const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};

const int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

const int csign[6] = {1, 2, 4, 8, 16, 32};

struct point
{
	int x;
	int y;
	point() : x(0), y(0) {}
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

inline int manhattanDis(const point& a, const point& b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

inline int imin(int a, int b) { return a < b ? a : b; }
inline int imax(int a, int b) { return a > b ? a : b; }

class ColorLinker
{
public:
	/* Class parameters */
#ifdef	DEBUG
	int cnt;
#endif	DEBUG

	int gridSize; // the board size is (gridSize * gridSize).

	int penalty; // save the penalty which is inputted.

	long cpenalty; // save the penalty score of this status.

	vector<int> ret; // process result

	vector<vector<int> > grid; // save the board status, if some cell(i,j) is painted by 1 and 3,  grid[i][j] = (2 ^ 1) | (2 ^ 3).

	map<int, vector<point> > statis; // statis[i].second saves all positions which is painted by statis[i].first.

	/* Class functions */
	void adjust(int); // adjust the board to minimize the penalty.

	void find(int, int&, int&, const point&); // find the nearest point which has same color.

	bool judge(const point&); // judge whether current point's top/left/bottom/right positions have same color points.

	void paint(int, point&, point&); // paint the path from point A to point B using color.

	vector<int> link(vector <string>, int);

	ColorLinker() : 
#ifdef	DEBUG
	cnt(0), 
#endif
	gridSize(0), penalty(0), cpenalty(0)
	{ 
		ret.clear();
		grid.clear();
		statis.clear(); 
	}
};

void ColorLinker::adjust(int color)
{
	int i = 0, j = 0;

	vector<point> cpoint(statis[color].begin(), statis[color].end());
	int len = int(cpoint.size());

	if(len == 1)
	{
		return;
	}

	int minDis = MAX_DIS;
	int tmpDis = 0;
	point startPoint;
	point endPoint;

	while(true)
	{
		minDis = MAX_DIS;
		for(i = 0; i < len - 1; i++)
		{
			for(j = i + 1; j < len; j++)
			{
				tmpDis = manhattanDis(cpoint[i], cpoint[j]);
				if(tmpDis > 1 && tmpDis < minDis)
				{
					minDis = tmpDis;
					startPoint = cpoint[i];
					endPoint = cpoint[j];
				}
			}
		}

		if(minDis == MAX_DIS)
		{
			break;
		}

		paint(color, startPoint, endPoint);
	}
}

void ColorLinker::find(int color, int& fpx, int& fpy, const point& p)
{
	int i = 0;
	int tmpDis = 0;
	int minDis = MAX_DIS;

	for(i = 0; i < int(statis[color].size()); i++)
	{
		if(p.x != statis[color][i].x || p.y != statis[color][i].y)
		{
			tmpDis = manhattanDis(p, statis[color][i]);
			if(tmpDis < minDis)
			{
				minDis = tmpDis;
				fpx = statis[color][i].x;
				fpy = statis[color][i].y;
			}
		}
	}
}

bool ColorLinker::judge(const point& p)
{
	int i = 0;
	int nx = 0, ny = 0;
	bool ret = false;

	for(i = 0; i < 4; i++)
	{
		nx = p.x + dx[i];
		ny = p.y + dy[i];

		if(nx >= 0 && nx < gridSize && ny >= 0 && ny < gridSize && (grid[p.x][p.y] & grid[nx][ny]))
		{
			ret = true;
			break;
		}
	}
	return ret;
}

void ColorLinker::paint(int color, point& a, point& b)
{
	int i = 0;
	int sx = imin(a.x, b.x), ex = imax(a.y, b.y);
	int sy = imin(a.y, b.y), ey = imax(a.y, b.y);

	for(i = sx; i <= ex; i++)
	{
		grid[i][sy] |= csign[color];
		statis[color].push_back(point(i, sy));
#ifdef	DEBUG
				cnt += 3;
#endif
		ret.push_back(i);
		ret.push_back(sy);
		ret.push_back(color);
	}

	for(i = sy + 1; i <= ey; i++)
	{
		grid[ex][i] |= csign[color];
		statis[color].push_back(point(ex, i));
#ifdef	DEBUG
				cnt += 3;
#endif
		ret.push_back(ex);
		ret.push_back(i);
		ret.push_back(color);
	}
}

vector<int> ColorLinker::link(vector<string> board, int ipenalty)
{
	int i = 0;
	int j = 0;
	
	penalty = ipenalty;
	gridSize = board.size();		

	for(i = 0; i < gridSize; i++)
	{
		vector<int> row(gridSize, 0);
		for(j = 0; j < gridSize; j++)
		{
			if(board[i][j] != '-')
			{
#ifdef	DEBUG
				cnt += 3;
#endif

				ret.push_back(i);
				ret.push_back(j);
				ret.push_back(int(board[i][j] - '0'));

				statis[(board[i][j] - '0')].push_back(point(i, j));
				row[j] |= csign[int(board[i][j] - '0')];
			}
		}
		grid.push_back(row);
	}

	for(map<int, vector<point> >::iterator it = statis.begin(); it != statis.end(); it++)
	{
		adjust(it->first);
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
