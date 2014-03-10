#include <stdio.h>

int imax(int a, int b)
{
	return a > b ? a : b;
}

int walk()
{
	int i = 0;
	int t = 0;
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = n;

	for(i = 0; i < n; ++i)
	{
		scanf("%d", &t);
		ret = imax(ret, t + i);
	}

	return ret;
}

int main()
{
	int i = 0;
	int t = 0;
	scanf("%d", &t);
	for(i = 0; i < t; ++i)
	{
		printf("%d\n", walk());
	}
	return 0;
}