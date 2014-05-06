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
#include <climits>
using namespace std;
typedef long long ll;

class EmployManager
{
public:
    int maximumEarnings(vector <int> value, vector <string> earning)
    {
		int len = value.size();
		int i = 0, j = 0;
		int ret = 0, sum = 0;
		for(i = 0; i < len; ++i)
		{
			for(j = i + 1; j < len; ++j)
			{
				ret -= earning[i][j] - '0';
			}
		}
		for(i = 0; i < len; ++i)
		{
			sum = 0;
			for(j = 0; j < len; ++j)
			{
				sum += earning[i][j] - '0';
			}
			sum -= value[i];
			if(sum > 0)
			{
				ret += sum;
			}
		}
		return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"02", "20"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, maximumEarnings(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"01", "10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, maximumEarnings(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0121", "1021", "2201", "1110"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, maximumEarnings(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2, 2, 0, 1, 4, 0, 1, 0, 0, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0100451253",  "1010518123",  "0102989242",  "0020093171",  "4590045480",  "5189400676",  "1893500826",  "2121468008",  "5247872007",  "3321066870"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 156; verify_case(3, Arg2, maximumEarnings(Arg0, Arg1)); }
// END CUT HERE
};

// BEGIN CUT HERE
int main()
{
    EmployManager ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
