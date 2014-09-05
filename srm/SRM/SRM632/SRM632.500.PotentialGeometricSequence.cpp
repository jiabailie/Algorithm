#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
typedef long long ll;
class PotentialGeometricSequence
{
public:
    int numberOfSubsequences(vector <int> d)
    {
		if(d.size() == 1) { return 1; }
		if(d.size() == 2) { return 3; }
		int i = 0, j = 0, c = 0;
		int ret = d.size() + d.size() - 1;
		vector<int> m;
		for(i = 1; i < d.size(); ++i)
		{
			m.push_back(d[i] - d[i - 1]);
		}
		c = 1;
		for(i = 1; i < m.size(); ++i)
		{
			if(m[i] == m[i - 1])
			{
				c += 1;
			}
			else
			{
				for(j = c + 1; j > 2; --j)
				{
					ret += j - 2;
				}
				c = 1;
			}
		}
		for(j = c + 1; j > 2; --j)
		{
			ret += j - 2;
		}
		return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_2() { int Arr0[] = {3,2,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,4,8,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(3, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_4() { int Arr0[] = {1,3,5,5,5,5,64,4,23,2,3,4,5,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 37; verify_case(4, Arg1, numberOfSubsequences(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
    PotentialGeometricSequence ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
