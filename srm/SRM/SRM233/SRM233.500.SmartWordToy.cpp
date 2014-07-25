#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long ll;

const int n = 32;

int startAry[4];
int finishAry[4];
int cost[n][n][n][n];
bool board[n][n][n][n];

struct point
{
	int d1;
	int d2;
	int d3;
	int d4;
	point() : d1(0), d2(0), d3(0), d4(0) {}
	point(int _d1, int _d2, int _d3, int _d4) : d1(_d1), d2(_d2), d3(_d3), d4(_d4) {}
	point(const point &p) : d1(p.d1), d2(p.d2), d3(p.d3), d4(p.d4) {}
	point& operator=(const point &p)
	{
		if(this == &p) { return *this; }
		d1 = p.d1;
		d2 = p.d2;
		d3 = p.d3;
		d4 = p.d4;
		return *this;
	}
};

void analyseForbid(string item)
{
	int i = 0, j = 0;
	int m = 0, n = 0;
	string segment;
	vector<string> split;
	for(i = 0; i < item.size(); ++i)
	{
		if(item[i] == ' ') { split.push_back(string(segment.begin(), segment.end())); segment.clear(); }
		else { segment.push_back(item[i]); }
	}
	if(segment.size() > 0) { split.push_back(string(segment.begin(), segment.end())); }
	for(i = 0; i < split[0].size(); ++i)
	{
		for(j = 0; j < split[1].size(); ++j)
		{
			for(m = 0; m < split[2].size(); ++m)
			{
				for(n = 0; n < split[3].size(); ++n)
				{
					board[int(split[0][i] - 'a')][int(split[1][j] - 'a')][int(split[2][m] - 'a')][int(split[3][n] - 'a')] = false;
				}
			}
		}
	}
}

void bfs()
{
	int i = 0, j = 0;
	int dir[2] = {1, -1};
	int x = 0, y = 0;
	int m = 0, n = 0;
	point front;
	queue<point> ique;
	ique.push(point(startAry[0], startAry[1], startAry[2], startAry[3]));
	cost[startAry[0]][startAry[1]][startAry[2]][startAry[3]] = 0;

	while(!ique.empty())
	{
		front = ique.front();
		ique.pop();
		for(i = 0; i < 4; ++i)
		{
			for(j = 0; j < 2; ++j)
			{
				x = front.d1;
				y = front.d2;
				m = front.d3;
				n = front.d4;
				switch(i)
				{
				case 0:
					x = (x + dir[j] + 26) % 26;
					break;
				case 1:
					y = (y + dir[j] + 26) % 26;
					break;
				case 2:
					m = (m + dir[j] + 26) % 26;
					break;
				case 3:
					n = (n + dir[j] + 26) % 26;
					break;
				default:
					break;
				}
				if(board[x][y][m][n] && cost[front.d1][front.d2][front.d3][front.d4] + 1 < cost[x][y][m][n])
				{
					cost[x][y][m][n] = cost[front.d1][front.d2][front.d3][front.d4] + 1;
					ique.push(point(x, y, m, n));
				}
			}
		}
	}
}

class SmartWordToy
{
public:
    int minPresses(string start, string finish, vector <string> forbid)
    {
		int i = 0;		
		memset(board, 1, sizeof(board));
		memset(cost, 0x7f, sizeof(cost));
		for(i = 0; i < forbid.size(); ++i)
		{
			analyseForbid(forbid[i]);
		}
		for(i = 0; i < 4; ++i)
		{
			startAry[i] = int(start[i] - 'a');
			finishAry[i] = int(finish[i] - 'a');
		}
		bfs();
        return cost[finishAry[0]][finishAry[1]][finishAry[2]][finishAry[3]] == 0x7f7f7f7f ? 
			-1 : cost[finishAry[0]][finishAry[1]][finishAry[2]][finishAry[3]];
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aaaa"; string Arg1 = "zzzz"; string Arr2[] = {"a a a z", "a a z a", "a z a a", "z a a a", "a z z z", "z a z z", "z z a z", "z z z a"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(0, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "aaaa"; string Arg1 = "bbbb"; vector <string> Arg2; int Arg3 = 4; verify_case(1, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "aaaa"; string Arg1 = "mmnn"; vector <string> Arg2; int Arg3 = 50; verify_case(2, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "aaaa"; string Arg1 = "zzzz"; string Arr2[] = {"bz a a a", "a bz a a", "a a bz a", "a a a bz"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(3, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "aaaa"; string Arg1 = "zzzz"; string Arr2[] = {"cdefghijklmnopqrstuvwxyz a a a", 
 "a cdefghijklmnopqrstuvwxyz a a", 
 "a a cdefghijklmnopqrstuvwxyz a", 
 "a a a cdefghijklmnopqrstuvwxyz"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(4, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "aaaa"; string Arg1 = "bbbb"; string Arr2[] = {"b b b b"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(5, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arg0 = "zzzz"; string Arg1 = "aaaa"; string Arr2[] = {"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(6, Arg3, minPresses(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SmartWordToy ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
