/*
 * References : www.codechef.com/NOV13/problems/SPOTWO/
 * Idea : Fermat's little theorem [http://en.wikipedia.org/wiki/Fermat%27s_little_theorem]
 */
#include <cstdio>

typedef unsigned long long ll;

using namespace std;

const ll mod = 1000000007;

int len = 0;
ll pow2[65];
ll rec2[65];
ll str[32];

inline void intTochar(ll x)
{
	len = 0;
	while(x > 0)
	{
		str[len] = x & 1;
		len = len + 1;
		x >>= 1;
	}
}

inline ll lowPow()
{
	int i = 0;
	ll x = 0;
	for(x = 0, i = len - 1; i >= 0; i--)
	{
		x = x * 10 + str[i];
	}
	x = x % (mod - 1); // Fermat's little theorem
	return x;
}

inline ll iPow(ll n)
{
	int i = 64;
	ll ret = 1;
	while(n > 0)
	{
		for(; i >= 0; i--)
		{
			if(n >= rec2[i])
			{
				n -= rec2[i];
				ret = (ret * pow2[i]) % mod;
				break;
			}
		}
		i = i + 1;
	}
	return ret;
}

int main()
{
	int t = 0;
	int i = 0;
	ll n = 0;

	pow2[0] = 1;
	pow2[1] = 2;

	rec2[0] = 0;
	rec2[1] = 1;

	for(i = 2; i < 65; i++)
	{
		pow2[i] = (pow2[i - 1] * pow2[i - 1]) % mod;
		rec2[i] = rec2[i - 1] << 1;
	}

	scanf("%d", &t);

	for(i = 1; i <= t; i++)
	{
		scanf("%llu", &n);
		intTochar(n);
		n = lowPow();
		n = iPow(n * 2);
		printf("%llu\n", n);		
	}
	return 0;
}
