#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
typedef long long ll;

class PaperAndPaintEasy
{
public:
    long long computeArea(int width, int height, int xfold, int cnt, int x1, int y1, int x2, int y2)
    {
		ll t = std::min(xfold, width - xfold);
		ll total = ll(width) * ll(height);
		if(x2 <= t)
		{
			return total - ll(x2 - x1) * ll(y2 - y1) * ll(cnt + 1) * 2ll;
		}
		else if(x1 > t)
		{
			return total - ll(x2 - x1) * ll(y2 - y1) * ll(cnt + 1);
		}
		return total - ll(t - x1) * ll(y2 - y1) * ll(cnt + 1) * 2ll - ll(x2 - t) * ll(y2 - y1) * ll(cnt + 1);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 2; int Arg3 = 2; int Arg4 = 1; int Arg5 = 1; int Arg6 = 3; int Arg7 = 2; long long Arg8 = 21LL; verify_case(0, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 13; int Arg2 = 1; int Arg3 = 0; int Arg4 = 1; int Arg5 = 8; int Arg6 = 2; int Arg7 = 12; long long Arg8 = 35LL; verify_case(1, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 12; int Arg2 = 7; int Arg3 = 3; int Arg4 = 3; int Arg5 = 1; int Arg6 = 6; int Arg7 = 2; long long Arg8 = 124LL; verify_case(2, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 4; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 1; int Arg7 = 1; long long Arg8 = 19LL; verify_case(3, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_4() { int Arg0 = 298140737; int Arg1 = 517853687; int Arg2 = 236446916; int Arg3 = 42; int Arg4 = 39184978; int Arg5 = 612986; int Arg6 = 47019319; int Arg7 = 2238239; long long Arg8 = 153298260286005841LL; verify_case(4, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_5() { int Arg0 = 202780277; int Arg1 = 318110070; int Arg2 = 40044318; int Arg3 = 9; int Arg4 = 1144186; int Arg5 = 10474356; int Arg6 = 2849401; int Arg7 = 25512278; long long Arg8 = 63993590307824790LL; verify_case(5, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PaperAndPaintEasy ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
