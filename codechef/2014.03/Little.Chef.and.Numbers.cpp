#include <cstdio>

using namespace std;

typedef long long ll;

ll comb2(ll a)
{
	ll p = a;
	ll q = a - 1;
	if(a & 1)
	{
		q >>= 1;
	}
	else
	{
		p >>= 1;
	}
	return p * q;
}

ll solve()
{
	int i = 0;
	int n = 0;
	int tmp = 0;
	int rec[3] = {0, 0, 0};
	ll inclusive[3] = {0, 0, 0};
	scanf("%d", &n);
	for(i = 0; i < n; ++i)
	{
		scanf("%d", &tmp);
		if(tmp < 3)
		{
			rec[tmp] += 1;
		}
	}
	ll total = comb2(ll(n));
	if(rec[0])
	{
		inclusive[0] = comb2(ll(rec[0])) + ll(rec[0]) * ll(n - rec[0]);
	}
	if(rec[1])
	{
		inclusive[1] = comb2(ll(rec[1])) + ll(rec[1]) * ll(n - rec[0] - rec[1]);
	}
	if(rec[2])
	{
		inclusive[2] = comb2(ll(rec[2]));
	}
	for(i = 0; i < 3; ++i)
	{
		total -= inclusive[i];
	}

	return total;
}

int main()
{
	int i = 0;
	int t = 0;
	scanf("%d", &t);
	for(i = 0; i < t; ++i)
	{
		printf("%lld", solve());
	}
	return 0;
}