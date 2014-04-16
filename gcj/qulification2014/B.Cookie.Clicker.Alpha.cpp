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

double c = 0.0;
double f = 0.0;
double x = 0.0;

double solve()
{
	vector<double> stime;
	int i = 0;
	int maxN = 100000;
	stime.push_back(x / 2);
	double cost = 0;
	for(i = 1; i <= maxN; ++i)
	{
		cost += c / (2.0 + (i - 1) * f);
		stime.push_back(cost * 1.0 + x / (2.0 + i * f));
	}
	sort(stime.begin(), stime.end());
	return stime[0];
}

int main()
{
	int t = 0, i = 0;	
	char buffer[2048];

	FILE* in = freopen("D:/Lab/Contests/Contests/file/B-large.in", "r", stdin);
	FILE* out = freopen("D:/Lab/Contests/Contests/file/B-large.out", "w", stdout);

	fscanf(in, "%d", &t);

	for(i = 0; i < t; i++)
	{
		fscanf(in, "%s", buffer);
		c = atof(buffer);
		fscanf(in, "%s", buffer);
		f = atof(buffer);
		fscanf(in, "%s", buffer);
		x = atof(buffer);
		
		fprintf(out, "Case #%d: %.7f\n", (i + 1), solve());
	}

	fclose(out);
	fclose(in);
	return 0;
}