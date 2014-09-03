#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
int dis[11][11];

class Egalitarianism3Easy
{
public:
	void getDots(int k, vector<int> &dots)
	{
		dots.clear();
		for(int i = 0; i < 12; ++i)
		{
			if(k & (1 << i))
			{
				dots.push_back(i);
			}
		}
	}
	bool satisfy(vector<int> &dots)
	{
		if(dots.size() == 1) { return 1; }
		int i = 0, j = 0;
		int stand = dis[dots[0]][dots[1]];
		for(i = 0; i < dots.size() - 1; ++i)
		{
			for(j = i + 1; j < dots.size(); ++j)
			{
				if(dis[dots[i]][dots[j]] != stand)
				{
					return false;
				}
			}
		}
		return true;
	}
    int maxCities(int n, vector <int> a, vector <int> b, vector <int> len)
    {
		int ret = 0;
        int i = 0, j = 0, k = 0;
		vector<int> dots;
		if(n == 1) { return 1; }
		memset(dis, 0x1f, sizeof(dis));
		for(i = 0; i < a.size(); ++i)
		{
			dis[a[i] - 1][b[i] - 1] = len[i];
			dis[b[i] - 1][a[i] - 1] = len[i];
		}
		for(k = 0; k < n; ++k)
		{
			for(i = 0; i < n; ++i)
			{
				for(j = 0; j < n; ++j)
				{
					dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
		for(i = 1; i <= (1 << n); ++i)
		{
			getDots(i, dots);
			if(satisfy(dots))
			{
				ret = std::max(ret, int(dots.size()));
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
	void test_case_0() { int Arg0 = 4; int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(0, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {1,2,3,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,5,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,1,3,2,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(1, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arr1[] = {1,1,1,1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,5,6,7,8,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 9; verify_case(2, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(3, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3)); }
	//void test_case_4() { int Arg0 = 1; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(4, Arg4, maxCities(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Egalitarianism3Easy ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
