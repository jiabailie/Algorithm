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

class MountainRanges
{
public:
    int countPeaks(vector <int> heights)
    {
		int i = 0;
        int peak = 0;
		vector<int> p;
		p.push_back(-1);
		for(i = 0; i < heights.size(); ++i)
		{
			p.push_back(heights[i]);
		}
		p.push_back(-1);
		for(i = 1; i < p.size() - 1; ++i)
		{
			if(p[i] > p[i - 1] && p[i] > p[i + 1])
			{
				peak += 1;
			}
		}
		return peak;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 6, 2, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, countPeaks(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, countPeaks(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, countPeaks(Arg0)); }
	void test_case_3() { int Arr0[] = {2,5,3,7,2,8,1,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, countPeaks(Arg0)); }
	void test_case_4() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, countPeaks(Arg0)); }
	void test_case_5() { int Arr0[] = {1,2,3,4,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, countPeaks(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    MountainRanges ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
