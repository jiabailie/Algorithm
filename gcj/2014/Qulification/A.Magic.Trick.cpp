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

using namespace std;

int a = 0, b = 0;

int board1[4][4];
int board2[4][4];

int solve()
{
	vector<int> ret;
	int i = 0, j = 0;
	for(i = 0; i < 4; ++i)
	{
		for(j = 0; j < 4; ++j)
		{
			if(board1[a][i] == board2[b][j])
			{
				ret.push_back(board1[a][i]);
			}
		}
	}
	if(ret.size() == 1)
	{
		return ret[0];
	}
	else if(ret.size() > 1)
	{
		return -1;
	}
	else if(ret.size() == 0)
	{
		return 0;
	}
}

int main()
{
	int t = 0;	
	int i = 0, j = 0, k = 0;

	FILE* in = freopen("D:/Lab/Contests/Contests/file/A-small-attempt3.in", "r", stdin);
	FILE* out = freopen("D:/Lab/Contests/Contests/file/A-small-attempt3.out", "w", stdout);

	fscanf(in, "%d", &t);

	for(i = 0; i < t; i++)
	{
		fscanf(in, "%d", &a);
		for(j = 0; j < 4; ++j)
		{
			for(k = 0; k < 4; ++k)
			{
				fscanf(in, "%d", &board1[j][k]);
			}
		}
		fscanf(in, "%d", &b);
		for(j = 0; j < 4; ++j)
		{
			for(k = 0; k < 4; ++k)
			{
				fscanf(in, "%d", &board2[j][k]);
			}
		}
		a -= 1;
		b -= 1;
		j = solve();
		switch(j)
		{
		case -1:
			fprintf(out, "Case #%d: %s\n", (i + 1), "Bad magician!");
			break;
		case 0:
			fprintf(out, "Case #%d: %s\n", (i + 1), "Volunteer cheated!");
			break;
		default:
			fprintf(out, "Case #%d: %d\n", (i + 1), j);
			break;
		}
	}

	fclose(out);
	fclose(in);
	return 0;
}