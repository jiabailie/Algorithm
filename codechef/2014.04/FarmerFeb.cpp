#include <stdio.h>

bool isprime(int x)
{
	if(x == 2) { return true; }
	for(int i = 2; i * i <= x; ++i)
	{
		if(x % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int t = 0;
	int i = 0, r = 0;
	int f = 0, s = 0;

	scanf("%d", &t);
	for(i = 0; i < t; ++i)
	{
		scanf("%d %d", &f, &s);

		for(r = 1; ; ++r)
		{
			if(isprime(r + f + s))
			{
				printf("%d\n", r);
				break;
			}
		}
	}
	return 0;
}