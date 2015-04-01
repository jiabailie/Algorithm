#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <numeric>
#include <iostream>
#include <climits>
#define SORT(X) sort(X.begin(), X.end())
#define SIZE(X) static_cast<int>(X.size())
using namespace std;
typedef long long ll;

class RobotOnMoonEasy
{
public:
    string isSafeCommand(vector <string> board, string S)
    {
		bool find = false;
		int i = 0, j = 0;
        int cx = 0, cy = 0;
		int nx = 0, ny = 0;
		for(i = 0; i < SIZE(board) && !find; ++i)
		{
			for(j = 0; j <SIZE(board[0]) && !find; ++j)
			{
				if(board[i][j] == 'S')
				{
					cx = i;
					cy = j;
					board[i][j] = '.';
					find = true;
				}
			}
		}
		for(i = 0; i < SIZE(S); ++i)
		{
			switch(S[i])
			{
			case 'U':
				nx = cx - 1;
				ny = cy;
				break;
			case 'D':
				nx = cx + 1;
				ny = cy;
				break;
			case 'L':
				nx = cx;
				ny = cy - 1;
				break;
			case 'R':
				nx = cx;
				ny = cy + 1;
				break;
			default:
				break;
			}
			if(nx < 0 || nx >= SIZE(board) || ny < 0 || ny >= SIZE(board[0]))
			{
				return "Dead";
			}
			else if(board[nx][ny] == '#')
			{
				continue;
			}
			else if(board[nx][ny] == '.')
			{
				cx = nx;
				cy = ny;
			}
		}
		return "Alive";
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
 ".###.",
 "..S#.",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURURURUR"; string Arg2 = "Alive"; verify_case(0, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".....",
 ".###.",
 "..S..",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURURURUR"; string Arg2 = "Dead"; verify_case(1, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".....",
 ".###.",
 "..S..",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURU"; string Arg2 = "Alive"; verify_case(2, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"; string Arg2 = "Alive"; verify_case(3, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#.###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"; string Arg2 = "Dead"; verify_case(4, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "R"; string Arg2 = "Dead"; verify_case(5, Arg2, isSafeCommand(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    RobotOnMoonEasy ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
