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
#include <utility>
using namespace std;
typedef long long ll;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int a[2010][2010];

struct p
{
	int x;
	int y;
	p() {}
	p(int _x, int _y) : x(_x), y(_y) {}
};

class TheGridDivTwo
{
public:
    int find(vector <int> x, vector <int> y, int k)
    {
		int res = 0;
		int i = 0;
		int ox = 0, oy = 0;
		int nx = 0, ny = 0;

		memset(a, 0, sizeof(a));
		
		for(i = 0; i < x.size(); ++i)
		{
			a[x[i] + 1000][y[i] + 1000] = -1;
		}
		queue<p> q;
		q.push(p(1000,1000));

		a[1000][1000] = 0;

		while(!q.empty())
		{
			ox = q.front().x;
			oy = q.front().y;
			if(a[ox][oy] <= k)
			{
				res = std::max(res, ox - 1000);
			}
			q.pop();
			for(i = 0; i < 4; ++i)
			{
				nx = ox + dx[i];
				ny = oy + dy[i];
				if(nx < 0 || nx > 2000 || ny < 0 || ny > 2000 || a[nx][ny] != 0 || a[ox][oy] + 1 > k)
				{
					continue;
				}
				a[nx][ny] = a[ox][oy] + 1;
				q.push(p(nx, ny));
			}
		}
		return res;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2,-1,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 2; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {-1, 0, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -1, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = 0; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1,0,0,-1,-1,-2,-2,-3,-3,-4,-4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,-1,1,-2,2,-3,3,-4,4,-5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; int Arg3 = 31; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,0,0,-1,-1,-2,-2,-3,-3,-4,-4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,-1,1,-2,2,-3,3,-4,4,-5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; int Arg3 = 31; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheGridDivTwo ___test;
    for(int i = 2; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
