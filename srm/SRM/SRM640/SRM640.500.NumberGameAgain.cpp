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

class NumberGameAgain
{
public:
    long long solve(int k, vector<long long> table)
    {
		ll ret = 0;
        ll limit = (1LL << k);
		map<ll, int> ban;
		sort(table.begin(), table.end());
		for(int i = 0; i < table.size(); ++i)
		{
			ll tmp = table[i];
			bool judge = false;
			while(tmp != 1)
			{
				if(ban[tmp])
				{
					judge = true;
					break;
				}
				tmp >>= 1;
			}
			if(judge)
			{
				continue;
			}
			ban[table[i]] = 1;
			tmp = 1;
			while(table[i] < limit)
			{
				ret += tmp;
				tmp <<= 1;
				table[i] <<= 1;
			}
		}
		return limit - ret - 2;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; long Arr1[] = {2,4,6}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; long Arr1[] = {2,3}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { 
		//int Arg0 = 5; long Arr1[] = {}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 30LL; verify_case(2, Arg2, solve(Arg0, Arg1)); 
	}
	void test_case_3() { int Arg0 = 40; long Arr1[] = {2,4,8,16,32141531,2324577,1099511627775,2222222222,33333333333,4444444444,2135}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 549755748288LL; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { 
		//int Arg0 = 40; long Arr1[] = {}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1099511627774LL; verify_case(4, Arg2, solve(Arg0, Arg1)); 
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    NumberGameAgain ___test;
    for(int i = 0; i < 10; ++i)
    {
		if(i == 2 || i == 4) { continue; }
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
