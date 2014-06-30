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

const int INF = 0x7fefefef;

class ConundrumReloaded
{
public:
	int minimumLiarsLine(string a)
	{
		int n = a.size();
		int ret = INF;
		int i = 0, j = 0;
		for(i = 0; i < 2; ++i)
		{
			bool honest = (i == 0);
			bool prev = honest;
			int liars = (honest ? 0 : 1);
			for(j = 1; j <= n; ++j)
			{
				bool t = (a[j - 1] == 'H');
				if(!prev) { t = !t; }
				if(!t) { liars += 1; }
				prev = t;
			}
			ret = std::min(ret, liars);
		}
		return ret;
	}

    int minimumLiars(string answers)
    {
		int n = answers.size();
		int i = 0, j = 0;
		int qm = -1;
		int ret = INF;
		for(i = 0; i < n; ++i)
		{
			if(answers[i] == '?') { qm = i; }
		}
		if(qm == -1)
		{
			for(i = 0; i < 2; ++i)
			{
				bool honest = (i == 0);
				bool prev = honest;
				bool consistent = false;
				int liars = 0;
				for(j = 1; j <= n; ++j)
				{
					bool t = (answers[j - 1] == 'H');
					if(!prev) { t = !t; }
					if(!t) { liars += 1; }
					if(j == n) { consistent = (t == honest); }
					prev = t;
				}
				if(consistent) { ret = std::min(ret, liars); }
			}
			if(ret >= INF) { ret = -1; }
			return ret;
		}
		string curr;
		ret = 0;
		for(i = 0; i <= n; ++i)
		{
			j = (qm + i) % n;
			if(answers[j] == '?')
			{
				if(curr.size() > 0)
				{
					ret += minimumLiarsLine(curr);
				}
				curr.clear();
			}
			else
			{
				curr.push_back(answers[j]);
			}
		}
		ret = std::min(ret, INF);
		if(ret >= INF) { ret = -1; }
		return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LLH"; int Arg1 = 1; verify_case(0, Arg1, minimumLiars(Arg0)); }
	void test_case_1() { string Arg0 = "?????"; int Arg1 = 0; verify_case(1, Arg1, minimumLiars(Arg0)); }
	void test_case_2() { string Arg0 = "LHLH?"; int Arg1 = 2; verify_case(2, Arg1, minimumLiars(Arg0)); }
	void test_case_3() { string Arg0 = "??LLLLLL??"; int Arg1 = 3; verify_case(3, Arg1, minimumLiars(Arg0)); }
	void test_case_4() { string Arg0 = "LLL"; int Arg1 = -1; verify_case(4, Arg1, minimumLiars(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ConundrumReloaded ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
