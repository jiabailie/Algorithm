#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
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

const ll M = 1000008;
bool prime[M];

void gprime()
{
	ll i = 0, j = 0;
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = false;
	for(i = 2; i < M; ++i)
	{
		if(prime[i])
		{
			for(j = i + i; j < M; j += i)
			{
				prime[j] = false;
			}
		}
	}
}

class TheKingsFactorization
{
public:
    vector<long long> getVector(long long N, vector<long long> primes)
    {
		int i = 0;
		vector<ll> fac;
		for(i = 0; i < primes.size(); ++i)
		{
			N /= primes[i];
			fac.push_back(primes[i]);
		}
		gprime();
		while(true)
		{
			for(i = 2; i < M; ++i)
			{
				if(prime[i] && (N % i == 0))
				{
					fac.push_back(i);
					N /= i;
					break;
				}
			}
			if(N == 1 || i == M) { break; }
		}
		if(N != 1) { fac.push_back(N); }
		sort(fac.begin(), fac.end());
		return fac;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long long Arg0 = 12LL; long Arr1[] = {2, 3}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {2, 2, 3 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getVector(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 999999799000008694LL; long Arr1[] = {2, 999999937}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {2, 499999931, 999999937}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getVector(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1764LL; long Arr1[] = {2, 3, 7}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {2, 2, 3, 3, 7, 7 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getVector(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 49LL; long Arr1[] = {7}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {7, 7 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getVector(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 210LL; long Arr1[] = {2, 5}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {2, 3, 5, 7 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getVector(Arg0, Arg1)); }
	void test_case_5() { long long Arg0 = 100000LL; long Arr1[] = {2, 2, 2, 5, 5}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {2, 2, 2, 2, 2, 5, 5, 5, 5, 5 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, getVector(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheKingsFactorization ___test;
    for(int i = 0; i < 10; ++i)
    {
        ___test.run_test(i);
    }
    return 0;
}
// END CUT HERE
