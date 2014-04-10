#include <stdio.h>

int main()
{
	int t = 0, l = 0, r = 0;
	int i = 0, j = 0, k = 0;

	scanf("%d", &t);

	for(i = 0; i < t; ++i)
	{
		scanf("%d %d", &l, &r);
		j = 0;
		k = 0;

		while(l != r)
		{
			while(l > r)
			{
				l >>= 1;
				j += 1;
			}
			while(r > l)
			{
				r >>= 1;
				k += 1;
			}
		}

		printf("%d\n", j + k);
	}

	return 0;
}