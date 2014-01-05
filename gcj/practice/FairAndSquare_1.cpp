#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

#define MAX_NUM 110

// whether s1 >= s2
int bige(int l1, int l2, int s1[], int s2[])
{
	int ret = 1;
	if(l1 > l2)	{ ret = 1; }
	if(l1 < l2) { ret = 0;	}
	if(l1 == l2)
	{
		for(int i = 0; i < l1; i++)
		{
			if(s1[i] > s2[i]) {	ret = 1; break; }
			if(s1[i] < s2[i]) {	ret = 0; break; }
		}
	}

	return ret;
}

// s1 mul s2
void bigmul(int l1, int l2, int ary1[], int ary2[], int ret[])
{
	int i = 0, j = 0;
	for(i = 0; i < l1; i++)
	{
		for(j = 0; j < l2; j++)
		{
			ret[i + j + 1] += ary1[i] * ary2[j];
		}
	}
	for(i = l1 + l2 - 1; i > 0; i--)
	{
		ret[i - 1] += ret[i] / 10;
		ret[i] = ret[i] % 10;
	}
	if(ret[0] == 0)
	{
		for(i = 0; i < l1 + l2 - 1; i++) { ret[i] = ret[i + 1]; }
		ret[i] = 0;
	}
}

int palindrome(int l, int s[])
{
	int ret = 1;
	int i = 0, j = l - 1;
	for(; i < j; i++, j--)
	{
		if(s[i] != s[j]) { ret = 0; break; }
	}
	return ret;
}

void addone(int l, int s[])
{
	int c = 1, t = 0;
	for(int i = l - 1; i >= 0; i--)
	{
		t = s[i] + c;
		s[i] = t % 10;
		c = t / 10;
	}
	if(c > 0)
	{
		for(t = l; l > 0; l--) { s[t] = s[t - 1]; }
		s[0] = c;
	}
}


int main()
{
	int t = 0;
	int la = 0, lb = 0;
	int i = 0, j = 0;
	int m = 0, n = 0;
	char a[MAX_NUM];
	char b[MAX_NUM];
	int ia[MAX_NUM];
	int ib[MAX_NUM];
	int re[MAX_NUM];

	int sa[MAX_NUM];
	int ch1[MAX_NUM];
	int ch2[MAX_NUM];

	int mul[MAX_NUM];

	FILE* in = freopen("E:\\Practice\\GCJ\\file\\C.in", "r", stdin);
	FILE* out = freopen("E:\\Practice\\GCJ\\file\\C.out", "w", stdout);

	fscanf(in, "%d", &t);

	for(i = 0; i < t; i++)
	{
		fscanf(in, "%s %s", &a, &b);
		la = strlen(a);
		lb = strlen(b);
		memset(ia, 0, sizeof(ia));
		memset(ib, 0, sizeof(ib));
		memset(re, 0, sizeof(re));
		memset(sa, 0, sizeof(sa));
		memset(mul, 0, sizeof(mul));
		for(j = 0; j < la; j++) { ia[j] = a[j] - '0'; }
		for(j = 0; j < lb; j++) { ib[j] = b[j] - '0'; }
		for(j = 0; j < (la / 2) + 1; j++) { sa[j] = ia[j]; }

		while(true)
		{
			bigmul((la / 2) + 1, (la / 2) + 1, sa, sa, mul);
			if(bige(la + 1, la, mul, ia)) { break; }
			else { addone((la / 2) + 1, sa); }
		}

		fprintf(out, "Case #%d: %s\n", (i + 1), re);
	}

	fclose(out);
	fclose(in);
	return 0;
}