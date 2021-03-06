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

class LightSwitchingPuzzle
{
public:
    int minFlips(string state)
    {
		int i = 0, j = 0;
		int n = state.size();
		int ret = 0;
		for(i = 1; i <= n; ++i)
		{
			if(state[i - 1] == 'Y')
			{
				ret += 1;
				for(j = i - 1; j < n; j += i)
				{
					state[j] = state[j] == 'Y' ? 'N' : 'Y';
				}
			}
		}
		return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YYYYYY"; int Arg1 = 1; verify_case(0, Arg1, minFlips(Arg0)); }
	void test_case_1() { string Arg0 = "YNYNYNYNY"; int Arg1 = 2; verify_case(1, Arg1, minFlips(Arg0)); }
	void test_case_2() { string Arg0 = "NNNNNNNNNN"; int Arg1 = 0; verify_case(2, Arg1, minFlips(Arg0)); }
	void test_case_3() { string Arg0 = "YYYNYYYNYYYNYYNYYYYN"; int Arg1 = 4; verify_case(3, Arg1, minFlips(Arg0)); }
	void test_case_4() { string Arg0 = "NYNNYNNNYNNNNYNNNNNYNNNNNNYNNNNNNNY"; int Arg1 = 12; verify_case(4, Arg1, minFlips(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    LightSwitchingPuzzle ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
