/* Kruskal's algorithm
 * http://en.wikipedia.org/wiki/Kruskal%27s_algorithm
 */
#include "Graph.h"

template<typename T>
inline void deleteArray(int len, T** source)
{
	if(!source) { return; }
	for(int i = 0; i < len; i++)
	{
		if(source[i])
		{
			free(source[i]);
		}
	}
}

inline void Kruscal(const Graph& g, vector<Edge>& MST)
{
	int n = g.n;
	int i = 0, j = 0;
	map<int, vector<Edge> > edgeG;
	bool** reachAble = (bool**)malloc(sizeof(bool*) * n);

	for(i = 0; i < n; i++) 
	{ 
		reachAble[i] = (bool*)malloc(sizeof(bool) * n); 
		memset(reachAble[i], false, sizeof(bool) * n);
	}

	MST.clear();

	for(i = 0; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(g.weight[i][j] != INT_MAX)
			{
				edgeG[g.weight[i][j]].push_back(Edge(i, j, g.weight[i][j]));
			}
		}
	}

	for(map<int, vector<Edge> >::iterator it = edgeG.begin(); it != edgeG.end(); it++)
	{
		vector<Edge> vEdge(it->second.begin(), it->second.end());
		for(vector<Edge>::iterator iit = vEdge.begin(); iit != vEdge.end(); iit++)
		{
			int n1 = (*iit).node1;
			int n2 = (*iit).node2;

			/* If n1 and n2 are not connected, adding this edge or not. */
			if(reachAble[n1][n2])
			{
				continue;
			}
			MST.push_back(*iit);

			vector<int> nset1;
			vector<int> nset2;
			
			nset1.push_back(n1);
			nset2.push_back(n2);

			/* Modify the reachable matrix. */
			for(i = 0; i < n; i++)
			{
				if(reachAble[i][n1])
				{
					nset1.push_back(i);
				}
				if(reachAble[i][n2])
				{
					nset2.push_back(i);
				}
			}
			for(i = 0; i < nset1.size(); i++)
			{
				for(j = 0; j < nset2.size(); j++)
				{
					reachAble[nset1[i]][nset2[j]] = true;
					reachAble[nset2[j]][nset1[i]] = true;
				}
			}
		}
		/* If the minimum spanning tree has had (n - 1) edges, stop the process. */
		if(MST.size() == n - 1)
		{
			break;
		}
	}

	deleteArray(n, reachAble);
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

	vector<Edge> MST;

	Kruscal(g, MST);

	return 0;
}
