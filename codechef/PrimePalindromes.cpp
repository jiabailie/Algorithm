/* References : www.codechef.com/problems/PRPALIN/ */
#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <iostream>
#define scan(x) scanf("%d", &x)
#define print(x) printf("%d\n", x)

using namespace std;

set<int> iset;

const double lg10 = log(10.0);

inline int getlen(int x)
{
	if(x == 0) { return 1; }
	return (log(x * 1.0) / lg10) + 1;
}

inline bool isprime(int x)
{
	if(x < 2) { return false; }
	if(x == 2) { return true; }
	int i = 0, e = int(sqrt(x * 1.0));
	for(int i = 2; i <= e; i++)
	{
		if(x % i == 0)
		{
			return false;
		}
	}
	return true;
}

inline void solve(int len)
{
	int i = 0, j = 0;
	int m = 0, n = 0;
	int t = 0;
	
	int e[4] = {0, 0, 0, 0};
	int d[4] = {1000, 100, 10, 1};
	for(i = 0; i < (len + 1) / 2; i++)
	{
		e[i] = 9;
	}

	for(i = 0; i <= e[3]; i++)
	{
		for(j = 0; j <= e[2]; j++)
		{
			for(m = 0; m <= e[1]; m++)
			{
				for(n = 0; n <= e[0]; n++)
				{
					if(len & 1)
					{
						t = i * 1000000 + j * 100000 + m * 10000 + n * 1000 + m * 100 + j * 10 + i;
					}
					else
					{
						t = i * 10000000 + j * 1000000 + m * 100000 + n * 10000 + n * 1000 + m * 100 + j * 10 + i;
					}
					t /= d[((len - 1) >> 1)];
					if(isprime(t))
					{
						iset.insert(t);
					}					
				}
			}
		}
	}
}

int main()
{
	int n = 0;
	int l = 0;

	for(int i = 1; i <= 8; i++)
	{
		solve(i);
	}

	for(set<int>::iterator it = iset.begin(); it != iset.end(); it++)
	{
		printf("%d,", *it);
	}

	scan(n);

	l = getlen(n);
	solve(l);
	solve(l + 1);

	for(set<int>::iterator it = iset.begin(); it != iset.end(); it++)
	{
		if((*it) >= n)
		{
			print(*it);
			break;
		}
	}
	
	return 0;
}
