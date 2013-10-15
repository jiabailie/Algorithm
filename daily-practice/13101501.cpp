/* Floyd–Warshall algorithm 
 * Source: www.codechef.com/UVCNCD13/problems/CTSHT
 * Wiki: en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
 */
#include <cstdio>
#include <climits>
#include <cstring>

using namespace std;

const int LEN = 210;

int n = 0;
int dis[LEN][LEN];

inline void FloydWarshall()
{
	int i = 0, j = 0, k = 0;

	for(k = 0; k < n; k++)
	{
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{		
				if(dis[i][k] + dis[k][j] < dis[i][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
}

int main()
{
	int a = 0, b = 0;
	int t = 0, q = 0;
	int i = 0, j = 0, k = 0;	
	char line[LEN + 1];

	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%d", &n);
		for(j = 0; j < n; j++)
		{
			scanf("%s", &line);
			for(k = 0; k < n; k++)
			{
				if(line[k] == 'Y') { dis[j][k] = 1; }
				else { dis[j][k] = 420; }
			}
			dis[j][j] = 0;
		}

		FloydWarshall();
		scanf("%d", &q);
		for(j = 0; j < q; j++)
		{
			scanf("%d %d", &a, &b);
			printf("%d\n", dis[a][b]);
		}
	}
	return 0;
}
