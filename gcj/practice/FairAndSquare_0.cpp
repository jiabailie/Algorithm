#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cstdlib>
#define MAX 110

using namespace std;

int palindrome(int a)
{
	char str[MAX];
	int i = 0, j = 0;
	itoa(a, str, 10);
	for(j = strlen(str) - 1; i < j; i++, j--)
	{
		if(str[i] != str[j]) { return 0; }
	}
	return 1;
}

int main()
{
	int t = 0, k = 0;
	int a = 0, b = 0, c = 0;
	double i = 0;

	FILE* in = freopen("E:\\Practice\\GCJ\\file\\C-small-attempt0.in", "r", stdin);
	FILE* out = freopen("E:\\Practice\\GCJ\\file\\C-small-attempt0.out", "w", stdout);

	fscanf(in, "%d", &t);

	for(k = 0; k < t; k++)
	{
		c = 0;
		fscanf(in, "%d %d", &a, &b);
		for(i = a; i <= b; i = i + 1)
		{
			int st = (int)sqrt(i);
			if(st * st == i && palindrome((int)i) && palindrome(st))
			{
				c++;
			}
		}
		fprintf(out, "Case #%d: %d\n", (k + 1), c);
	}

	fclose(out);
	fclose(in);
	return 0;
}