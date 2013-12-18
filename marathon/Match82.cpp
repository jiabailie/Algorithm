/*
 * Reference: community.topcoder.com/longcontest/?module=ViewProblemStatement&compid=34370&rd=15825
 * Test tool: www.topcoder.com/contest/problem/ColorLinker/manual.html
 * Debug call: java -jar ColorLinkerVis.jar -exec clab.exe -seed 1
 */
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <fstream>

#define DEBUG
#undef	DEBUG
using namespace std;

const int MAX = 61;

const int MAX_COLOR = 5;

const int MAX_DIS = 10000;

const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};

const int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

// csign[i] means that cell is painted with color i.
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

struct component
{
	int num;
	int color;
	vector<point> points;

	component() : num(0), color(0) {}

	component(int _num, int _color, vector<point>& _points) : 
			num(_num), 
			color(_color), 
			points(vector<point>(_points.begin(), _points.end())) {}

	component(const component& _component) : 
			num(_component.num), 
			color(_component.color), 
			points(vector<point>(_component.points.begin(), _component.points.end())) {}

	component& operator=(const component& _component)
	{
		if(this != &_component)
		{
			this->num = _component.num;
			this->color = _component.color;
			this->points = vector<point>(_component.points.begin(), _component.points.end());

			return *this;
		}

		return *this;
	}

	void add(const point& _point)
	{
		num += 1;
		points.push_back(_point);
	}

	~component(){}
};

class ColorLinker
{
public:
	int cnt;

	// the board size is (gridSize * gridSize).
	int gridSize; 

	// save the penalty which is inputted.
	int penalty; 

	// save the penalty score of this status.
	long cpenalty; 

	// process result
	vector<int> ret; 

	// visited array
	bool visited[MAX][MAX];

	// save the board status, if some cell(i,j) is painted by 1 and 3
	// grid[i][j] = (2 ^ 1) | (2 ^ 3).
	vector<vector<int> > grid; 

	// statis[i].second saves all positions which is painted by statis[i].first.
	map<int, vector<point> > statis; 

	// judge if (x, y) in the range of this grid.
	inline bool judgePosInRange(int, int);

	// judge whether current point's top/left/bottom/right positions have same color points.
	inline bool judge(const point&); 

	// find the nearest point which has same color.
	inline void find(int, int&, int&, const point&); 

	// do breadth first search to find how many discrete connected-component in this image
	// search all points painted by color
	inline vector<component> findcc(int);

	// merge two different connected-components.
	inline void mergecc(component&, component&);

	// find nearest distance between two connected-components.
	inline int calCcDis(point&, point&, component&, component&);

	// do breadth first search to find how many discrete connected-component in this image
	inline component bfs(int, point&);

	// paint the path from point A to point B using color.
	inline void paint(int, point&, point&, component&); 	
	
	// paint the line from point A to point B using color.
	inline void paintline(int, point&, point&, component&); 

	// adjust the board to minimize the penalty.
	inline void adjust(int); 

	vector<int> link(vector <string>, int);

	ColorLinker() : cnt(0), gridSize(0), penalty(0), cpenalty(0)
	{ 
		ret.clear();
		grid.clear();
		statis.clear(); 
	}
};

inline int imin(int a, int b) { return a < b ? a : b; }

inline int imax(int a, int b) { return a > b ? a : b; }

inline int manhattanDis(const point& a, const point& b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

inline void swappoint(point& a, point& b)
{
	point c(a);
	a = b;
	b = c;
}

inline bool ColorLinker::judgePosInRange(int x, int y)
{
	bool ret = false;
	if(x >= 0 && x < gridSize && y >= 0 && y < gridSize)
	{
		ret = true;
	}
	return ret;
}

inline bool ColorLinker::judge(const point& p)
{
	int i = 0;
	int nx = 0, ny = 0;
	bool ret = false;

	for(i = 0; i < 4; i++)
	{
		nx = p.x + dx[i];
		ny = p.y + dy[i];

		if(judgePosInRange(nx, ny) && (grid[p.x][p.y] & grid[nx][ny]))
		{
			ret = true;
			break;
		}
	}
	return ret;
}

inline void ColorLinker::find(int color, int& fpx, int& fpy, const point& p)
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

inline vector<component> ColorLinker::findcc(int color)
{
	int i = 0;
	vector<component> ret;

	memset(visited, 0, sizeof(visited));

	for(i = 0; i < statis[color].size(); i++)
	{
		if(!visited[statis[color][i].x][statis[color][i].y])
		{
			ret.push_back(bfs(color, statis[color][i]));
		}
	}

	return ret;
}

inline void ColorLinker::mergecc(component& c1, component& c2)
{
	for(vector<point>::iterator it = c2.points.begin(); it != c2.points.end(); it++)
	{
		c1.add((*it));
	}
}

inline int ColorLinker::calCcDis(point& p1, point& p2, component& c1, component& c2)
{
	int i = 0, j = 0;
	int tmpDis = 0;
	int minDis = MAX_DIS;

	for(i = 0; i < c1.points.size(); i++)
	{
		for(j = 0; j < c2.points.size(); j++)
		{
			tmpDis = manhattanDis(c1.points[i], c2.points[j]);
			if(tmpDis < minDis)
			{
				minDis = tmpDis;
				p1 = c1.points[i];
				p2 = c2.points[j];
			}
		}
	}

	return minDis;
}

inline component ColorLinker::bfs(int color, point& p)
{
	int i = 0;
	int nx = 0;
	int ny = 0;
	point top;
	component segment;
	queue<point> iqueue;

	segment.color = color;
	segment.points.clear();

	iqueue.push(p);

	while(!iqueue.empty())
	{
		top = iqueue.front();
		iqueue.pop();

		visited[top.x][top.y] = true;
		segment.add(top);

		for(i = 0; i < 4; i++)
		{
			nx = top.x + dx[i];
			ny = top.y + dy[i];

			if(judgePosInRange(nx, ny) && (csign[color] & grid[nx][ny]) && !visited[nx][ny])
			{
				iqueue.push(point(nx, ny));
			}
		}
	}

	return segment;
}

inline void ColorLinker::paint(int color, point& a, point& b, component& cc)
{
	int i = 0;

	if(a.x == b.x || a.y == b.y)
	{
		paintline(color, a, b, cc);
	}
	else
	{
		point c(b.x, a.y);
		grid[b.x][a.y] |= csign[color];
		statis[color].push_back(c);

		cc.add(c);

		cnt += 3;

		ret.push_back(b.x);
		ret.push_back(a.y);
		ret.push_back(color);

		paintline(color, a, c, cc);
		paintline(color, c, b, cc);
	}
}

inline void ColorLinker::paintline(int color, point& a, point& b, component& cc)
{
	int i = 0;
	int s = 0, e = 0;
	point c;

	if(a.x == b.x)
	{
		s = imin(a.y, b.y);
		e = imax(a.y, b.y);

		for(i = s + 1; i < e; i++)
		{
			c = point(a.x, i);
			grid[a.x][i] |= csign[color];
			statis[color].push_back(c);

			cc.add(c);

			cnt += 3;

			ret.push_back(a.x);
			ret.push_back(i);
			ret.push_back(color);
		}
	}
	else if(a.y == b.y)
	{
		s = imin(a.x, b.x);
		e = imax(a.x, b.x);
		for(i = s + 1; i < e; i++)
		{
			c = point(i, a.y);
			grid[i][a.y] |= csign[color];
			statis[color].push_back(c);

			cc.add(c);

			cnt += 3;

			ret.push_back(i);
			ret.push_back(a.y);
			ret.push_back(color);
		}
	}
}

inline void ColorLinker::adjust(int color)
{
	int i = 0, j = 0;

	int len = int(statis[color].size());

	if(len == 1) { return; }

	int minDis = MAX_DIS;
	int tmpDis = 0;

	int lastI = 0;
	int lastJ = 0;

	point startPoint;
	point endPoint;

	point tsPoint;
	point tePoint;

	vector<component> components = findcc(color);

	while(components.size() > 1)
	{
		minDis = MAX_DIS;
		
		for(i = 0; i < components.size() - 1; i++)
		{
			for(j = i + 1; j < components.size(); j++)
			{
				tmpDis = calCcDis(tsPoint, tePoint, components[i], components[j]);
				if(tmpDis < minDis)
				{
					minDis = tmpDis;
					startPoint = tsPoint;
					endPoint = tePoint;
					lastI = i;
					lastJ = j;
				}
			}
		}

		mergecc(components[lastI], components[lastJ]);

		paint(color, startPoint, endPoint, components[lastI]);

		components.erase(components.begin() + lastJ);
	}

	i = 0;
}

vector<int> ColorLinker::link(vector<string> board, int ipenalty)
{
	int i = 0;
	int j = 0;
	int c = 0;
	
	penalty = ipenalty;
	gridSize = board.size();		

	for(i = 0; i < gridSize; i++)
	{
		vector<int> row(gridSize, 0);
		for(j = 0; j < gridSize; j++)
		{
			if(board[i][j] != '-')
			{
				c = board[i][j] - '0';

				cnt += 3;

				ret.push_back(i);
				ret.push_back(j);
				ret.push_back(c);

				statis[c].push_back(point(i, j));
				row[j] |= csign[c];
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
	char grid[MAX][MAX]
#ifdef DEBUG
	=
{
"-------------------------------------------------3---------2",
"--------------2---------------2-----------------------------",
"-----------------------------------0----------------------2-",
"------------------------------------------------2-----------",
"----------------2-------------------3----------------1------",
"-------------2-------------------------------------1--------",
"-----------------------------------------------------2------",
"3------------------------------2----------------------------",
"-3-------------0----2-------------------------2----2--------",
"--------------2---------------------0-----------------------",
"------------------------------------------------------------",
"-------------------1----------------------------------------",
"------------------------------------------------------------",
"---------3--------2-----------------------------------------",
"---------------------1--------------------------------------",
"1------------------3-----------2------------2---------------",
"------------------------------------------------------------",
"---------1--------------------------------------------------",
"------0-----------------------------------------------------",
"3----------------------------------------------------------0",
"--------1-2-------------------------------------------------",
"------------------------------------------------------------",
"--------1-------------3-------------------------------------",
"--------------------------------------------------2----3----",
"----------------------------------------------3-------------",
"------------------------------------------------------------",
"-----------------------------------1------------------------",
"------1-----------------------------------------------------",
"------------------------------------------------------3-----",
"---------------------------------------------2------------3-",
"------------------------------2-----------------------------",
"-----------------1-----------------------------2------------",
"----------------2---0---------------------------------------",
"------------------------------------------------------------",
"-------------------3---------2------------------------------",
"----------3-----------------------------------------2--1--0-",
"----------------1-----------------2-------------------------",
"--------------------------------------------------------2---",
"------------------0------------------------------3----------",
"-------------2----------------------------------------------",
"------------------------------------------------------------",
"------------------------------------------------------------",
"---------------------4------2-------1-----------------------",
"------------------------------------------------------------",
"---------------------------------------1--------------------",
"---------------------------2-------------------3------------",
"----------------------3-------------------------------------",
"-----------2---------------------------------------2--------",
"------------------------------------------------------------",
"------------------4----------------------------4-----1------",
"-------3-3-------0------------------------------------------",
"---------------------------------------1-------3------------",
"--------------0---------------------------------------------",
"---------------------2--------------------------------------",
"------------------------------------------------------------",
"------------------------------------------------------------",
"------------0-----------------------------------------------",
"---------------------------------------------------1--------",
"------------------------3-----------------------------------",
"---------------------22-------------------------------------"
};
#endif
	;

#ifdef	DEBUG
	gridSize = 60;
	penalty = 328;
#else
	memset(grid, 0, sizeof(grid));
	cin >> gridSize;
	cin >> penalty;
	for(i = 0; i < gridSize; i++)
	{
		cin >> grid[i];
	}
#endif

	vector<string> board;
	for(i = 0; i < gridSize; i++)
	{
		string tmp(grid[i]);
		board.push_back(tmp);
	}
	
	vector<int> ret = c.link(board, penalty);

#ifdef	DEBUG
	ofstream fout("result.txt");

	if(!fout.good())
	{
		cout << "the output file is not exist." << endl;
	}

	fout << c.cnt << endl;
	
	for(map<int, vector<point> >::iterator imap = c.statis.begin(); imap != c.statis.end(); imap++)
	{
		for(vector<point>::iterator it = imap->second.begin(); it != imap->second.end(); it++)
		{
			fout << it->x << " "
				 << it->y << " "
				 << imap->first << endl;
		}
	}	

	fout.flush();
	fout.close();
#else
	cout << c.cnt << endl;
	
	for(map<int, vector<point> >::iterator imap = c.statis.begin(); imap != c.statis.end(); imap++)
	{
		for(vector<point>::iterator it = imap->second.begin(); it != imap->second.end(); it++)
		{
			cout << it->x << endl
				 << it->y << endl
				 << imap->first << endl;
		}
	}	
#endif

	return 0;
}
