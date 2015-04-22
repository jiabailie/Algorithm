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

ll gcd(ll a, ll b)
{
	if(a < b) { return gcd(b, a); }
	ll c = 0;
	while(b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

ll lcm(ll a, ll b)
{
	return (a / gcd(a, b)) * b;
}

class ThePermutationGameDiv2
{
public:
    long long findMin(int N)
    {
        ll ret = 1;
		for(ll i = 1; i <= N; ++i)
		{
			ret = lcm(ret, i);
		}
		return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 2LL; verify_case(0, Arg1, findMin(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 6LL; verify_case(1, Arg1, findMin(Arg0)); }
	void test_case_2() { int Arg0 = 6; long long Arg1 = 60LL; verify_case(2, Arg1, findMin(Arg0)); }
	void test_case_3() { int Arg0 = 11; long long Arg1 = 27720LL; verify_case(3, Arg1, findMin(Arg0)); }
	void test_case_4() { int Arg0 = 25; long long Arg1 = 26771144400LL; verify_case(4, Arg1, findMin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ThePermutationGameDiv2 ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
