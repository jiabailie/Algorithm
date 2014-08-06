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
bool legal = false;
char bracket[6] = {'(' , ')', '[', ']', '{', '}'};
bool judgeLegal(const char *expr)
{
	stack<char> istack;
	int cur = 0;
	char top = 0;
	int len = strlen(expr);
	istack.push(expr[0]);
	while(cur + 1 < len)
	{
		cur += 1;
		if(!istack.empty())
		{
			top = istack.top();
			if((top == '(' && expr[cur] == ')') || 
			   (top == '[' && expr[cur] == ']') || 
			   (top == '{' && expr[cur] == '}'))
			{
				istack.pop();
				continue;
			}
		}
		istack.push(expr[cur]);
	}
	return istack.empty();
}
class BracketExpressions
{
public:
    string ifPossible(string expression)
    {
		vector<int> x;
		int n = expression.size();
		int i = 0, m = 0;
		for(i = 0; i < n; ++i)
		{
			if(expression[i] == 'X')
			{
				x.push_back(i);
			}
		}
		int t = x.size();
		int p6[6];
		p6[0] = 1;
		for(i = 1; i < 6; ++i)
		{
			p6[i] = 6 * p6[i - 1];
		}
		const char *chars = "([{)]}";
		for(m = 0; m < p6[t]; ++m)
		{
			string nexp = expression;
			for(i = 0; i < t; ++i)
			{
				nexp[x[i]] = chars[(m / p6[i]) % 6];
			}
			if(judgeLegal(nexp.c_str()))
			{
				return "possible";
			}
		}
		return "impossible";
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "()}{[]"; string Arg1 = "impossible"; verify_case(0, Arg1, ifPossible(Arg0)); }
	void test_case_1() { string Arg0 = "{[[X[X[XX[[[[X[[[[[[[[{[()]}]]]]]]]]]]]]]]]]]])]]}"; string Arg1 = "possible"; verify_case(1, Arg1, ifPossible(Arg0)); }
	void test_case_2() { string Arg0 = "({])"; string Arg1 = "impossible"; verify_case(2, Arg1, ifPossible(Arg0)); }
	void test_case_3() { string Arg0 = "[]X"; string Arg1 = "impossible"; verify_case(3, Arg1, ifPossible(Arg0)); }
	void test_case_4() { string Arg0 = "([]X()[()]XX}[])X{{}}]"; string Arg1 = "possible"; verify_case(4, Arg1, ifPossible(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    BracketExpressions ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
