/* References: www.codechef.com/NOV13/problems/MCHAIRS/
 * C(0,n)+C(1,n)+C(2,n)+...+C(n.n)=2^n
 * (1+x)^n=C(0.n)+C(1,n)x+C(2,n)x^2+C(3,n)x^3+…+C(n,n)x^n
 */
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;	

const ll x = 1000000007;

ll r[33];
ll b[33];

inline ll ipow(ll base, int p)
{
	ll res = 1;
	while(p > 1)
	{
		int i = 32;
		for(i = 32; i > 0 && p > 1; i--)
		{
			if(b[i] <= p)
			{
				p -= b[i];
				res = (res * r[i]) % x;
				i += 1;
			}
		}
	}
	if(p == 1) { res = (res * 2) % x; }

	return res;
}

int main()
{
	int t = 0;
	int i = 0;
	ll n = 0;
	ll res = 1;

	memset(r, 1, sizeof(r));
	r[1] = 4;
	b[1] = 2;
	for(i = 2; i < 33; i++)
	{
		r[i] = (r[i - 1] * r[i - 1]) % x;
		b[i] = b[i - 1] * 2;
	}

	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%lld", &n);
		
		res = (ipow(2, n) + x - 1) % x;

		printf("%lld\n", res);
	}
	
	return 0;
}
