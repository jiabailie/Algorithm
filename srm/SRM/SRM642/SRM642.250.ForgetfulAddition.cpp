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

void cal(int index, string e, int &a, int &b)
{
	a = 0;
	b = 0;
	int i = 0;
	for(i = 0; i <= index; ++i)
	{
		a = a * 10 + (e[i] - '0');
	}
	for(i = index + 1; i < e.size(); ++i)
	{
		b = b * 10 + (e[i] - '0');
	}
}

class ForgetfulAddition
{
public:
    int minNumber(string expression)
    {
        int ret = INT_MAX;
		int a = 0, b = 0;
		for(int i = 0; i < expression.size() - 1; ++i)
		{
			cal(i, expression, a, b);
			if(a + b < ret)
			{
				ret = a + b;
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
	void test_case_0() { string Arg0 = "22"; int Arg1 = 4; verify_case(0, Arg1, minNumber(Arg0)); }
	void test_case_1() { string Arg0 = "123"; int Arg1 = 15; verify_case(1, Arg1, minNumber(Arg0)); }
	void test_case_2() { string Arg0 = "1289"; int Arg1 = 101; verify_case(2, Arg1, minNumber(Arg0)); }
	void test_case_3() { string Arg0 = "31415926"; int Arg1 = 9067; verify_case(3, Arg1, minNumber(Arg0)); }
	void test_case_4() { string Arg0 = "98765"; int Arg1 = 863; verify_case(4, Arg1, minNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ForgetfulAddition ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
