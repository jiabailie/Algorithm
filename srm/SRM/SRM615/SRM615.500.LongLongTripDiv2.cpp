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

class LongLongTripDiv2
{
public:
    string isAble(long long D, int T, int B)
    {
        ll div = D / ll(B);
        ll mod = D % ll(B); 

        ll ini = div + mod;

        while(ini <= T)
        {
            if(ini == T)
            {
                return "Possible";
            }
            div -= 1;
            ini += B - 1;
            if(div < 0)
            {
                return "Impossible";
            }
        }
        return "Impossible";
    }
    
// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { long long Arg0 = 10LL; int Arg1 = 6; int Arg2 = 3; string Arg3 = "Possible"; verify_case(0, Arg3, isAble(Arg0, Arg1, Arg2)); }
    void test_case_1() { long long Arg0 = 10LL; int Arg1 = 5; int Arg2 = 3; string Arg3 = "Impossible"; verify_case(1, Arg3, isAble(Arg0, Arg1, Arg2)); }
    void test_case_2() { long long Arg0 = 50LL; int Arg1 = 100; int Arg2 = 2; string Arg3 = "Impossible"; verify_case(2, Arg3, isAble(Arg0, Arg1, Arg2)); }
    void test_case_3() { long long Arg0 = 120LL; int Arg1 = 10; int Arg2 = 11; string Arg3 = "Impossible"; verify_case(3, Arg3, isAble(Arg0, Arg1, Arg2)); }
    void test_case_4() { long long Arg0 = 10LL; int Arg1 = 10; int Arg2 = 9999; string Arg3 = "Possible"; verify_case(4, Arg3, isAble(Arg0, Arg1, Arg2)); }
    void test_case_5() { long long Arg0 = 1000LL; int Arg1 = 100; int Arg2 = 10; string Arg3 = "Possible"; verify_case(5, Arg3, isAble(Arg0, Arg1, Arg2)); }
    void test_case_6() { long long Arg0 = 1000010000100001LL; int Arg1 = 1100011; int Arg2 = 1000000000; string Arg3 = "Possible"; verify_case(6, Arg3, isAble(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
    LongLongTripDiv2 ___test;
    for(int i = 0; i < 7; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
