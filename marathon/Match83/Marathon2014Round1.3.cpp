#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

typedef long long ll;

const ll mul = 48271;
const ll mod = 2147483647;
const int dirX[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dirY[8] = {0, 1, 0, -1, 1, -1, -1, 1};

int N = 0;
int iboard[16][16];

inline int imin(int x, int y) { return x < y ? x : y; }
inline int imax(int x, int y) { return x > y ? x : y; }
inline int iabs(int x, int y) { return x > y ? x - y : y - x; }
inline int setPos(int x, int y) { return x * N + y; }
inline void getPos(int p, int &x, int &y) { x = p / N; y = p % N; }

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

class SquareRemover
{
private:	
	int backK;
	int backX;
	int backY;
	int backC;
	int backDir;
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
		backK = 0;
		backC = 0;
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

	void findNearestNeighbour(int color, int x, int y, vector<int> d)
	{
		bool find = false;
		int i = 0, j = 0;
		int tx = 0, ty = 0;
		
		for(j = 0; j < int(d.size()) && !find; ++j)
		{
			for(i = 1; i <= N && !find; ++i)
			{
				tx = x + i * dirX[d[j]];
				ty = y + i * dirY[d[j]];
	
				if(tx >= 0 && tx < N && ty >= 0 && ty < N && iboard[tx][ty] == color)
				{
					find = true;
					backX = tx;
					backY = ty;
					switch(d[j])
					{
					case idir::up:
						backDir = idir::down;
						break;
					case idir::right:
						backDir = idir::left;
						break;
					case idir::down:
						backDir = idir::up;
						break;
					case idir::left:
						backDir = idir::right;
						break;
					default:
						break;
					}
				}
			}
		}
	}

	void findNearestENeighbour(int color, int x, int y, vector<int> d)
	{
		bool find = false;
		int i = 0, j = 0;
		int tx = 0, ty = 0;
		
		for(j = 0; j < int(d.size()) && !find; ++j)
		{
			for(i = 1; i <= N && !find; ++i)
			{
				tx = x + i * dirX[d[j]];
				ty = y + i * dirY[d[j]];
	
				if(tx >= 0 && tx < N && ty >= 0 && ty < N && iboard[tx][ty] == color)
				{
					find = true;
					backX = tx;
					backY = ty;
					switch(d[j])
					{
					case idir::up:
						backDir = idir::down;
						break;
					case idir::right:
						backDir = idir::left;
						break;
					case idir::down:
						backDir = idir::up;
						break;
					case idir::left:
						backDir = idir::right;
						break;
					default:
						break;
					}
				}
			}
		}
	}

	int getNeighbourColor(int kind, int x, int y)
	{
		int ret = -1;
		if(kind == 0) {	ret = iboard[x - 1][y - 1]; }
		else if(kind == 1) { ret = iboard[x + 1][y - 1]; }
		else if(kind == 2) { ret = iboard[x + 1][y + 1]; }
		else if(kind == 3) { ret = iboard[x - 1][y + 1]; }
		return ret;
	}

	void setDirValue(int kind, int x, int y, int &nx, int &ny)
	{
		switch(kind)
		{
		case idir::up:
			nx = x - 1;
			ny = y;
			break;
		case idir::left:
			nx = x;
			ny = y - 1;
			break;
		case idir::down:
			nx = x + 1;
			ny = y;
			break;
		case idir::right:
			nx = x;
			ny = y + 1;
			break;
		default:
			break;
		}
	}

	void setRetValue(int x, int y, int d, int &pos, int &dir, int &col)
	{
		dir = d;
		pos = setPos(x, y);		
		col = iboard[x][y];
	}

	void swapColor(int x1, int y1, int x2, int y2)
	{
		if(iboard[x1][y1] == iboard[x2][y2])
		{
			backDir = -1;
			return;
		}
		int c = 0;
		c = iboard[x1][y1];
		iboard[x1][y1] = iboard[x2][y2];
		iboard[x2][y2] = c;
	}

	void assignDirections(int kind, int &d1, int &d2)
	{
		switch(kind)
		{
		case 0:
			d1 = idir::right;
			d2 = idir::down;
			break;
		case 1:
			d1 = idir::up;
			d2 = idir::right;
			break;
		case 2:
			d1 = idir::up;
			d2 = idir::left;
			break;
		case 3:
			d1 = idir::left;
			d2 = idir::down;
			break;
		default:
			break;
		}
	}

	int getNeighboursColor(int kind, int x, int y, 
		int &nbPos1, int &nbDir1, int &nbCol1, 
		int &nbPos2, int &nbDir2, int &nbCol2)
	{
		int ret = 0;
		int x1 = 0, y1 = 0, d1 = 0;
		int x2 = 0, y2 = 0, d2 = 0;

		assignDirections(kind, d1, d2);
		setDirValue(d1, x, y, x1, y1);
		setDirValue(d2, x, y, x2, y2);
		if(x1 >= 0 && x1 < N && y1 >= 0 && y1 < N)
		{
			ret += 1;
			setRetValue(x1, y1, d1, nbPos1, nbDir1, nbCol1);
		}
		if(x2 >= 0 && x2 < N && y2 >= 0 && y2 < N)
		{
			ret += 1;
			if(ret == 2)
			{			
				setRetValue(x2, y2, d2, nbPos2, nbDir2, nbCol2);
			}
			else if(ret == 1)
			{
				setRetValue(x2, y2, d2, nbPos1, nbDir1, nbCol1);
			}
		}

		return ret;
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

	bool judgeTripleRemovable(int i, int j, int kind, int &x, int &y, int &dir, int &spos)
	{
		bool find = false;
		vector<int> vdir;
		int pos1 = 0, dir1 = 0, col1 = 0;
		int pos2 = 0, dir2 = 0, col2 = 0;
		int ncolor = getNeighbourColor(kind, i, j);
		int m = getNeighboursColor(kind, i, j, pos1, dir1, col1, pos2, dir2, col2);
		if(m == 0) { return find; }
		if(ncolor == col1)
		{
			find = true;
			x = i;
			y = j;
			dir = dir1;
			spos = pos1;
		}
		if(!find && m == 2 && ncolor == col2)
		{
			find = true;
			x = i;
			y = j;
			dir = dir2;
			spos = pos2;
		}
		if(!find && backDir == -1 && kind == backK)
		{
			int edir[2];
			vdir.clear();
			backK = (backK + 1) % 4;
			assignDirections(kind, edir[0], edir[1]);
			vdir.push_back(edir[0]);
			vdir.push_back(edir[1]);
			findNearestNeighbour(ncolor, i, j, vdir);
		}
		return find;
	}
	void loopControl(int &x, int &y, int &dir)
	{
		bool find = false;
		int spos = -1;
		int i = 0, j = 0, k = -1;
		int m = 0;	

		backX = -1;
		backY = -1;
		backDir = -1;
		
		for(i = 0; i < N && !find; ++i)
		{
			for(j = 0; j < N && !find; ++j)
			{
				k = -1;
				if(this->rbTriple(i, j)) { find = judgeTripleRemovable(i, j, 0, x, y, dir, spos); }
				if(!find && this->rtTriple(i, j)) { find = judgeTripleRemovable(i, j, 1, x, y, dir, spos); }
				if(!find && this->ltTriple(i, j)) { find = judgeTripleRemovable(i, j, 2, x, y, dir, spos); }
				if(!find && this->lbTriple(i, j)) { find = judgeTripleRemovable(i, j, 3, x, y, dir, spos); }
			}
		}
		if(find)
		{
			int tx = 0, ty = 0;
			getPos(spos, tx, ty);
			swapColor(x, y, tx, ty);
			globalRemove(0, 0, N, N);
		}
		else
		{
			while(true)
			{
				handleNoTriple(x, y, dir);
				i = x + dirX[dir];
				j = y + dirY[dir];
				if(i >= 0 && i < N && j >= 0 && j < N && backDir != -1) { break; }
			}
		}
	}

	void handleNoTriple(int &x, int &y, int &dir)
	{
		int i = 0, j = 0;
		bool f = false;
		vector<int> vdir;
		if(backDir != -1)
		{
			x = backX;
			y = backY;
			dir = backDir;
			return;
		}

		if(backDir != -1)
		{
			backC = backC % (N * N);
			vdir.clear();
			vdir.push_back(idir::up);
			vdir.push_back(idir::right);
			vdir.push_back(idir::down);
			vdir.push_back(idir::left);
		
			for(i = backC / N; i < N && backDir == -1; ++i)
			{
				for(j = backC % N; j < N && backDir == -1; ++j)
				{
					findNearestNeighbour(iboard[i][j], i, j, vdir);
		
					f = true;
					x = backX;
					y = backY;
					dir = backDir;
				}
			}
			backC += 1;
		}
		swapColor(x, y, x + dirX[dir], y + dirY[dir]);
		globalRemove(0, 0, N, N);
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

	cin >> colors >> N;

	for(int i = 0; i < N; ++i)
	{
		string tmp;
		cin >> tmp;
		board.push_back(tmp);
	}

	cin >> startSeed;
	SquareRemover sr;
	vector<int> ret = sr.playIt(colors, board, startSeed); 

	for(int i = 0; i < 30000; ++i)
	{
		cout << ret[i] << endl;
	}

	return 0;
}