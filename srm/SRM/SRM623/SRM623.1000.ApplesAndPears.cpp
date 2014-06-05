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

vector<pair<int, int> > apple;
vector<pair<int, int> > pear;
vector<pair<int, int> > blank;

void find(vector<string> &b, int lx, int ly, int rx, int ry, int &ca, int &cp, int &cb, int &ra, int &rp, int &rb)
{
	for(int i = lx; i <= rx; ++i)
	{
		for(int j = ly; j <= ry; ++j)
		{
			switch(b[i][j])
			{
			case 'A':
				ca += 1;
				break;
			case 'P':
				cp += 1;
				break;
			default:
				cb += 1;
				break;
			}
		}
	}
	ra = apple.size() - ca;
	rp = pear.size() - cp;
	rb = blank.size() - cb;
}

class ApplesAndPears
{
public:
    int getArea(vector <string> board, int K)
    {
		int ret = 1;
		int i = 0, j = 0;
		int lx = 0, ly = 0;
		int rx = 0, ry = 0;
		int n = board.size();
		for(i = 0; i < n; ++i)
		{
			for(j = 0; j < n; ++j)
			{
				switch(board[i][j])
				{
				case 'A':
					apple.push_back(make_pair<int, int>(i, j));
					break;
				case 'P':
					pear.push_back(make_pair<int, int>(i, j));
					break;
				default:
					blank.push_back(make_pair<int, int>(i, j));
					break;
				}
			}
		}
		int area = 0;
		int ca = 0, cp = 0, cb = 0;
		int ra = 0, rp = 0, rb = 0;
		for(lx = 0; lx < n; ++lx)
		{
			for(ly = 0; ly < n; ++ly)
			{
				for(rx = lx; rx < n; ++rx)
				{
					for(ry = ly; ry < n; ++ry)
					{
						area = (rx - lx + 1) * (ry - ly + 1);
						if(area <= ret) { continue; }
						ca = cp = cb = 0;
						find(board, lx, ly, rx, ry, ca, cp, cb, ra, rp, rb);
						if((ca + ra >= area && area - ca <= K) || (cp + rp >= area && area - cp <= K) || (cb + rb >= area && area - cb <= K))
						{
							ret = area;
						}
					}
				}
			}
		}
		return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".A",
 "P."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, getArea(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".A",
 "P."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, getArea(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".PP", 
 "PPA", 
 "PAP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(2, Arg2, getArea(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"A.P.PAAPPA",
 "PPP..P.PPP",
 "AAP.A.PAPA",
 "P.PA.AAA.A",
 "...PA.P.PA",
 "P..A.A.P..",
 "PAAP..A.A.",
 "PAAPPA.APA",
 ".P.AP.P.AA",
 "..APAPAA.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 21; verify_case(3, Arg2, getArea(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ApplesAndPears ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
