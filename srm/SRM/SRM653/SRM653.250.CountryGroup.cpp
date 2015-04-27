#include <string>
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

class CountryGroup
{
public:
    int solve(vector <int> a)
    {
		int ret = 0;
        int i = 0, j = 0;
		int n = SIZE(a);
		for(i = 0; i < n; )
		{
			for(j = 0; j < a[i]; ++j)
			{
				if(i + j >= n || a[i + j] != a[i])
				{
					return -1;
				}
			}
			i += a[i];
			ret += 1;
		}
		return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,2,3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = {1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = {3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {4,4,4,4,1,1,2,2,3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { int Arr0[] = {2,1,2,2,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    CountryGroup ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
