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

#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr << #x << " " << x << endl
#define se(x) cerr << " " << x 
#define pb push_back

class MinimumSquareEasy
{
public:
    long long minArea(vector <int> x, vector <int> y)
    {
		int n = sz(x);
		int i = 0, j = 0, k = 0;
		ll minX = LLONG_MAX;
		ll minY = LLONG_MAX;
		ll maxX = LLONG_MIN;
		ll maxY = LLONG_MIN;
		ll side = 0;
		ll res = LLONG_MAX, tmp = -1;

		for(i = 0; i < n - 1; ++i)
		{
			for(j = i + 1; j < n; ++j)
			{
				minX = LLONG_MAX;
				minY = LLONG_MAX;
				maxX = LLONG_MIN;
				maxY = LLONG_MIN;

				for(k = 0; k < n; ++k)
				{
					if(k == i || k == j)
					{
						continue;
					}
					if(x[k] < minX) { minX = x[k]; }
					if(x[k] > maxX) { maxX = x[k]; }
					if(y[k] < minY) { minY = y[k]; }
					if(y[k] > maxY) { maxY = y[k]; }
				}

				minX -= 1;
				maxX += 1;
				minY -= 1;
				maxY += 1;

				side = maxX - minX > maxY - minY ? maxX - minX : maxY - minY;

				tmp = side * side;
				if(tmp < res)
				{
					res = tmp;
				}
			}
		}

		return res;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4LL; verify_case(0, Arg2, minArea(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1, -1, 0, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2, -1, 0, -1, -2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 9LL; verify_case(1, Arg2, minArea(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1000000000, -1000000000, 1000000000, -1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000, 1000000000, -1000000000, -1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4000000008000000004LL; verify_case(2, Arg2, minArea(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {93, 34, 12, -11, -7, -21, 51, -22, 59, 74, -19, 29, -56, -95, -96, 9, 44, -37, -54, -21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {64, 12, -43, 20, 55, 74, -20, -54, 24, 20, -18, 77, 86, 22, 47, -24, -33, -57, 5, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 22801LL; verify_case(3, Arg2, minArea(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
    MinimumSquareEasy ___test;
    for(int i = 0; i < 4; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
