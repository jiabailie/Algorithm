#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <numeric>
#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
#define SORT(X) sort(X.begin(), X.end())
#define SIZE(X) static_cast<int>(X.size())
using namespace std;
typedef long long ll;

const int N = 21;
int n = 0;
bool g[N][N];

int findcc(int a, int b)
{
	int c = 0;
	vector<bool> visited(n, false);
	queue<int> iq;
	if(a >= 0 && b >= 0)
	{
		visited[a] = visited[b] = true;
	}
	int i = 0, j = 0, k = 0;
	for(i = 0; i < n; ++i)
	{
		if(!visited[i])
		{
			iq.push(i);
			c += 1;
			while(!iq.empty())
			{
				j = iq.front();
				iq.pop();
				visited[j] = true;
				for(k = 0; k < n; ++k)
				{
					if(g[j][k] && !visited[k])
					{
						iq.push(k);
					}
				}
			}
		}
	}
	return c;
}

class Fragile2
{
public:
    int countPairs(vector <string> graph)
    {
		n = SIZE(graph);
		int i = 0, j = 0;
        memset(g, 0, sizeof(g));
		for(i = 0; i < n; ++i)
		{
			for(j = 0; j < n; ++j)
			{
				if(graph[i][j] == 'Y')
				{
					g[i][j] = true;
				}
			}
		}
		int o = findcc(-1, -1);
		int ret = 0;
		int k = 0;
		for(i = 0; i < n - 1; ++i)
		{
			for(j = i + 1; j < n; ++j)
			{
				k = findcc(i, j);
				if(k > o)
				{
					ret += 1;
				}
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
	void test_case_0() { string Arr0[] = {"NYNN", "YNYN", "NYNY", "NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, countPairs(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYNNNN", "YNYNNN", "NYNNNN", "NNNNYN", "NNNYNY", "NNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, countPairs(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNN", "NNN", "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, countPairs(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNYNNYYNN", "YNNNYNYYNN", "NNNNYNNNYN", "YNNNYYNNNN", "NYYYNNNNYN",
 "NNNYNNNNYN", "YYNNNNNNNN", "YYNNNNNNYN", "NNYNYYNYNY", "NNNNNNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(3, Arg1, countPairs(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNNYNNYNNNNNNNYYNNNY", "NNNNNNNNYNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNN", "YNNNNNNNNNYNNNNNNNNN", "NNNNNNNYNNNNNYNNNNYN",
 "NNNNNNNNNNNNNNNNYNNY", "YNNNNNNNNNNNNYYYNYNN", "NNNNYNNNNNNNNYYNNNNN", "NYNNNNNNNYNNNNNNNNNN", "NNNNNNNNYNNNYNNNNNYN",
 "NNNYNNNNNNNNNNYNNNNN", "NNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNYNNNNNNNYNN", "NNNNYNYYNNNNNNNNNNNN", "YNNNNNYYNNYNNNNNNNNN",
 "YNNNNNYNNNNNNNNNYNNN", "NNNNNYNNNNNNNNNYNYNN", "NNNNNNYNNNNNYNNNYNNN", "NNNNYNNNNYNNNNNNNNNN", "YNNNNYNNNNNNNNNNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; verify_case(4, Arg1, countPairs(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Fragile2 ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
