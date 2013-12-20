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
#undef  DEBUG
using namespace std;

const int MAX = 61;

const int MAX_COLOR = 5;

const int MAX_DIS = 10000;

const int dx[4] = {1, -1, 0, 0};

const int dy[4] = {0, 0, 1, -1};

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

	// process result
	vector<int> ret; 

	// visited array
	bool visited[MAX][MAX];

	// record the penalty of through this cell
	int cpenalty[MAX][MAX];

	// record the path which has the least penalty
	int path[MAX][MAX];

	// record how many cost it will be cost from one point to another
	long cost[MAX][MAX];

	// save the board status, if some cell(i,j) is painted by 1 and 3
	// grid[i][j] = (2 ^ 1) | (2 ^ 3).
	vector<vector<int> > grid; 

	// how many color this cell has.
	vector<vector<int> > cell;

	// statis[i].second saves all positions which is painted by statis[i].first.
	map<int, vector<point> > statis; 

	// all connected components of this seed
	// separate by color
	map<int, vector<component> > composet;

	// judge if (x, y) in the range of this grid.
	inline bool judgePosInRange(int, int);

	// calculate the penalty if there are x kinds of colors.
	inline int calpointpenalty(int);

	// judge whether current point's top/left/bottom/right positions have same color points.
	inline bool judge(int, int); 

	// find the nearest point which has same color.
	inline void find(int, int&, int&, const point&); 

	// do breadth first search to find how many discrete connected-component in this image
	// search all points painted by color
	inline vector<component> findcc(int);

	// merge two different connected-components.
	inline void mergecc(component&, component&);

	// calculate the penalty under this situation.
	inline int calPenalty();

	// calculate the penalty from one point a to another b
	// there is a middle point c, if c(-1, -1) a and b are co-linear.
	inline int calPenalty(int, point&, point&, point&);

	// calculate the penalty from a to b
	// a and b are co-linear.
	inline int calLinePenalty(int, point&, point&);

	// find nearest distance between two connected-components.
	inline int calCcDis(point&, point&, point&, component&, component&);

	// do breadth first search to find how many discrete connected-component in this image
	inline component bfs(int, point&);

	// paint the path from point A to point B using color.
	inline void paint(int, point&, point&, point&, component&);	 
	
	// paint the line from point A to point B using color.
	inline void paintline(int, point&, point&, component&); 

	// adjust the board to minimize the penalty.
	inline void adjust(); 

	vector<int> link(vector <string>, int);

	ColorLinker() : cnt(0), gridSize(0), penalty(0)
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

inline int ColorLinker::calpointpenalty(int k)
{
	return k + k * (k - 1) * penalty;
}

inline bool ColorLinker::judge(int x, int y)
{
	int i = 0;
	int nx = 0, ny = 0;
	bool ret = false;

	for(i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];

		if(judgePosInRange(nx, ny) && (grid[x][y] & grid[nx][ny]))
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

	for(i = 0; i < int(statis[color].size()); i++)
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

inline int ColorLinker::calPenalty()
{
	int ret = 0;
	int i = 0, j = 0;

	for(i = 0; i < gridSize; i++)
	{
		for(j = 0; j < gridSize; j++)
		{
			ret += cpenalty[i][j];
		}
	}

	return ret;
}

inline int ColorLinker::calPenalty(int c, point& a, point& middle, point& b)
{
	int ret = 0;

	if(a.x != b.x && a.y != b.y)
	{
		point m1(a.x, b.y);
		point m2(b.x, a.y);

		int penalty1 = calLinePenalty(c, a, m1) + 
			calLinePenalty(c, m1, b) + 
			((grid[a.x][b.y] & csign[c]) ? cpenalty[a.x][b.y] : calpointpenalty(cell[a.x][b.y] + 1));

		int penalty2 = calLinePenalty(c, a, m2) + 
			calLinePenalty(c, m2, b) + 
			((grid[b.x][a.y] & csign[c]) ? cpenalty[b.x][a.y] : calpointpenalty(cell[b.x][a.y] + 1));

		middle = m1;
		ret = penalty1;
		if(penalty1 > penalty2)
		{
			middle = m2;
			ret = penalty2;
		}
	}
	else
	{
		middle = point(-1, -1);
		ret = calLinePenalty(c, a, b);
	}
	return ret;
}

inline int ColorLinker::calLinePenalty(int c, point& a, point& b)
{
	int i = 0;
	int s = 0, e = 0;
	int ret = 0;

	if(a.x == b.x)
	{
		s = imin(a.y, b.y);
		e = imax(a.y, b.y);

		for(ret = 0, i = s + 1; i < e; i++)
		{
			ret += ((grid[a.x][i] & csign[c]) ? cpenalty[a.x][i] : calpointpenalty(cell[a.x][i] + 1));
		}
	}
	else if(a.y == b.y)
	{
		s = imin(a.x, b.x);
		e = imax(a.x, b.x);

		for(ret = 0, i = s + 1; i < e; i++)
		{
			ret += ((grid[i][a.y] & csign[c]) ? cpenalty[i][a.y] : calpointpenalty(cell[i][a.y] + 1));
		}
	}
	return ret;
}

inline int ColorLinker::calCcDis(point& p1, point& middle, point& p2, component& c1, component& c2)
{
	int i = 0, j = 0;
	int tmpDis = 0;
	int minDis = INT_MAX;
	point tmiddle(-1, -1);

	for(i = 0; i < int(c1.points.size()); i++)
	{
		for(j = 0; j < int(c2.points.size()); j++)
		{
			tmpDis = calPenalty(c1.color, c1.points[i], tmiddle, c2.points[j]);
			if(tmpDis < minDis)
			{
				minDis = tmpDis;
				p1 = c1.points[i];
				p2 = c2.points[j];
				middle = tmiddle;
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

inline void ColorLinker::paint(int color, point& a, point& middle, point& b, component& cc)
{
	int i = 0;

	if(middle.x == -1 && middle.y == -1)
	{
		paintline(color, a, b, cc);
	}
	else
	{
		grid[middle.x][middle.y] |= csign[color];
		cell[middle.x][middle.y] += 1;
		statis[color].push_back(middle);

		cpenalty[middle.x][middle.y] = 
			cell[middle.x][middle.y] + 
			cell[middle.x][middle.y] * (cell[middle.x][middle.y] - 1) * penalty;

		cc.add(middle);

		cnt += 3;

		ret.push_back(middle.x);
		ret.push_back(middle.y);
		ret.push_back(color);

		paintline(color, a, middle, cc);
		paintline(color, middle, b, cc);
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
			cell[a.x][i] += 1;
			statis[color].push_back(c);

			cpenalty[a.x][i] = 
				cell[a.x][i] + 
				cell[a.x][i] * (cell[a.x][i] - 1) * penalty;

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
			cell[i][a.y] += 1;
			statis[color].push_back(c);

			cpenalty[i][a.y] = 
				cell[i][a.y] + 
				cell[i][a.y] * (cell[i][a.y] - 1) * penalty;

			cc.add(c);

			cnt += 3;

			ret.push_back(i);
			ret.push_back(a.y);
			ret.push_back(color);
		}
	}
}

inline void ColorLinker::adjust()
{
	bool flg = false;
	int i = 0, j = 0;

	int colorkind = statis.size();
	int composum = 0;

	int minDis = MAX_DIS;
	int tmpDis = 0;

	int lastI = 0;
	int lastJ = 0;

	int mcolor = 0;
	point startPoint;
	point endPoint;
	point middle(-1 ,-1);

	point tsPoint;
	point tePoint;
	point tmiddle(-1 ,-1);

	for(map<int, vector<point> >::iterator it = statis.begin(); it != statis.end(); it++)
	{
		composum += it->second.size();
	}

	while(!flg)
	{
		flg = true;
		minDis = MAX_DIS;
		for(map<int, vector<component> >::iterator it = composet.begin(); it != composet.end(); it++)
		{
			if(it->second.size() > 1)
			{
				flg = false;
				for(i = 0; i < int(it->second.size()) - 1; i++)
				{
					for(j = i + 1; j < int(it->second.size()); j++)
					{
						tmpDis = calCcDis(tsPoint, tmiddle, tePoint, it->second[i], it->second[j]);
						if(tmpDis < minDis || (tmpDis == minDis && manhattanDis(tsPoint, tePoint) < manhattanDis(startPoint, endPoint)))
						{
							mcolor = it->first;
							minDis = tmpDis;
							startPoint = tsPoint;
							endPoint = tePoint;
							middle = tmiddle;
							lastI = i;
							lastJ = j;
						}
					}
				}
			}
		}

		if(!flg)
		{
			mergecc(composet[mcolor][lastI], composet[mcolor][lastJ]);
			paint(mcolor, startPoint, middle, endPoint, composet[mcolor][lastI]);
			composet[mcolor].erase(composet[mcolor].begin() + lastJ);
		}
	}
}

vector<int> ColorLinker::link(vector<string> board, int ipenalty)
{
	int i = 0;
	int j = 0;
	int c = 0;
	
	penalty = ipenalty;
	gridSize = board.size();

	memset(cpenalty, 0, sizeof(cpenalty));

	for(i = 0; i < gridSize; i++)
	{
		vector<int> row(gridSize, 0);
		vector<int> val(gridSize, 0);
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
				val[j] = 1;

				cpenalty[i][j] = 1;
			}
		}
		grid.push_back(row);
		cell.push_back(val);
	}

	for(map<int, vector<point> >::iterator it = statis.begin(); it != statis.end(); it++)
	{		
		composet[it->first] = findcc(it->first);
	}

	adjust();

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
"--------10-------1-----------------",
"1----------------------------------",
"----------------------------1------",
"----------------11-----------------",
"-1-------1-------------------------",
"------------------------------11---",
"----------11----------1------------",
"---------------------------1-------",
"-----------------------------------",
"-----------------------------------",
"---1-------------------------------",
"----------1------------------------",
"----------------------1-----------1",
"1----------------------------------",
"-------------1---------------------",
"-----------1-----11-1--------------",
"-------------------------1---------",
"--1------------------1-------------",
"------1----------------------------",
"-----------------------------------",
"-----------------11-1-----1--------",
"-----------------0----------1-1----",
"--------------------1--------------",
"-------------------1----------1----",
"-----------------1-----------1-----",
"----------------------------1------",
"---------1-------------------------",
"-----1-----------------------------",
"-----------------------------1-----",
"---00----------1--1----------------",
"----------------------1------------",
"--------------------------------1--",
"----------------------------------1",
"---------------------1-------------",
"-----------------1---1-------------"
};
#endif
	;

#ifdef	DEBUG
	gridSize = 35;
	penalty = 57;
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
			fout << it->x << " ";
			fout << it->y << " ";
			fout << imap->first << endl;
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
			cout << it->x << endl;
			cout << it->y << endl;
			cout << imap->first << endl;
		}
	}	
#endif

	return 0;
}
