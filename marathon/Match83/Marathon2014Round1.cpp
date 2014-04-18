#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#define DEBUG
using namespace std;

typedef long long ll;

enum direction { up = 0, right = 1, down = 2, left = 3, rt = 4, lt = 5, lb = 6, rb = 7 };

int N = 0;
int dirX[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dirY[8] = {0, 1, 0, -1, 1, -1, -1, 1};

// 0 right-bottom
// 1 right-top
// 2 left-top
// 3 left-bottom
vector<int> triples[4];

int iboard[16][16];

inline int setPos(int x, int y)
{
	return x * N + y;
}

inline void getPos(int p, int &x, int &y)
{
	x = p / N;
	y = p % N;
}

class SquareRemover
{
private:
	bool rbTriple(int, int);

	bool rtTriple(int, int);

	bool ltTriple(int, int);

	bool lbTriple(int, int);

	bool judgeTriple(int, int, int[3]);

	void calColor(int, int, vector<int>&);

	void getTriples();
public:
	vector<int> playIt(int colors, vector<string> board, int startSeed);
};

bool SquareRemover::rbTriple(int x, int y)
{
	int dirs[3] = {direction::up, direction::lt, direction::left};
	return judgeTriple(x, y, dirs);
}

bool SquareRemover::rtTriple(int x, int y)
{
	int dirs[3] = {direction::left, direction::lb, direction::down};
	return judgeTriple(x, y, dirs);
}

bool SquareRemover::ltTriple(int x, int y)
{
	int dirs[3] = {direction::right, direction::rb, direction::down};
	return judgeTriple(x, y, dirs);
}

bool SquareRemover::lbTriple(int x, int y)
{
	int dirs[3] = {direction::up, direction::rt, direction::right};
	return judgeTriple(x, y, dirs);
}

bool SquareRemover::judgeTriple(int x, int y, int dirs[3])
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

void SquareRemover::calColor(int colors, int startSeed, vector<int> &color)
{
	int i = 0;
	int c = 80000;
	ll tmp = 0;
	ll mul = 48271;
	ll mod = 2147483647;

	color.push_back(startSeed);

	for(i = 1; i < c; ++i)
	{
		tmp = color[i - 1];
		tmp = (tmp * mul) % mod;
		color.push_back(tmp);
		color[i - 1] = color[i - 1] % colors;
	}
	color[c - 1] = color[c - 1] % colors;
}

void SquareRemover::getTriples()
{
	int i = 0, j = 0;

	for(i = 0; i < 4; triples[i].clear(), ++i);

	for(i = 0; i < N; ++i)
	{
		for(j = 0; j < N; ++j)
		{
			if(this->rbTriple(i, j)) { triples[0].push_back(setPos(i, j)); }
			if(this->rtTriple(i, j)) { triples[1].push_back(setPos(i, j)); }
			if(this->ltTriple(i, j)) { triples[2].push_back(setPos(i, j)); }
			if(this->lbTriple(i, j)) { triples[3].push_back(setPos(i, j)); }
		}
	}
}

vector<int> SquareRemover::playIt(int colors, vector<string> board, int startSeed)
{
	int i = 0, j = 0;
	vector<int> ret;
	vector<int> color;

	calColor(colors, startSeed, color);
	memset(iboard, 0, sizeof(iboard));

	for(i = 0; i < N; ++i)
	{
		for(j = 0; j < N; ++j)
		{
			iboard[i][j] = board[i][j] - '0';
		}
	}

	getTriples();

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