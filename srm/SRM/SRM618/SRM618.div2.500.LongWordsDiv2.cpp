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
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair
typedef long long LL;

class LongWordsDiv2
{
public:
        string find(string word)
        {
            int i = 0, j = 0;
            int m = 0, n = 0;
            int len = int(word.length());
            for(i = 1; i < len; ++i)
            {
                if(word[i] == word[i - 1])
                {
                    return "Dislikes";
                }
            }
            for(i = 0; i < len - 3; ++i)
            {
                if(i + 1 < len)
                {
                    for(j = i + 1; j < len - 2; ++j)
                    {
                        if(j + 1 < len)
                        {
                            for(m = j + 1; m < len - 1; ++m)
                            {
                                if(m + 1 < len)
                                {
                                    for(n = m + 1; n < len; ++n)
                                    {
                                        if(word[i] == word[m] && word[j] == word[n])
                                        {
                                            return "Dislikes";
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return "Likes";
        }
// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "A"; string Arg1 = "Likes"; verify_case(0, Arg1, find(Arg0)); }
    void test_case_1() { string Arg0 = "ABCBA"; string Arg1 = "Likes"; verify_case(1, Arg1, find(Arg0)); }
    void test_case_2() { string Arg0 = "ABCBAC"; string Arg1 = "Dislikes"; verify_case(2, Arg1, find(Arg0)); }
    void test_case_3() { string Arg0 = "TOPCODER"; string Arg1 = "Likes"; verify_case(3, Arg1, find(Arg0)); }
    void test_case_4() { string Arg0 = "VAMOSGIMNASIA"; string Arg1 = "Dislikes"; verify_case(4, Arg1, find(Arg0)); }
    void test_case_5() { string Arg0 = "SINGLEROUNDMATCH"; string Arg1 = "Likes"; verify_case(5, Arg1, find(Arg0)); }
    void test_case_6() { string Arg0 = "DALELOBO"; string Arg1 = "Likes"; verify_case(6, Arg1, find(Arg0)); }
// END CUT HERE
};

// BEGIN CUT HERE
int main()
{
    LongWordsDiv2 ___test;

    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }

    return 0;
}
// END CUT HERE
