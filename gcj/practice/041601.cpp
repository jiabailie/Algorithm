#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

int pmin = 501;
vector<char> g_path;

void jump(int order, int x, int y, int cx, int cy, vector<char> path)
{
	if(order >= pmin) { return; }
	if(cx == x && cy == y && order < pmin) 
	{ 
		g_path.clear();
		for(vector<char>::iterator it = path.begin(); it != path.end(); it++)
		{
			g_path.push_back((*it));
		}
		return; 
	}

	if(x > cx && x - cx <= order + 1)
	{
		vector<char> tmp = path;
		tmp.push_back('E');
		jump(order + 1, x, y, cx + order + 1, cy, tmp);
	}

	if(y > cy && y - cy <= order + 1)
	{
		vector<char> tmp = path;
		tmp.push_back('N');
		jump(order + 1, x, y, cx, cy + order + 1, tmp);
	}

	if(x < cx && cx - x <= order + 1)
	{
		vector<char> tmp = path;
		tmp.push_back('W');
		jump(order + 1, x, y, cx - order - 1, cy, tmp);
	}

	if(y < cy && cy - y <= order + 1)
	{
		vector<char> tmp = path;
		tmp.push_back('S');
		jump(order + 1, x, y, cx, cy - order - 1, tmp);
	}
}

int main()
{
	int t = 0;
	int x = 0, y = 0;
	int i = 0, j = 0, k = 0;
	vector<char> path;

	FILE* in = freopen("E:\\Practice\\GCJ\\file\\1.in", "r", stdin);
	FILE* out = freopen("E:\\Practice\\GCJ\\file\\1.out", "w", stdout);

	fscanf(in, "%d", &t);
	for(k = 0; k < t; k++)
	{
		fscanf(in, "%d %d", &x, &y);
		path.clear();
		jump(0, x, y, 0, 0, path);
		fprintf(out, "Case #%d: ", (k + 1));
		for(vector<char>::iterator it = g_path.begin(); it != g_path.end(); it++)
		{
			fprintf(out, "%c", (*it));
		}
		fprintf(out, "\n");
	}

	fclose(in);
	fclose(out);

	return 0;
}