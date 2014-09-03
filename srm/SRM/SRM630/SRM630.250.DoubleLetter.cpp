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

class DoubleLetter
{
public:
    string ableToSolve(string S)
    {
		stack<char> istack;
		bool possible = false;
		bool ischange = true;
		while(ischange)
		{
			ischange = false;
			if(S.length() == 0)
			{
				possible = true;
				break;
			}
			else if(S.length() == 1)
			{
				break;
			}
			istack.push(S[0]);
			for(int i = 1; i < S.length(); ++i)
			{
				if(!istack.empty() && S[i] == istack.top())
				{
					ischange = true;
					istack.pop();
				}
				else
				{
					istack.push(S[i]);
				}
			}
			if(istack.empty())
			{
				possible = true;
				break;
			}
			S.clear();
			while(!istack.empty())
			{
				S.push_back(istack.top());
				istack.pop();
			}
		}
		return possible ? "Possible" : "Impossible";
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aabccb"; string Arg1 = "Possible"; verify_case(0, Arg1, ableToSolve(Arg0)); }
	void test_case_1() { string Arg0 = "aabccbb"; string Arg1 = "Impossible"; verify_case(1, Arg1, ableToSolve(Arg0)); }
	void test_case_2() { string Arg0 = "abcddcba"; string Arg1 = "Possible"; verify_case(2, Arg1, ableToSolve(Arg0)); }
	void test_case_3() { string Arg0 = "abab"; string Arg1 = "Impossible"; verify_case(3, Arg1, ableToSolve(Arg0)); }
	void test_case_4() { string Arg0 = "aaaaaaaaaa"; string Arg1 = "Possible"; verify_case(4, Arg1, ableToSolve(Arg0)); }
	void test_case_5() { string Arg0 = "aababbabbaba"; string Arg1 = "Impossible"; verify_case(5, Arg1, ableToSolve(Arg0)); }
	void test_case_6() { string Arg0 = "zzxzxxzxxzzx"; string Arg1 = "Possible"; verify_case(6, Arg1, ableToSolve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DoubleLetter ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
