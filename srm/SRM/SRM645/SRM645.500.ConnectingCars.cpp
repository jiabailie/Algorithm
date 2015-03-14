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
#include <climits>
using namespace std;
typedef long long ll;

class ConnectingCars
{
public:
	ll move(int x, vector<pair<ll, ll> > pos)
	{
		int i = 0;
		ll ret = 0;
		ll offset = 0;
		for (i = x - 1; i >= 0; --i)
		{
			offset = pos[i + 1].first - pos[i].second;
			ret += offset;
			pos[i].second += offset;
			pos[i].first += offset;
		}
		for (i = x + 1; i < pos.size(); ++i)
		{
			offset = pos[i].first - pos[i - 1].second;
			ret += offset;
			pos[i].first -= offset;
			pos[i].second -= offset;
		}
		return ret;
	}
    long long minimizeCost(vector <int> positions, vector <int> lengths)
    {
		int i = 0;
		int n = positions.size();
		ll ret = LLONG_MAX;
		ll tmp = LLONG_MAX;
		vector<pair<ll, ll> > pos;		
		for (i = 0; i < n; ++i)
		{
			pos.push_back(make_pair(ll(positions[i]), ll(positions[i]) + ll(lengths[i])));
		}
		sort(pos.begin(), pos.end());
		for (i = 0; i < n; ++i)
		{
			tmp = move(i, pos);
			if (tmp < ret)
			{
				ret = tmp;
			}
		}
		return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 3, 10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 5, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 15LL; verify_case(0, Arg2, minimizeCost(Arg0, Arg1)); }
	void test_case_1() {
		int Arr0[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 900000001, 900000002, 900000003, 900000004, 900000005, 900000006, 900000007, 900000008, 900000009, 900000010, 900000011, 900000012, 900000013, 900000014, 900000015, 900000016, 900000017, 900000018, 900000019, 900000020, 900000021, 900000022, 900000023, 900000024, 900000025 }; 
		vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1000000000 }; 
		vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 21599999424ll; verify_case(1, Arg2, minimizeCost(Arg0, Arg1));
	}
	void test_case_2() { int Arr0[] = {4, 10, 100, 13, 80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 3, 42, 40, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 66LL; verify_case(2, Arg2, minimizeCost(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5606451, 63581020, 81615191, 190991272, 352848147, 413795385, 468408016, 615921162, 760622952, 791438427}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {42643329, 9909484, 58137134, 99547272, 39849232, 15146704, 144630245, 604149, 15591965, 107856540}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1009957100LL; verify_case(3, Arg2, minimizeCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ConnectingCars ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
