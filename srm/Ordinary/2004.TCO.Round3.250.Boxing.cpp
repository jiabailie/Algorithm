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

map<int, int> paramArray;

int getOneAmount(int value)
{
	int oneAmount = 0;
	while(value)
	{
		oneAmount += 1;
		value &= (value - 1);
	}
	return oneAmount;
}

void setValue(int value, vector<int> &dataSet)
{
	for(vector<int>::iterator it = dataSet.begin(); it != dataSet.end(); ++it)
	{
		if(paramArray.find(*it) != paramArray.end())
		{
			paramArray[(*it)] |= value;
		}
		else
		{
			paramArray[(*it)] = value;
		}
	}
}

class Boxing
{
public:
	int maxCredit(vector<int> a, vector<int> b, vector<int> c, vector<int> d, vector<int> e)
	{
		int maxInterval = 0;
		paramArray.clear();

		setValue(1, a);
		setValue(2, b);
		setValue(4, c);
		setValue(8, d);
		setValue(16, e);

		int tmpJudgePressed = 0;		

		for(map<int, int>::iterator itPos = paramArray.begin(), startTime = paramArray.begin(); itPos != paramArray.end(); ++itPos)
		{
			if(tmpJudgePressed == 0)
			{
				startTime = itPos;
			}
			if(itPos->first - startTime->first + 1 > 1000)
			{
				itPos = startTime;
				tmpJudgePressed = 0;
				continue;
			}
			tmpJudgePressed |= itPos->second;
			
			if(getOneAmount(tmpJudgePressed) >= 3)
			{
				tmpJudgePressed = 0;
				maxInterval += 1;
			}
		}

		return maxInterval;
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,1,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1,2,3,4,5,6,7,8}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 6; verify_case(0, Arg5, maxCredit(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {100,200,300,1200,6000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {900,902,1200,4000,5000,6001}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,2000,6002}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1,2,3,4,5,6,7,8}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 3; verify_case(1, Arg5, maxCredit(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {5000,6500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0,5800,6000}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1; verify_case(2, Arg5, maxCredit(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Boxing ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
