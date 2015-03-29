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

int gm = INT_MAX;
int gn = 0;
string gs;

int calc(string s)
{
	int ret = 0;
	for(int i = 0; i < gn - 1; ++i)
	{
		if(s[i] == s[i + 1])
		{
			ret += 1;
		}
	}
	return ret;
}

void step(int cur, string s)
{
	if(cur == gn)
	{
		int u = calc(s);
		if(u < gm) 
		{ 
			gm = u; 
		}
		return;
	}
	if(gs[cur] != '?') { step(cur + 1, s); return; }
	int z = -1;
	// head
	if(cur == 0 && s[cur + 1] != '?') { z = cur + 1; }
	// tail
	if(cur == gn - 1 && s[cur - 1] != '?') { z = cur - 1; }
	// middle
	if(cur > 0 && cur < gn - 1) { z = cur - 1; }
	if(z != -1)
	{
		s[cur] = s[z] == 'A' ? 'B' : 'A';
		step(cur + 1, s);
		return;
	}
	s[cur] = 'A';
	step(cur + 1, s);
	s[cur] = 'B';
	step(cur + 1, s);
}

class TaroFillingAStringDiv2
{
public:
    int getNumber(string S)
    {
		gm = INT_MAX;
		gs = S;
		gn = SIZE(S);
		step(0, S);
		return gm;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABAA"; int Arg1 = 1; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arg0 = "??"; int Arg1 = 0; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arg0 = "A?A"; int Arg1 = 0; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arg0 = "A??B???AAB?A???A"; int Arg1 = 3; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arg0 = "?BB?BAAB???BAB?B?AAAA?ABBA????A?AAB?BBA?A?"; int Arg1 = 10; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TaroFillingAStringDiv2 ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
