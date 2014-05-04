#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;
const int N = 1000005;
int n = 0;
int conse[N];
char buffer[N];
char v[5] = {'a', 'e', 'i', 'o', 'u'};
inline void init()
{
	int i = 0, j = 0;
	for(i = 0; i < strlen(buffer); ++i)
	{
		for(j = 0; j < 5; ++j)
		{
			if(buffer[i] == v[j])
			{
				conse[i] = 0;
				break;
			}
		}
		if(j == 5)
		{
			if(i == 0) { conse[i] = 1; }
			else
			{
				conse[i] = conse[i - 1] + 1;
			}
		}
	}
}
inline ll solve()
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	ll res = 0;
	ll len = strlen(buffer);
	for(i = 0; i < len; ++i)
	{
		tmp = 0;
		j = i;
		if(conse[i] != 0)
		{
			for(j = i; j < len && conse[j] != 0 && tmp - conse[i] + 1 != n; tmp = conse[j], ++j);
			tmp = tmp - conse[i] + 1;
		}
		for(; j < len && tmp != n; ++j)
		{
			if(conse[j] > tmp)
			{
				tmp = conse[j];
			}
		}
		if(tmp < n) { break; }
		res += len - j + 1;
	}
	return res;
}
int main()
{
    int t = 0;       
    int i = 0;

    FILE* in = freopen("E:/Projects/lab/lab/file/A-large-practice.in", "r", stdin);
    FILE* out = freopen("E:/Projects/lab/lab/file/A-large-practice.out", "w", stdout);

    fscanf(in, "%d", &t);

    for(i = 0; i < t; i++)
    {
		memset(conse, 0, sizeof(conse));
		memset(buffer, 0, sizeof(buffer));
        fscanf(in, "%s %d", &buffer, &n);
		init();
        fprintf(out, "Case #%d: %lld\n", (i + 1), solve());
    }

    fclose(out);
    fclose(in);

    return 0;
}