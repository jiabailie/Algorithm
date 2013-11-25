/* Problem Source : bbs.csdn.net/topics/390650933 */
#include <cstdio>
#include <set>
#include <iostream>

using namespace std;

int m = 0;

int bytwo[10] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18}; // 2 * k
int byone[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // 1 * k

set<int> ret;

inline void findFiveLen()
{
	int s = 0, t = 0;
	int i = 0, j = 0, k = 0;

	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			t = m - bytwo[i] - bytwo[j];
			if(t >= 0 && t <= 9)
			{
				k = i * 10000 + j * 1000 + t * 100 + j * 10 + i;
				if(k > 10000) { ret.insert(k); }
				k = j * 10000 + i * 1000 + t * 100 + i * 10 + j;
				if(k > 10000) { ret.insert(k); }
			}
		}
	}
}

inline void findSixLen()
{
	int s = 0, t = 0;
	int i = 0, j = 0, k = 0;

	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			t = m - bytwo[i] - bytwo[j];
			if(t >= 0 && t <= 18 && t % 2 == 0)
			{
				t >>= 1;

				k = i * 100000 + j * 10000 + t * 1000 + t * 100 + j * 10 + i;
				if(k > 100000) { ret.insert(k); }

				k = i * 100000 + t * 10000 + j * 1000 + j * 100 + t * 10 + i;
				if(k > 100000) { ret.insert(k); }

				k = j * 100000 + i * 10000 + t * 1000 + t * 100 + i * 10 + j;
				if(k > 100000) { ret.insert(k); }

				k = j * 100000 + t * 10000 + i * 1000 + i * 100 + t * 10 + j;
				if(k > 100000) { ret.insert(k); }

				k = t * 100000 + i * 10000 + j * 1000 + j * 100 + i * 10 + t;
				if(k > 100000) { ret.insert(k); }

				k = t * 100000 + j * 10000 + i * 1000 + i * 100 + j * 10 + t;
				if(k > 100000) { ret.insert(k); }
			}
		}
	}
}

int main()
{
	cin >> m;

	findFiveLen();
	findSixLen();

	if(ret.size() == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		for(set<int>::iterator it = ret.begin(); it != ret.end(); it++)
		{
			cout << (*it) << endl;
		}
	}
	return 0;
}
