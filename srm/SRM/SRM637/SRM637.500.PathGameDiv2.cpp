#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <climits>
using namespace std;
typedef long long ll;
int dis[2][55];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
inline int setPos(int x, int y) { return x * 100 + y; }
inline void getPos(int &x, int &y, int pos) { x = pos / 100; y = pos % 100; }
int bfs(int start, vector<string> &board)
{
	memset(dis, 0x7f, sizeof(dis));
	queue<int> iqueue;
	iqueue.push(setPos(start, 0));
	int i = 0, w = board[0].size();
	int px = 0, py = 0;
	int tx = 0, ty = 0;
	dis[start][0] = 1;
	while(!iqueue.empty())
	{
		getPos(tx, ty, iqueue.front());
		iqueue.pop();
		for(i = 0; i < 4; ++i)
		{
			px = tx + dx[i];
			py = ty + dy[i];
			if(px >= 0 && px < board.size() && py >= 0 && py < w && board[px][py] == '.' && dis[tx][ty] + 1 < dis[px][py])
			{
				dis[px][py] = dis[tx][ty] + 1;
				iqueue.push(setPos(px, py));
			}
		}
	}
	return std::min(dis[0][w - 1], dis[1][w - 1]);
}
class PathGameDiv2
{
public:
    int calc(vector <string> board)
    {
		int pathLen1 = 100000;
		int pathLen2 = 100000;
		int black = 0;		
		for(int i = 0; i < 2; ++i)
		{
			for(int j = 0; j < board[i].size(); ++j)
			{
				if(board[i][j] == '#')
				{
					black += 1;
				}
			}
		}
		if(board[0][0] == '.')
		{
			pathLen1 = bfs(0, board);
		}
		if(board[1][0] == '.')
		{
			pathLen2 = bfs(1, board);
		}
		pathLen1 = std::min(pathLen1, pathLen2);
		return 2 * board[0].size() - pathLen1 - black;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#...."
,"...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, calc(Arg0)); }
	void test_case_1() { string Arr0[] = {"#"
,"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, calc(Arg0)); }
	void test_case_2() { string Arr0[] = {"."
,"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, calc(Arg0)); }
	void test_case_3() { string Arr0[] = {"....#.##.....#..........."
,"..#......#.......#..#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(3, Arg1, calc(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
    PathGameDiv2 ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
