#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int board[8][8];
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};
inline int setPos(int x, int y) { return x * 10 + y; }
inline void getPos(int pos, int &x, int &y) { x = pos / 10; y = pos % 10; }
class BishopMove
{
public:
	int howManyMoves(int r1, int c1, int r2, int c2);
};
int BishopMove::howManyMoves(int r1, int c1, int r2, int c2)
{
	if(r1 == r2 && c1 == c2) { return 0; }
	int top = 0;
	int i = 0, j = 0;
	int stpX = 0, stpY = 0;
	int tmpX = r1, tmpY = c1;
	queue<int> ique;
	ique.push(setPos(r1, c1));
	memset(board, 0x7f, sizeof(board));
	board[r1][c1] = 0;
	while(!ique.empty())
	{
		top = ique.front();
		ique.pop();
		getPos(top, tmpX, tmpY);
		for(i = 0; i < 4; ++i)
		{
			for(j = 1; j < 8; ++j)
			{
				stpX = tmpX + j * dx[i];
				stpY = tmpY + j * dy[i];
				if(stpX >= 0 && stpX < 8 && stpY >= 0 && stpY < 8 && board[tmpX][tmpY] + 1 < board[stpX][stpY])
				{
					board[stpX][stpY] = board[tmpX][tmpY] + 1;
					ique.push(setPos(stpX, stpY));
				}
			}
		}
	}
	if(board[r2][c2] == 0x7f7f7f7f) { return -1; }
	return board[r2][c2];
}
int main()
{
	BishopMove bm;
	int result[4] = {1, 0, 2, -1};
	int runtest[4] = {
		bm.howManyMoves(4, 6, 7, 3),
		bm.howManyMoves(2, 5, 2, 5),
		bm.howManyMoves(1, 3, 5, 5),
		bm.howManyMoves(4, 6, 7, 4)};
	for(int i = 0; i < 4; ++i)
	{
		cout << (result[i] == runtest[i] ? "pass" : "fail") << endl;
	}
	return 0;
}