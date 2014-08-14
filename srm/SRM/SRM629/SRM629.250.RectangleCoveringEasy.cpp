#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
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

class RectangleCoveringEasy
{
public:
    int solve(int holeH, int holeW, int boardH, int boardW)
    {
        int hH = std::min(holeH, holeW);
		int hW = std::max(holeH, holeW);
		int bH = std::min(boardH, boardW);
		int bW = std::max(boardH, boardW);

		if((hH < bH && hW < bW) || (hH == bH && hW < bW) || (hH < bH && hW == bW))
		{
			return 1;
		}
		return -1;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = -1; verify_case(0, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 4; int Arg3 = 6; int Arg4 = 1; verify_case(1, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 602841311; int Arg1 = 910449437; int Arg2 = 3919002; int Arg3 = 932964157; int Arg4 = -1; verify_case(2, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 10; int Arg2 = 3; int Arg3 = 12; int Arg4 = 1; verify_case(3, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    RectangleCoveringEasy ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
