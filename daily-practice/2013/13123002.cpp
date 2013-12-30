#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

inline int solve(int a, int b, int n)
{
	int i = 0;
	int j = 0;
	bool flg = false;
	int loop = 0;
	int start = 0;
	int rec[128];

	rec[1] = rec[2] = 1;

	for(i = 3; i < 128 && !flg; i++)
	{
		rec[i] = (a * rec[i - 1] + b * rec[i - 2]) % 7;

		for(j = 2; j < i && !flg; j++)
		{
			if(rec[j - 1] == rec[i - 1] && rec[j] == rec[i])
			{
				start = j;
				loop = i - j;
				flg = true;
			}
		}
	}

	n = (n - start) % loop;
	return rec[start + n];	
}

int main()
{	
	int a = 0, b = 0, n = 0;

	while(scanf("%d %d %d", &a, &b, &n), (a | b | n))
	{
		printf("%d\n", solve(a, b, n));
	}

	return 0;
}
