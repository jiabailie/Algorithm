/* Prim's algorithm
 * http://en.wikipedia.org/wiki/Prim%27s_algorithm
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

inline void Prim(const Graph& g, vector<Edge>& MST)
{
	int n = g.n;
	int i = 0, j = 0;
	map<int, vector<Edge> > edgeG;	
	set<int> visited;
	set<int> uvisite;
	bool** reachAble = (bool**)malloc(sizeof(bool*) * n);

	for(i = 0; i < n; i++) 
	{ 
		uvisite.insert(i);
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

	visited.insert(0);
	uvisite.erase(0);

	while(visited.size() < n)
	{
		int minDis = INT_MAX;
		int n1 = -1;
		int n2 = -1;

		for(set<int>::iterator it1 = visited.begin(); it1 != visited.end(); it1++)
		{
			for(set<int>::iterator it2 = uvisite.begin(); it2 != uvisite.end(); it2++)
			{
				if(!reachAble[(*it1)][(*it2)] && g.weight[(*it1)][(*it2)] < minDis)
				{
					minDis = g.weight[(*it1)][(*it2)];
					n1 = (*it1);
					n2 = (*it2);
				}
			}
		}

		/* If there are more than one connected components. */
		if(minDis == INT_MAX && n1 == -1 && n2 == -1 && uvisite.size() > 0)
		{
			n1 = *(uvisite.begin());
			visited.insert(n1);
			uvisite.erase(n1);
			continue;
		}

		visited.insert(n2);
		uvisite.erase(n2);
		MST.push_back(Edge(n1, n2, minDis));

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

	Prim(g, MST);

	return 0;
}
