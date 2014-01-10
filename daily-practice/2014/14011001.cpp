#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool use[100001];
bool cpy[100001];

int main()
{
	int t = 0;
	int i = 0, j = 0, s = 0;
	int n = 0, m = 0, k = 0;

	while(scanf("%d %d", &n, &m), n + m > 0)
	{
		vector<int> A;
		vector<int> C;
		memset(use, 0, sizeof(use));
		memset(cpy, 0, sizeof(cpy));

		for(i = 0; i < n; i++)
		{
			scanf("%d", &j);
			A.push_back(j);
		}
		for(i = 0; i < n; i++)
		{
			scanf("%d", &j);
			C.push_back(j);
		}
		for(i = 0; i < n; i++)
		{
			for(j = 1; j <= C[i]; j++)
			{
				k = A[i] * j;
				if(k > m)
				{
					break;
				}
				for(s = 1; s <= m; s++)
				{
					if(use[s])
					{
						cpy[s] = true;
					}
					if(s + k > m)
					{
						break;
					}
					if(use[s])
					{
						cpy[s + k] = true;
					}
				}
				cpy[k] = true;
			}
			memcpy(use, cpy, sizeof(cpy));
		}
		int cnt = 0;
		for(i = 1; i <= m; i++)
		{
			if(use[i])
			{
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}
