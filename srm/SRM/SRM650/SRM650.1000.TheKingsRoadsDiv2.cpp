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
#define SORT(X) sort(X.begin(), X.end())
#define SIZE(X) static_cast<int>(X.size())
using namespace std;
typedef long long ll;
const int N = 1024;
int n = 0, H = 0;
bool disabledEdge[N][N];
vector<bool> visited;
vector<vector<int> > g;
bool dfs(int x, int p, int h)
{
	// dfs to check if this is a balance binary tree
	if (!visited[x]) // make sure there are no cycles
	{
		int i = 0, y = 0;
		visited[x] = true;
		int a = -1, b = -1; // each node must have two children or zero
		for (i = 0; i < SIZE(g[x]); ++i)
		{
			y = g[x][i];
			if (!disabledEdge[x][y] && y != p)
			{
				if (a == -1) { a = y; }
				else if (b == -1) { b = y; }
				else { return false; }
			}
		}
		if (a == -1){ return h == 1; } // only allow leaves at the right depth
		else if (b == -1){ return false; } // only one child node
		else{ return dfs(a, x, h - 1) && dfs(b, x, h - 1); } // check the two subtrees
	}
	return false;
}
bool binaryTree()
{
	// find root, it must have degree 2.
	int root = -1;
	int i = 0, d = 0;
	int x = 0, y = 0;
	for (x = 0; x < n; ++x)
	{
		d = 0;
		for (i = 0; i < SIZE(g[x]); ++i)
		{
			y = g[x][i];
			if (!disabledEdge[x][y]){ d += 1; }
		}
		if (d == 2)
		{
			if (root == -1){ root = x; }
			else{ return false; } // only allow one root
		}
	}
	if (root == -1){ return false; }
	visited.resize(n);
	fill(visited.begin(), visited.end(), false);
	return dfs(root, -1, H);
}
class TheKingsRoadsDiv2
{
public:
	string getAnswer(int h, vector <int> a, vector <int> b)
	{
		H = h;
		n = (1 << h) - 1;
		g.resize(n);
		int badEdges = 1;
		int x = 0, y = 0;
		int i = 0, j = 0;
		for (i = 0; i < SIZE(b); ++i)
		{
			a[i] -= 1;
			b[i] -= 1;
			bool repeated = false;
			for (j = 0; j < i; ++j)
			{
				if ((a[i] == a[j] && b[i] == b[j]) || (a[i] == b[j] && a[j] == b[i]))
				{
					repeated = true;
				}
			}
			if (repeated || a[i] == b[i])
			{
				badEdges -= 1;
			}
			else
			{
				g[a[i]].push_back(b[i]);
				g[b[i]].push_back(a[i]);
			}
		}
		if (badEdges < 0){ return "Incorrect"; }
		if (badEdges == 0){ return binaryTree() ? "Correct" : "Incorrect"; }
		memset(disabledEdge, 0, sizeof(disabledEdge));
		for (x = 0; x < n; ++x)
		{
			for (i = 0; i < SIZE(g[x]); ++i)
			{
				y = g[x][i];
				if (y > x)
				{
					disabledEdge[x][y] = disabledEdge[y][x] = true;
					if (binaryTree()){ return "Correct"; }
					disabledEdge[x][y] = disabledEdge[y][x] = false;
				}
			}
		}
		return "Incorrect";
	}
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1, 2, 3, 7, 1, 5, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6, 7, 4, 3, 3, 1, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Correct"; verify_case(0, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Incorrect"; verify_case(1, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {7, 1, 1, 2, 2, 3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7, 1, 7, 4, 5, 2, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Incorrect"; verify_case(2, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {1, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Correct"; verify_case(3, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arr1[] = {6, 5, 3, 3, 5, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 5, 5, 6, 4, 7, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Correct"; verify_case(4, Arg3, getAnswer(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheKingsRoadsDiv2 ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
