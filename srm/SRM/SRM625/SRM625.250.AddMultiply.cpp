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

class AddMultiply
{
public:
    vector <int> makeExpression(int y)
    {
        vector<int> ret;
		for(int i = -1000; i <= 1000; ++i)
		{
			for(int j = -1000; i <= 1000; ++j)
			{
				if(i != 0 && i != 1 && j != 0 && j != 1)
				{
					int k = y - i * j;
					if(k >= -1000 && k <= 1000 && k != 0 && k != 1)
					{
						ret.push_back(i);
						ret.push_back(j);
						ret.push_back(k);
						return ret;
					}
				}
			}
		}
		return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 6; int Arr1[] = {2, 2, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, makeExpression(Arg0)); }
	void test_case_1() { int Arg0 = 11; int Arr1[] = {2, 3, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, makeExpression(Arg0)); }
	void test_case_2() { int Arg0 = 0; int Arr1[] = {7, 10, -70 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, makeExpression(Arg0)); }
	void test_case_3() { int Arg0 = 500; int Arr1[] = {-400, -3, -700 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, makeExpression(Arg0)); }
	void test_case_4() { int Arg0 = 2; int Arr1[] = {2, 2, -2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, makeExpression(Arg0)); }
	void test_case_5() { int Arg0 = 5; int Arr1[] = {5, 2, -5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, makeExpression(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    AddMultiply ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
