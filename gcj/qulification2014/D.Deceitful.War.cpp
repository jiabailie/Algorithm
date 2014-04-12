#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n = 0;
double snao[1000];
double sken[1000];
bool unao[1000];
bool uken[1000];

int war()
{
	int i = 0, j = 0;
	int scoreNao = 0;
	int scoreKen = 0;	
	bool find = false;
	memset(uken, 0, sizeof(uken));

	for(i = 0; i < n; ++i)
	{
		find = false;
		for(j = 0; j < n && !find; ++j)
		{
			if(!uken[j] && snao[i] < sken[j])
			{
				scoreKen += 1;
				uken[j] = true;
				find = true;
			}
		}
		if(!find)
		{			
			for(j = 0; j < n; ++j)
			{
				if(!uken[j])
				{
					uken[j] = true;
					if(snao[i] > sken[j])
					{
						scoreNao += 1;
					}
					else if(snao[i] < sken[j])
					{
						scoreKen += 1;
					}
					break;
				}
			}
		}
	}

	return scoreNao;
}

int dwar()
{
	int i = 0, j = 0;
	int scoreNao = 0;
	int scoreKen = 0;
	int maxKen = 0;
	int maxNao = 0, minNao = 0;
	
	memset(unao, 0, sizeof(unao));
	memset(uken, 0, sizeof(uken));
	
	for(i = 0; i < n; ++i)
	{
		for(j = n - 1; j >= 0; --j)
		{
			if(!unao[j]) { maxNao = j; break; }
		}
		for(j = n - 1; j >= 0; --j)
		{
			if(!uken[j]) { maxKen = j; break; }
		}

		if(snao[maxNao] > sken[maxKen])
		{
			scoreNao += 1;
			unao[maxNao] = true;
			uken[maxKen] = true;
		}
		else if(snao[maxNao] < sken[maxKen])
		{
			for(j = 0; j < n; ++j)
			{
				if(!unao[j]) { minNao = j; break; }
			}
			scoreKen += 1;
			unao[minNao] = true;
			uken[maxKen] = true;
		}
	}

	return scoreNao;
}

int main()
{
	int t = 0;
	int i = 0, j = 0;
	char buffer[2048];

	FILE* in = freopen("D:/Lab/Contests/Contests/file/D-large.in", "r", stdin);
	FILE* out = freopen("D:/Lab/Contests/Contests/file/D-large.out", "w", stdout);

	fscanf(in, "%d", &t);

	for(i = 0; i < t; i++)
	{
		fscanf(in, "%d", &n);

		for(j = 0; j < n; ++j)
		{
			fscanf(in, "%s", buffer);
			snao[j] = atof(buffer);
		}

		for(j = 0; j < n; ++j)
		{
			fscanf(in, "%s", buffer);
			sken[j] = atof(buffer);
		}

		sort(snao, snao + n);
		sort(sken, sken + n);
		
		fprintf(out, "Case #%d: %d %d\n", (i + 1), dwar(), war());
	}

	fclose(out);
	fclose(in);
	return 0;
}