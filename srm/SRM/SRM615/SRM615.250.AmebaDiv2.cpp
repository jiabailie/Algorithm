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

#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr << #x << " " << x << endl
#define se(x) cerr << " " << x 
#define pb push_back

class AmebaDiv2
{
public:
    int simulate(vector <int> X, int A)
    {
        ll res = A;
        for(int i = 0; i < sz(X); ++i)
        {
            if(res == X[i])
            {
                res <<= 1;
            }
        }
        return int(res);
    }
    
// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {2,1,3,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; verify_case(0, Arg2, simulate(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {1,4,9,16,25,36,49}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 10; verify_case(1, Arg2, simulate(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {1,2,4,8,16,32,64,128,256,1024,2048}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 512; verify_case(2, Arg2, simulate(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {817,832,817,832,126,817,63,63,126,817,832,287,823,817,574}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 63; int Arg2 = 252; verify_case(3, Arg2, simulate(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
    AmebaDiv2 ___test;
    for(int i = 0; i < 4; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
