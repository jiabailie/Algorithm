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
class NamingConvention
{
public:
    string toCamelCase(string v)
    {
		string ret("");
		for(int i = 0; i < v.size(); ++i)
		{
			if(i == 0)
			{
				ret.push_back(v[0]);
				continue;
			}
			if(v[i] == '_')
			{
				continue;
			}
			if(i - 1 >= 0 && v[i - 1] == '_')
			{
				ret.push_back(char('A' + v[i] - 'a'));
			}
			else
			{
				ret.push_back(v[i]);
			}
		}
		return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "sum_of_two_numbers"; string Arg1 = "sumOfTwoNumbers"; verify_case(0, Arg1, toCamelCase(Arg0)); }
	void test_case_1() { string Arg0 = "variable"; string Arg1 = "variable"; verify_case(1, Arg1, toCamelCase(Arg0)); }
	void test_case_2() { string Arg0 = "t_o_p_c_o_d_e_r"; string Arg1 = "tOPCODER"; verify_case(2, Arg1, toCamelCase(Arg0)); }
	void test_case_3() { string Arg0 = "the_variable_name_can_be_very_long_like_this"; string Arg1 = "theVariableNameCanBeVeryLongLikeThis"; verify_case(3, Arg1, toCamelCase(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
    NamingConvention ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
