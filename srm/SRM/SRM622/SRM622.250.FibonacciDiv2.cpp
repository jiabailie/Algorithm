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
inline int iabs(int x) { return x > 0 ? x : -x; }
class FibonacciDiv2
{
public:
    int find(int N)
    {
		int s = 0, t = 0;
		int iMax = 1000000;
		int minus = iMax;
		int a = 0, b = 1;
		for(int i = 2; i <= iMax; ++i)
		{
			t = a + b;
			if(t > iMax) { break; }
			s = iabs(t - N);
			if(s < minus) { minus = s; }
			if(minus == 0 || s > minus) { break; }
			a = b;
			b = t;
		}
		return minus;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arg0 = 13; int Arg1 = 0; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 2; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arg0 = 19; int Arg1 = 2; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 167960; verify_case(4, Arg1, find(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
    FibonacciDiv2 ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
