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

class AliceGameEasy
{
public:
    long long findMinimumValue(long long x, long long y)
    {
        ll p = x + y;
		ll s = 0.5 * sqrt(1 + 8.0 * p) - 0.5;
		ll t = (s + s * s) >> 1;
		if(p != t)
		{
			return -1;
		}
		t = 0;
		for(ll i = s; i > 0 && x > 0; --i)
		{
			if(x >= i)
			{
				x -= i;
				t += 1;
			}
		}
		return t;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 7LL; long long Arg1 = 14LL; long long Arg2 = 2LL; verify_case(0, Arg2, findMinimumValue(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 10LL; long long Arg1 = 0LL; long long Arg2 = 4LL; verify_case(1, Arg2, findMinimumValue(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 932599670050LL; long long Arg1 = 67400241741LL; long long Arg2 = 1047062LL; verify_case(2, Arg2, findMinimumValue(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 7LL; long long Arg1 = 13LL; long long Arg2 = -1LL; verify_case(3, Arg2, findMinimumValue(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 0LL; long long Arg1 = 0LL; long long Arg2 = 0LL; verify_case(4, Arg2, findMinimumValue(Arg0, Arg1)); }
	void test_case_5() { long long Arg0 = 100000LL; long long Arg1 = 400500LL; long long Arg2 = 106LL; verify_case(5, Arg2, findMinimumValue(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    AliceGameEasy ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
