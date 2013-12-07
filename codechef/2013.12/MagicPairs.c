#include <stdio.h>
 
typedef long long ll;
 
int main()
{
	ll t = 0, n = 0, ret = 0;
	int i = 0, j = 0, k = 0;
 
	scanf("%lld", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%lld", &n);
		for(j = 0; j < n; j++)
		{
			scanf("%d", &k);
		}
 
		if(n & 1)
		{
			ret = n * ((n - 1) >> 1);
		}
		else
		{
			ret = (n >> 1) * (n - 1);
		}
		printf("%lld\n", ret);
	}
 
	return 0;
} 