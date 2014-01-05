#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

struct chest
{
	int t;
	int k;
	vector<int> keys;
};

int main()
{
	int t = 0;
	int k = 0, n = 0;
	int i = 0, j = 0, m = 0;
	int tmp = 0;
	int keys[400];
	vector<chest> chests;

	FILE* in = freopen("E:\\Practice\\GCJ\\file\\D.in", "r", stdin);
	FILE* out = freopen("E:\\Practice\\GCJ\\file\\D.out", "w", stdout);

	fscanf(in, "%d", &t);

	for(i = 0; i < t; i++)
	{
		fscanf(in, "%d %d", &k, &n);
		for(j = 0; j < k; j++)
		{
			fscanf(in, "%d", &keys[j]);
		}
		for(j = 0; j < n; j++)
		{
			chest c;
			fscanf(in, "%d %d", &(c.t), &(c.k));
			for(m = 0; m < c.k; m++)
			{
				fscanf(in, "%d", &tmp);
				c.keys.push_back(tmp);
			}
			chests.push_back(c);
		}
		//fprintf(out, "Case #%d: %s\n", (i + 1), re);
	}

	fclose(out);
	fclose(in);
	return 0;
}