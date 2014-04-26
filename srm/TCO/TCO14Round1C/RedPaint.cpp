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
double mem[2][510][510];
class RedPaint
{
public:
    double expectedCells(int N)
    {
        int curr = 0, prev = 1;
        int p = 0, l = 0, r = 0;
        for(p = N; p >= 0; --p)
        {
            for(l = 0; l <= N; ++l)
            {
                for(r = 0; r <= N; ++r)
                {
                    if(p == N) { mem[curr][l][r] = 0.0; continue; }
                    mem[curr][l][r] = 0.0;
                    if(l == 0)
                    {
                        mem[curr][l][r] += 0.5 * (mem[prev][0][r + 1] + 1);
                    }
                    else
                    {
                        mem[curr][l][r] += 0.5 * mem[prev][l - 1][r + 1];
                    }
                    if(r == 0)
                    {
                        mem[curr][l][r] += 0.5 * (mem[prev][l + 1][0] + 1);
                    }
                    else
                    {
                        mem[curr][l][r] += 0.5 * mem[prev][l + 1][r - 1];
                    }
                }
            }
            swap(curr, prev);
        }
        return mem[prev][0][0] + 1;
    }
    
// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 0; double Arg1 = 1.0; verify_case(0, Arg1, expectedCells(Arg0)); }
    void test_case_1() { int Arg0 = 1; double Arg1 = 2.0; verify_case(1, Arg1, expectedCells(Arg0)); }
    void test_case_2() { int Arg0 = 2; double Arg1 = 2.5; verify_case(2, Arg1, expectedCells(Arg0)); }
    void test_case_3() { int Arg0 = 4; double Arg1 = 3.375; verify_case(3, Arg1, expectedCells(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
    RedPaint ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
