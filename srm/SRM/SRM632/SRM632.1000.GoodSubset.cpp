/**
 * Since the maximum number is 2,000,000,000, it's a very big number, 
 * thus if using general dp sequence, it maybe overflow or using more time.
 * So the computation starts from goodValue, dividing each elements until the result is 1 or not.
 */
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

vector<int> gd;
map<int, int> dp[101];

int mod = 1000000007;

int f(int v, int t)
{
	if(dp[t].count(v) == 0)
	{
		int res = 0;
		if(t == 0)
		{
			if(v == 1)
			{
				res = 1;
			}
		}
		else
		{
			if(v % gd[t - 1] == 0)
			{
				res = (res + f(v / gd[t - 1], t - 1)) % mod;
			}
			res = (res + f(v, t - 1)) % mod;
		}
		dp[t][v] = res;
	}
	return dp[t][v];
}

class GoodSubset
{
public:
    int numberOfSubsets(int goodValue, vector <int> d)
    {
		for(int i = 0; i < 101; ++i)
		{
			dp[i].clear();
		}
		gd = vector<int>(d.begin(), d.end());
		return f(goodValue, gd.size()) - (goodValue == 1 ? 1 : 0);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(2, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 12; int Arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, numberOfSubsets(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    GoodSubset ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
