#include <cstring>
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

class ValueOfString
{
public:
    int findValue(string s)
    {
		int i = 0;
		int j = 0;
        int c[27];
		int p[27];
		memset(c, 0, sizeof(c));
		memset(p, 0, sizeof(p));
		for(i = 0; i < SIZE(s); ++i)
		{
			c[s[i] - 'a' + 1] += 1;
		}
		p[1] = c[1];
		for(i = 2; i < 27; ++i)
		{
			p[i] = p[i - 1] + c[i];
		}
		int ret = 0;
		for(i = 0; i < SIZE(s); ++i)
		{
			j = int(s[i] - 'a' + 1);
			ret += j * p[j];
		}
		return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "babca"; int Arg1 = 35; verify_case(0, Arg1, findValue(Arg0)); }
	void test_case_1() { string Arg0 = "zz"; int Arg1 = 104; verify_case(1, Arg1, findValue(Arg0)); }
	void test_case_2() { string Arg0 = "y"; int Arg1 = 25; verify_case(2, Arg1, findValue(Arg0)); }
	void test_case_3() { string Arg0 = "aaabbc"; int Arg1 = 47; verify_case(3, Arg1, findValue(Arg0)); }
	void test_case_4() { string Arg0 = "topcoder"; int Arg1 = 558; verify_case(4, Arg1, findValue(Arg0)); }
	void test_case_5() { string Arg0 = "thequickbrownfoxjumpsoverthelazydog"; int Arg1 = 11187; verify_case(5, Arg1, findValue(Arg0)); }
	void test_case_6() { string Arg0 = "zyxwvutsrqponmlkjihgfedcba"; int Arg1 = 6201; verify_case(6, Arg1, findValue(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ValueOfString ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
