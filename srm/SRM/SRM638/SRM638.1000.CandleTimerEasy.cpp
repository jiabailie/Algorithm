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
#include <list>
using namespace std;
typedef long long ll;
class CandleTimerEasy
{
public:
    int differentTime(vector <int> A, vector <int> B, vector <int> len)
    {
		const int INF = 1000000000;
		int n = A.size() + 1;
		vector<list<int> > g(n);
		vector<vector<int> > w(n, vector<int>(n, INF));

		for(int i = 0; i < n - 1; ++i)
		{
			len[i] <<= 1;
			for(int j = 0; j < 2; ++j)
			{
				g[A[i]].push_back(B[i]);
				w[A[i]][B[i]] = len[i];
				swap(A[i], B[i]);
			}
		}

		vector<int> leaves;
		for(int i = 0; i < n; ++i)
		{
			if(g[i].size() == 1)
			{
				leaves.push_back(i);
			}
		}
		int t = leaves.size();

		set<int> times;
		for(int mask = 1; mask < (1 << t); ++mask)
		{
			vector<int> dist(n, INF);
			vector<int> Q;
			vector<int> parent(n, -1);
			for(int i = 0; i < t; ++i)
			{
				if(mask & (1 << i))
				{
					int u = leaves[i];
					dist[u] = 0;
					Q.push_back(u);
				}
			}
			int mx = 0;
			while(Q.size() > 0)
			{
				int s = 0;
				for(int i = 1; i < Q.size(); ++i)
				{
					if(dist[Q[i]] < dist[Q[s]])
					{
						s = i;
					}
				}
				int x = Q[s];
				Q[s] = Q[Q.size() - 1];
				Q.pop_back();
				mx = std::max(mx, dist[x]);
				for(list<int>::iterator it = g[x].begin(); it != g[x].end(); ++it)
				{
					int y = *it;
					if(dist[y] > dist[x] + w[x][y])
					{
						parent[y] = x;
						dist[y] = dist[x] + w[x][y];
						if(count(Q.begin(), Q.end(), y) == 0)
						{
							Q.push_back(y);
						}
					}
				}
			}
			for(int i = 0; i < A.size(); ++i)
			{
				int x = dist[A[i]], y = dist[B[i]];
				if(x < y) { swap(x, y); }
				if((parent[A[i]] != B[i]) && (parent[B[i]] != A[i]))
				{
					if(x - y <= len[i])
					{
						mx = std::max(mx, x + (len[i] - (x - y)) / 2);
					}
				}
			}
			times.insert(mx);
		}
		return times.size();
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(2, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,1,1,2,3,3,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,3,2,4,6,8,7,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(3, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {123,456,789,1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(4, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(5, Arg3, differentTime(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
    CandleTimerEasy ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
