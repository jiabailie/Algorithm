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
typedef unsigned long long ll;
using namespace std;
const int N = 1000005;
int n = 0;
char buffer[N];
char v[5] = {'a', 'e', 'i', 'o', 'u'};
inline ll solve()
{
	ll c = 0, len = strlen(buffer);
	ll res = 0;
	ll i = 0, j = 0, k = 0;
	for(i = 0; i < len; ++i)
	{
		c = c + 1;
		for(j = 0; j < 5; ++j)
		{
			if(buffer[i] == v[j])
			{
				c = 0;
				break;
			}
		}
		if(c >= n)
		{
			res += (len - i) * (i - n - k + 2);
			k = i - n + 2;
		}
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
		memset(buffer, 0, sizeof(buffer));
        fscanf(in, "%s %d", &buffer, &n);
        fprintf(out, "Case #%d: %llu\n", (i + 1), solve());
    }

    fclose(out);
    fclose(in);

    return 0;
}