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

	// record the temp path which has the least penalty (for temp)
	int mpath[MAX][MAX];

	// record how many cost it will be cost from one point to another (for temp)
	long mcost[MAX][MAX];

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

	// judge whether current point's top/left/bottom/right positions have same color points.
	inline bool judge(int, int); 

	// find the nearest point which has same color.
	inline void find(int, int&, int&, const point&); 

	// do breadth first search to find how many discrete connected-component in this image
	// search all points painted by color
	inline vector<component> findcc(int);

	// merge two different connected-components.
	inline void mergecc(component&, component&);

	// calculate the penalty from one point a to another b
	// there is a middle point c, if c(-1, -1) a and b are co-linear.
	inline int calPenalty(point&, point&, point&);

	// calculate the penalty from a to b
	// a and b are co-linear.
	inline int calLinePenalty(point&, point&);

	// find nearest distance between two connected-components.
	inline int calCcDis(point&, point&, point&, component&, component&);

	// do breadth first search to find how many discrete connected-component in this image
	inline component bfs(int, point&);

	// paint the path from point A to point B using path[MAX][MAX]
	inline void paint(int, point&, point&, component&);
	
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

inline int ColorLinker::calPenalty(point& a, point& middle, point& b)
{
	int ret = 0;

	if(a.x != b.x && a.y != b.y)
	{
		point m1(a.x, b.y);
		point m2(b.x, a.y);

		int penalty1 = calLinePenalty(a, m1) + calLinePenalty(m1, b) + cpenalty[a.x][b.y];
		int penalty2 = calLinePenalty(a, m2) + calLinePenalty(m2, b) + cpenalty[b.x][a.y];

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
		ret = calLinePenalty(a, b);
	}
	return ret;
}

inline int ColorLinker::calLinePenalty(point& a, point& b)
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
			ret += cpenalty[a.x][i];
		}
	}
	else if(a.y == b.y)
	{
		s = imin(a.x, b.x);
		e = imax(a.x, b.x);

		for(ret = 0, i = s + 1; i < e; i++)
		{
			ret += cpenalty[i][a.y];
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
			tmpDis = calPenalty(c1.points[i], tmiddle, c2.points[j]);
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

inline void ColorLinker::paint(int color, point& a, point& b, component& cc)
{
	point pc;
	int px = 0, py = 0;
	int current = path[b.x][b.y];
	int start = a.x * gridSize + a.y;

	while(current != start)
	{
		px = current / gridSize;
		py = current % gridSize;

		pc = point(px, py);
		
		grid[px][py] |= csign[color];
		cell[px][py] += 1;
		statis[color].push_back(pc);

		cpenalty[px][py] = cell[px][py] + cell[px][py] * (cell[px][py] - 1) * penalty;

		cc.add(pc);

		cnt += 3;

		ret.push_back(px);
		ret.push_back(py);
		ret.push_back(color);

		current = path[px][py];
	}
}

inline void ColorLinker::adjust()
{
	int minDis;
	bool flg = false;
	int i = 0, j = 0;
	int m = 0, n = 0;
	int nx = 0, ny = 0;

	int lastI = 0;
	int lastJ = 0;

	int mcolor = 0;
	point startPoint;
	point endPoint;

	point tsPoint;
	point tePoint;

	point top;
	queue<point> iqueue;

	while(!flg)
	{
		flg = true;
		minDis = MAX_DIS;

		memset(path, 0, sizeof(path));

		for(map<int, vector<component> >::iterator it = composet.begin(); it != composet.end(); it++)
		{
			if(it->second.size() > 1)
			{
				flg = false;

				for(i = 0; i < int(it->second.size()) - 1; i++)
				{
					for(m = 0; m < it->second[i].points.size(); m++)
					{
						n = 0;
						for(j = 0; j < 4; j++)
						{
							nx = it->second[i].points[m].x + dx[n];
							ny = it->second[i].points[m].y + dy[n];

							if(judgePosInRange(nx, ny) && (grid[nx][ny] & csign[it->first]) == 0)
							{
								n++;
							}
						}

						if(n == 0) { continue; }

						memset(mpath, 0, sizeof(mpath));
						memset(mcost, 0x7f, sizeof(mcost));	
					
						mcost[it->second[i].points[m].x][it->second[i].points[m].y] = 0;
						iqueue.push(it->second[i].points[m]);
					
						while(!iqueue.empty())
						{
							top = iqueue.front();
							iqueue.pop();
					
							for(n = 0; n < 4; n++)
							{
								nx = top.x + dx[n];
								ny = top.y + dy[n];
					
								if(judgePosInRange(nx, ny) && mcost[top.x][top.y] + cpenalty[nx][ny] < mcost[nx][ny])
								{
									mcost[nx][ny] = mcost[top.x][top.y] + cpenalty[nx][ny];
									mpath[nx][ny] = top.x * gridSize + top.y;

									iqueue.push(point(nx, ny));
								}
							}
						}

						for(j = i + 1; j < int(it->second.size()); j++)
						{
							for(n = 0; n < it->second[j].points.size(); n++)
							{
								if(mcost[it->second[j].points[n].x][it->second[j].points[n].y] - cpenalty[it->second[j].points[n].x][it->second[j].points[n].y] < minDis)
								{
									minDis = mcost[it->second[j].points[n].x][it->second[j].points[n].y] - cpenalty[it->second[j].points[n].x][it->second[j].points[n].y];
									mcolor = it->first;
									startPoint = it->second[i].points[m];
									endPoint = it->second[j].points[n];

									lastI = i;
									lastJ = j;

									memcpy(path, mpath, sizeof(path));
								}
							}
						}
					}
				}
			}
		}

		if(!flg)
		{
			mergecc(composet[mcolor][lastI], composet[mcolor][lastJ]);
			paint(mcolor, startPoint, endPoint, composet[mcolor][lastI]);
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
