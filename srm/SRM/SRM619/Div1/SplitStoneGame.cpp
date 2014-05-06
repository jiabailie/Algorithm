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

class SplitStoneGame
{
public:
    string winOrLose(vector <int> number)
    {
		sort(number.begin(), number.end());
		int n = number.size();
		// If there are only 2 or 1 piles of stones, the first player will lose.
		// If any pile can not be split into two parts, the first player will lose.
		if(n <= 2 || number[n - 1] == 1) { return "LOSE"; }
		// If the amount of piles is more than 2 and is an even number, the first player will lose.
		// Since the amount of piles will decrease by 1 after each turn, so the first player will have no piles to split.
		if(n % 2 == 0) { return "LOSE"; }
		return "WIN";
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(0, Arg1, winOrLose(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(1, Arg1, winOrLose(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN"; verify_case(2, Arg1, winOrLose(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 1, 4, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN"; verify_case(3, Arg1, winOrLose(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(4, Arg1, winOrLose(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SplitStoneGame ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
