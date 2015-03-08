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

vector<string> replaceVec(char cr, vector<string> &str)
{
	char c = 0;
	vector<string> vec;
	for(int i = 0; i < str.size(); ++i)
	{
		string tmp;
		for(int j = 0; j < str[i].size(); ++j)
		{
			c = str[i][j];
			if(c == '?')
			{
				c = cr;
			}
			tmp.push_back(c);
		}
		vec.push_back(tmp);
	}
	return vec;
}

int calmin(int pos, vector<string> &vmin, vector<string> &vmax)
{
	int i = 0;
	vector<string> vec(vmax.begin(), vmax.end());
	vec[pos] = vmin[pos];
	sort(vec.begin(), vec.end());
	for(i = 0; i < vec.size(); ++i)
	{
		if(vec[i] == vmin[pos])
		{
			return i;
		}
	}
	return -1;
}

class LostCharacter
{
public:
    vector <int> getmins(vector <string> str)
    {
		vector<int> vec;
		vector<string> vmin = replaceVec('a', str);
		vector<string> vmax = replaceVec('z', str);
		for(int i = 0; i < str.size(); ++i)
		{
			vec.push_back(calmin(i, vmin, vmax));
		}
		return vec;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"abc","bcd","cde","cdf","bbc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 3, 4, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getmins(Arg0)); }
	void test_case_1() { string Arr0[] = {"?ala","ara","baba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getmins(Arg0)); }
	void test_case_2() { string Arr0[] = {"a?","a","a","ab","aa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0, 0, 3, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getmins(Arg0)); }
	void test_case_3() { string Arr0[] = {"s?nu?ke","sm??eke","?sna?ke","so?th?e","shake??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 2, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getmins(Arg0)); }
	void test_case_4() { string Arr0[] = {"?","z?","zz?","zzz?","zzzz?","zzzzz?","zzzzzz?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 4, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getmins(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    LostCharacter ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
