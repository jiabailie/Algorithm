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

class ElectronicPetEasy
{
public:
    string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2)
    {
        set<int> given;
		for(int i = 0; i < t1; ++i)
		{
			given.insert(st1 + i * p1);
		}
		for(int i = 0; i < t2; ++i)
		{
			int j = st2 + i * p2;
			if(given.find(j) != given.end())
			{
				return string("Difficult");
			}
		}
		return string("Easy");
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 3; int Arg3 = 5; int Arg4 = 2; int Arg5 = 3; string Arg6 = "Difficult"; verify_case(0, Arg6, isDifficult(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 3; int Arg3 = 5; int Arg4 = 2; int Arg5 = 2; string Arg6 = "Easy"; verify_case(1, Arg6, isDifficult(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 4; int Arg2 = 7; int Arg3 = 1; int Arg4 = 4; int Arg5 = 7; string Arg6 = "Difficult"; verify_case(2, Arg6, isDifficult(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1000; int Arg2 = 1000; int Arg3 = 2; int Arg4 = 1000; int Arg5 = 1000; string Arg6 = "Easy"; verify_case(3, Arg6, isDifficult(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; int Arg4 = 2; int Arg5 = 2; string Arg6 = "Easy"; verify_case(4, Arg6, isDifficult(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ElectronicPetEasy ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
