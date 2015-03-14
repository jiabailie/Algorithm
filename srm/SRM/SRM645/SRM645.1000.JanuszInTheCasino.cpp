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
typedef pair<ll, int> pi;
map<pi, double> mpd;

class JanuszInTheCasino
{
public:
	double eval(ll n, int m, int k)
	{
		if (k == 0)
		{
			return (n > 0ll ? 1.0 : 0.0);
		}
		pi p = make_pair(n, k);
		// split n into m buckets, ((n / m), (n / m), ..., (n / m), ((n / m) + 1), ..., ((n / m) + 1))
		// there are a=(n % m) buckets which are filled with ((n / m) + 1)
		if (mpd.find(p) == mpd.end())
		{
			int a = int(n % m);
			double p1 = eval(n - (n / m + 1), m, k - 1); // worst case, remove (n / m + 1)
			double p2 = eval(n - (n / m), m, k - 1);     // better case, remove (n / m)
			mpd[p] = (p1 * a + p2 * (m - a)) / (m * 1.0);
		}
		return mpd[p];
	}
    double findProbability(ll n, int m, int k)
    {
		mpd.clear();
		return eval(n, m, k);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; int Arg1 = 2; int Arg2 = 2; double Arg3 = 0.75; verify_case(0, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 1LL; int Arg1 = 3; int Arg2 = 3; double Arg3 = 0.2962962962962962; verify_case(1, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 4LL; int Arg1 = 3; int Arg2 = 2; double Arg3 = 1.0; verify_case(2, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 5LL; int Arg1 = 4; int Arg2 = 5; double Arg3 = 0.87109375; verify_case(3, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 1000000000000LL; int Arg1 = 2; int Arg2 = 40; double Arg3 = 0.9094947017729282; verify_case(4, Arg3, findProbability(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    JanuszInTheCasino ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
