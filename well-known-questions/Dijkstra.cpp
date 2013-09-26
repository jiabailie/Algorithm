/* Dijkstra's algorithm 
 * http://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
 */
#include "Graph.h"

/* Distance[] records the minimum distance from startNode. 
 * Path[] records the pre-node in the path which is the shortest path from startNode to this node.
 */
inline void Dijkstra(int startNode, vector<int>& distance, vector<int>& path, Graph& g)
{
	int n = g.n;
	int i = 0, j = 0;
	int cvisited = 0;
	bool* visited = (bool*)malloc(sizeof(bool) * n);

	memset(visited, false, sizeof(bool) * n);

	visited[startNode] = true;
	distance[startNode] = 0;
	path[startNode] = startNode;
	cvisited++;

	/* Initialize the distance and path. */
	for(i = 0; i < n; i++)
	{
		if(i != startNode)
		{
			distance[i] = g.weight[startNode][i];
			path[i] = startNode;
		}
	}

	/* Visit all unvisited nodes, and find the nearest node to put into the visited set. */
	while(cvisited < n)
	{
		int min = INT_MAX;
		int minC = -1;
		for(i = 0; i < n; i++)
		{
			if(!visited[i] && distance[i] < min)
			{
				min = distance[i];
				minC = i;
			}
		}

		cvisited++;
		visited[minC] = true;

		/* Adjust the distance and pre-node along the path. */
		for(i = 0; i < n; i++)
		{
			if(i != minC && g.weight[minC][i] != INT_MAX && g.weight[minC][i] + distance[minC] < distance[i])
			{
				distance[i] = g.weight[minC][i] + distance[minC];
				path[i] = minC;
			}
		}
	}
}

int main()
{
	int e = 9;
	const int n = 6;

	vector<vector<int> > weight;

	int matrix[n][n] = 
	{{0,  7,  9,  0, 0, 14},
	 {7,  0, 10, 15, 0,  0},
	 {9, 10,  0, 11, 0,  2},
	 {0, 15, 11,  0, 6,  0},
	 {0,  0,  0,  6, 0,  9},
	 {14, 0,  2,  0, 9,  0}};

	for(int i = 0; i < n; i++)
	{
		vector<int> t;		
		for(int j = 0; j < n; j++)
		{
			if(i == j) { t.push_back(0); continue; }
			t.push_back(matrix[i][j] == 0 ? INT_MAX : matrix[i][j]);
		}
		weight.push_back(t);
	}
	Graph g(n, e, GraphTypes(0), weight);

	vector<int> distance(n, INT_MAX);
	vector<int> path(n, -1);

	Dijkstra(0, distance, path, g);

	return 0;
}
