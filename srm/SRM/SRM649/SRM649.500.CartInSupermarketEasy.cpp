#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <numeric>
#include <iostream>
#include <climits>
#define SORT(X) sort(X.begin(), X.end())
#define SIZE(X) static_cast<int>(X.size())
using namespace std;
typedef long long ll;

const int n = 102;
const int k = 102;
int dp[n][k];

class CartInSupermarketEasy
{
public:
    int calc(int N, int K)
    {
		memset(dp, 0,sizeof(dp));
		int i = 0, j = 0;
		int m = 0, n = 0;
		int t = 0;
		if(N == 0) { return 0; }
		if(K == 0) { return N; }
		if(N == 1) { return 1; }
		for(i = 0; i <= N; dp[i][0] = i, ++i);
		for(i = 0; i <= K; dp[0][i] = 0, dp[1][i] = 1, ++i);

		// split i items at most j times
		for(i = 2; i <= N; ++i)
		{
			for(j = 0; j <= K; ++j)
			{
				t = -1;
				dp[i][j] = std::min(i, dp[i - 1][j] + 1);
				for(m = 1; m < i; ++m)
				{					
					for(n = 0; n < j; ++n)
					{
						// using std::max: since the split (i,j) into two parts, it costs the longer one, it is a whole process.
						t = std::max(dp[m][n], dp[i - m][j - n - 1]) + 1;
						dp[i][j] = std::min(dp[i][j], t);
					}					
				}
			}
		}
		return dp[N][K];
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 5; verify_case(0, Arg2, calc(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 4; verify_case(1, Arg2, calc(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 4; int Arg2 = 6; verify_case(2, Arg2, calc(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 100; int Arg2 = 4; verify_case(3, Arg2, calc(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 45; int Arg1 = 5; int Arg2 = 11; verify_case(4, Arg2, calc(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 8; verify_case(5, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    CartInSupermarketEasy ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
