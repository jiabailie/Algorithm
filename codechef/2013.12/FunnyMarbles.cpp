#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

int cur = -1;
int o[2010], ov[2010];
ll sum[1000001];
ll own[1000001];

inline ll gsum(int p)
{
	ll ret = sum[p];
	for(int i = 0; i <= cur; i++)
	{
		if(o[i] <= p)
		{
			ret += ov[i];
		}
	}
	return ret;
}

int main()
{
	char c;
	int i = 0, j = 0;
	int n = 0, q = 0;
	int x = 0, y = 0;

	memset(o, 0, sizeof(o));
	memset(ov, 0, sizeof(ov));
	
	scanf("%d %d", &n, &q);
	for(i = 1; i <= n; i++)
	{
		scanf("%lld", &own[i]);		
	}
	for(i = 1; i <= n; i++)
	{
		sum[i] = own[i] + sum[i -1];
	}
	for(i = 0; i < q; i++)
	{
		getchar();
		scanf("%c %d %d", &c, &x, &y);
		x++;
		if(c == 'S')
		{
			y++;
			printf("%lld\n", gsum(y) - gsum(x - 1));
		}
		else if(c == 'G')
		{
			cur++;
			o[cur] = x;
			ov[cur] = y;
		}
		else if(c == 'T')
		{
			cur++;
			o[cur] = x;
			ov[cur] = -y;
		}		
	}
	return 0;
}