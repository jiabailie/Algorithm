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

bool used[110];
vector<int> missed;
vector<int> pos;

int cal(vector<int>& seq)
{
	int ret = 0;
	int i = 0, j = 0;
	for(i = 0; i < seq.size(); ++i)
	{
		for(j = 0; j < i; ++j)
		{
			if(seq[j] < seq[i])
			{
				ret += 1;
			}
		}
	}
	return ret;
}

class SortishDiv2
{
public:
    int ways(int sortedness, vector <int> seq)
    {
        int i = 0, ret = 0;
		memset(used, 0, sizeof(used));
		missed.clear();
		pos.clear();
		for(i = 0; i < seq.size(); ++i)
		{
			used[seq[i]] = true;
			if(seq[i] == 0)
			{
				pos.push_back(i);
			}
		}
		for(i = 1; i <= seq.size(); ++i)
		{
			if(!used[i])
			{
				missed.push_back(i);
			}
		}
		sort(missed.begin(), missed.end());
		if(missed.size() == 0 && cal(seq) == sortedness)
		{
			return 1;
		}
		do
		{
			for(i = 0; i < pos.size(); ++i)
			{
				seq[pos[i]] = missed[i];		
			}
			if(cal(seq) == sortedness)
			{
				ret += 1;
			}
		}while(next_permutation(missed.begin(), missed.end()));
		return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {4, 0, 0, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, ways(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, ways(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, ways(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {1, 2, 0, 5, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, ways(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SortishDiv2 ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
