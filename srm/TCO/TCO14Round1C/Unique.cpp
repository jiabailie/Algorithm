#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <climits>
using namespace std;
typedef long long ll;
class Unique
{
public:
    string removeDuplicates(string S)
    {
        string ret;
        bool used[26];
        memset(used, 0, sizeof(used));
        for(int i = 0; i < int(S.size()); ++i)
        {
            if(used[S[i] - 'a']) { continue; }
            ret.push_back(S[i]);
            used[S[i] - 'a'] = true;
        }
        return ret;
    }
    
// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "banana"; string Arg1 = "ban"; verify_case(0, Arg1, removeDuplicates(Arg0)); }
    void test_case_1() { string Arg0 = "aardvark"; string Arg1 = "ardvk"; verify_case(1, Arg1, removeDuplicates(Arg0)); }
    void test_case_2() { string Arg0 = "xxxxx"; string Arg1 = "x"; verify_case(2, Arg1, removeDuplicates(Arg0)); }
    void test_case_3() { string Arg0 = "topcoder"; string Arg1 = "topcder"; verify_case(3, Arg1, removeDuplicates(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
    Unique ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
