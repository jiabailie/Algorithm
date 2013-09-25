#include "Graph.h"

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

	for(i = 0; i < n; i++)
	{
		if(i != startNode)
		{
			distance[i] = g.weight[startNode][i];
			path[i] = startNode;
		}
	}

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
	const int n = 6;
	int e = 9;
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
