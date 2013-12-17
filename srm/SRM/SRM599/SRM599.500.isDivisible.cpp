#include <cstdio>
#include <map>
#include <iostream>
#include <cstring>
typedef long long ll;

using namespace std;

map<ll, ll> primeFactors(int x)
{
	map<ll, ll> ret;
	for(int p = 2; p * p <= x; p++)
	{
		if(x % p == 0)
		{
			ll r = 0;
			while(x % p == 0)
			{
				x /= p;
				r++;
			}
			ret[p] = r;
		}
	}
	if(x != 1)
	{
		ret[x] = 1;
	}
	return ret;
}

string isDivisible(int A, int B, int C, int D)
{
	map<ll, ll> ap = primeFactors(A);
	map<ll, ll> cp = primeFactors(C);

	for(map<ll, ll>::iterator it = cp.begin(); it != cp.end(); it++)
	{
		if(it->second * D > ap[it->first] * B)
		{
			return "not divisible";
		}
	}

	return "divisible";
}

int main()
{
	int A = 0, B = 0;
	int C = 0, D = 0;

	cin >> A >> B >> C >> D;
	cout << isDivisible(A, B, C, D).c_str() << endl;

	return 0;
}
