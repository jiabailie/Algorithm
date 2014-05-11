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
const int l = 55;
double f[l][l][l];
class RandomGraph
{
public:
    double probability(int n, int pp)
    {
		double p = pp / 1000.0;
		memset(f, 0, sizeof(f));
		f[0][0][0] = 1;
		int i = 0, j = 0, k = 0;
		for(i = 0; i < n; ++i)
		{
			for(j = 0; j <= n; ++j)
			{
				for(k = 0; k <= n; ++k)
				{
					f[i + 1][j + 1][k] += f[i][j][k] * pow(1 - p, i);
					if(j && i > 0) { f[i + 1][j - 1][k + 1] += f[i][j][k] * pow(1 - p, i - 1) * j; }
					if(k && i > 1) { f[i + 1][j][k - 1] += f[i][j][k] * pow(1 - p, i - 2) * k; }
				}
			}
		}
		double ans = 0;
		double b = p * p * p + p * p * (1 - p) * 3;
		for(j = 0; j <= n; ++j)
		{
			for(k = 0; k <= n; ++k)
			{
				i = n - j * 1 - k * 2;
				if(i % 3 != 0 || i < 0) { continue; }
				i /= 3;
				ans += f[n][j][k] * pow(p, k) * pow(b, i);
			}
		}
		return 1 - ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 0; double Arg2 = 0.0; verify_case(0, Arg2, probability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 620; double Arg2 = 0.0; verify_case(1, Arg2, probability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 500; double Arg2 = 0.59375; verify_case(2, Arg2, probability(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 100; double Arg2 = 0.33566851611343496; verify_case(3, Arg2, probability(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 15; int Arg1 = 50; double Arg2 = 0.5686761670525845; verify_case(4, Arg2, probability(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 10; double Arg2 = 0.7494276522159893; verify_case(5, Arg2, probability(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 50; int Arg1 = 1000; double Arg2 = 1.0; verify_case(6, Arg2, probability(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
    RandomGraph ___test;
    for(int i = 2; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
