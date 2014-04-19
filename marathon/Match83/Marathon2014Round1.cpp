#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#define DEBUG
using namespace std;

typedef long long ll;

const ll mul = 48271;
const ll mod = 2147483647;
const int dirX[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dirY[8] = {0, 1, 0, -1, 1, -1, -1, 1};

struct idir
{
	enum direction 
	{ 
		up = 0, 
		right = 1, 
		down = 2, 
		left = 3, 
		rt = 4, 
		lt = 5, 
		lb = 6, 
		rb = 7 
	};
};

int N = 0;
int iboard[16][16];

// 0 right-bottom
// 1 right-top
// 2 left-top
// 3 left-bottom
set<int> triples[4];

struct neighbour
{
	int x;
	int y;
	int dist;
	int dir;
	neighbour() {}
	neighbour(int _x, int _y) : x(_x), y(_y), dist(-1), dir(-1) {}
	neighbour(int _x, int _y, int _dist, int _dir) : x(_x), y(_y), dist(_dist), dir(_dir) {}
	neighbour(const neighbour &_m) : x(_m.x), y(_m.y), dist(_m.dist), dir(_m.dir) {}
	neighbour& operator=(const neighbour &_m)
	{
		if(&_m == this) { return *this; }
		this->x = _m.x;
		this->y = _m.y;
		this->dist = _m.dist;
		this->dir = _m.dir;
		return *this;
	}
};

vector<neighbour> cneighbour[7];

inline int imin(int x, int y) { return x < y ? x : y; }
inline int imax(int x, int y) { return x > y ? x : y; }
inline int iabs(int x, int y) { return x > y ? x - y : y - x; }
inline int setPos(int x, int y) { return x * N + y; }
inline void getPos(int p, int &x, int &y) { x = p / N; y = p % N; }

class SquareRemover
{
private:
	int _colors;

	ll _cur_color;

	bool rbTriple(int x, int y)
	{
		int dirs[3] = {idir::up, idir::lt, idir::left};
		return judgeTriple(x, y, dirs);
	}

	bool rtTriple(int x, int y)
	{
		int dirs[3] = {idir::left, idir::lb, idir::down};
		return judgeTriple(x, y, dirs);
	}

	bool ltTriple(int x, int y)
	{
		int dirs[3] = {idir::right, idir::rb, idir::down};
		return judgeTriple(x, y, dirs);
	}

	bool lbTriple(int x, int y)
	{
		int dirs[3] = {idir::up, idir::rt, idir::right};
		return judgeTriple(x, y, dirs);
	}

	void resetStructures(vector<string> board)
	{
		int i = 0, j = 0;
		for(i = 0; i < 7; cneighbour[i].clear(), ++i);
		for(i = 0; i < 4; triples[i].clear(), ++i);
		memset(iboard, 0, sizeof(iboard));
		for(i = 0; i < N; ++i)
		{
			for(j = 0; j < N; ++j)
			{
				iboard[i][j] = board[i][j] - '0';
			}
		}
	}

	int getNextColor()
	{
		int ret = int(_cur_color % _colors);
		_cur_color = (_cur_color * mul) % mod;
		return ret;
	}

	void handleRange(int &sX, int &sY, int &eX, int &eY)
	{
		sX = imax(0, sX);
		sY = imax(0, sY);
		eX = imin(N - 1, eX);
		eY = imin(N - 1, eY);
	}

	bool judgeTriple(int x, int y, int dirs[3])
	{
		int i = 0, j = 0;
		int tx = 0, ty = 0;
		for(i = 0; i < 3; ++i)
		{
			j = dirs[i];
			tx = x + dirX[j];
			ty = y + dirY[j];
			if(!(tx >= 0 && tx < N && ty >= 0 && ty < N))
			{ 
				return false;
			}
		}

		if(!(iboard[x + dirX[dirs[0]]][y + dirY[dirs[0]]] == iboard[x + dirX[dirs[1]]][y + dirY[dirs[1]]] &&
			 iboard[x + dirX[dirs[0]]][y + dirY[dirs[0]]] == iboard[x + dirX[dirs[2]]][y + dirY[dirs[2]]]))
		{
			return false;
		}
		return true;
	}	

	neighbour findNearestNeighbour(int x, int y)
	{
		bool find = false;
		int i = 0, j = 0;
		int tx = 0, ty = 0;
	
		neighbour ret(x, y);
	
		for(i = 1; i <= N && !find; ++i)
		{
			for(j = 0; j < 4 && !find; ++j)
			{
				tx = x + i * dirX[j];
				ty = y + i * dirY[j];
	
				if(tx >= 0 && tx < N && ty >= 0 && ty < N && iboard[x][y] == iboard[tx][ty])
				{
					ret.dist = i;
					ret.dir = j;
					find = true;
				}
			}
		}
		return ret;
	}

	int getNeighbourColor(int kind, int ind)
	{
		int ret = -1;
		int x = 0, y = 0;
		getPos(ind, x, y);
		if(kind == 0) {	ret = iboard[x - 1][y - 1]; }
		else if(kind == 1) { ret = iboard[x + 1][y - 1]; }
		else if(kind == 2) { ret = iboard[x + 1][y + 1]; }
		else if(kind == 3) { ret = iboard[x - 1][y + 1]; }
		return ret;
	}

	void generateNeighbours(int sX, int sY, int eX, int eY)
	{
		handleRange(sX, sY, eX, eY);
		for(int i = sX; i < eX; ++i)
		{
			for(int j = sY; j < eY; ++j)
			{
				cneighbour[iboard[i][j]].push_back(neighbour(findNearestNeighbour(i, j)));
			}
		}
	}

	void getTriples(int sX, int sY, int eX, int eY)
	{
		handleRange(sX, sY, eX, eY);
		for(int i = sX; i < eX; ++i)
		{
			for(int j = sY; j < eY; ++j)
			{
				if(this->rbTriple(i, j)) { triples[0].insert(setPos(i, j)); }
				if(this->rtTriple(i, j)) { triples[1].insert(setPos(i, j)); }
				if(this->ltTriple(i, j)) { triples[2].insert(setPos(i, j)); }
				if(this->lbTriple(i, j)) { triples[3].insert(setPos(i, j)); }
			}
		}
	}

	void globalRemove(int sX, int sY, int eX, int eY)
	{
		handleRange(sX, sY, eX, eY);
		for(int i = sX; i < eX; ++i)
		{
			for(int j = sY; j < eY; ++j)
			{
				if(iboard[i][j] == iboard[i][j + 1] && 
				   iboard[i][j] == iboard[i + 1][j] && 
				   iboard[i][j] == iboard[i + 1][j + 1])
				{
					iboard[i][j] = getNextColor();
					iboard[i][j + 1] = getNextColor();
					iboard[i + 1][j] = getNextColor();
					iboard[i + 1][j + 1] = getNextColor();
					j = j + 1;
				}
			}
		}
	}

	bool findMatchTriples(int &d, int &kind1, int &ind1, int &kind2, int &ind2)
	{
		bool find = false;
		int i = 0, j = 0, k = 0;
		set<int>::iterator m, n;
		for(i = 0; i < 3 && !find; ++i)
		{
			for(j = i + 1; j < 4 && !find; ++j)
			{
				for(m = triples[i].begin(); m != triples[i].end() && !find; ++m)
				{
					for(n = triples[j].begin(); n != triples[j].end() && !find; ++n)
					{
						k = iabs(*m, *n);
						if(k == 1 || k == N)
						{
							if(iboard[(*m) / N][(*m) % N] == getNeighbourColor(j, *n) && 
							   iboard[(*n) / N][(*n) % N] == getNeighbourColor(i, *m))
							{
								find = true;
								kind1 = i;
								kind2 = j;
								ind1 = *m;
								ind2 = *n;
							}
						}
					}
				}
			}
		}
		return find;
	}

	void loopControl(int &x, int &y, int &dir)
	{
		int d = 0; // 0: horizontal, 1: vertical
		int ind1 = 0, ind2 = 0;
		int kind1 = 0, kind2 = 0;

		bool match = findMatchTriples(d, kind1, ind1, kind2, ind2);

		if(match)
		{

		}
	}
public:
	vector<int> playIt(int colors, vector<string> board, int startSeed);
};

vector<int> SquareRemover::playIt(int colors, vector<string> board, int startSeed)
{
	int i = 0, d = 0;	
	int x = 0, y = 0;
	int loop = 10000;
	vector<int> ret;

	N = board.size();

	_colors = colors;

	_cur_color = startSeed;

	resetStructures(board);

	getTriples(0, 0, N, N);

	generateNeighbours(0, 0, N, N);

	globalRemove(0, 0, N, N);

	for(i = 0; i < loop; ++i)
	{
		loopControl(x, y, d);
		ret.push_back(x);
		ret.push_back(y);
		ret.push_back(d);
	}

	return ret;
}

int main()
{
	int colors = 0;
	vector<string> board;
	int startSeed = 0;

#ifdef DEBUG
	colors = 5;
	N = 14;
	startSeed = 857377961;
	board.clear();
	for(int i = 0; i < N; ++i)
	{
		string tmp = "";
		for(int j = 0; j < N; ++j)
		{
			tmp.push_back(char('0' + (rand() % 5)));
		}
		board.push_back(tmp);
	}
#else
	cin >> colors >> N;

	for(int i = 0; i < N; ++i)
	{
		string tmp;
		cin >> tmp;
		board.push_back(tmp);
	}

	cin >> startSeed;
#endif
	SquareRemover sr;
	vector<int> ret = sr.playIt(colors, board, startSeed); 

	for(int i = 0; i < 30000; ++i)
	{
		cout << 0 << endl;
	}

	return 0;
}