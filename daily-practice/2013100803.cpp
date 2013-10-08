/* Find the shortest path between two nodes, and the nodes have their own name as string format.
 * Source : blog.csdn.net/ganze_12345/article/details/12419527
 */
#include <cstdio>
#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

void addPairToMap(char*& str, map<char*, int>& project)
{
	bool find = false;
	for(map<char*, int>::iterator it = project.begin(); it != project.end(); it++)
	{
		if(strcmp(str, (*it).first) == 0)
		{
			find = true;

			delete[] str;
			str = (*it).first;
			break;
		}
	}
	if(!find)
	{
		int t = project.size();
		project.insert(pair<char*, int>(str, t));
	}
}

int findIndex(char* name, map<char*, int> project)
{
	int ret = -1;
	for(map<char*, int>::iterator it = project.begin(); it != project.end(); it++)
	{
		if(strcmp(name, (*it).first) == 0)
		{
			ret = (*it).second;
			break;
		}
	}
	return ret;
}

int findShortestPathFloyd(int is, int ie, vector<vector<bool> >& graph)
{
	int n = graph[0].size();
	int i = 0, j = 0;
	vector<int> pre(n, -1);
	vector<int> cost(n, n << 1);

	pre[is] = is;
	cost[is] = 0;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(graph[i][j] && cost[j] > cost[i] + 1)
			{
				pre[j] = i;
				cost[j] = cost[i] + 1;
			}
		}
	}
	return cost[ie];
}

int findShortestPathDijkstra(int is, int ie, vector<vector<bool> >& graph)
{
	int i = 0, j = 0;
	int prei = -1;
	int minCur = -1;
	int n = graph[0].size();
	vector<int> pre(n, -1);
	vector<int> cost(n, INT_MAX);
	vector<bool> visit(n, false);

	pre[is] = is;
	cost[is] = 0;
	visit[is] = true;

	while(true)
	{
		prei = -1;
		minCur = -1;
		for(i = 0; i < n && minCur == -1; i++)
		{
			if(visit[i])
			{
				for(j = 0; j < n && minCur == -1; j++)
				{
					if(!visit[j] && graph[i][j])
					{
						prei = i;
						minCur = j;
					}
				}
			}
		}
		if(minCur == -1)
		{
			break;
		}
		if(cost[minCur] > cost[prei] + 1)
		{
			pre[minCur] = prei;
			cost[minCur] = cost[prei] + 1;
		}
		for(i = 0; i < n; i++)
		{
			if(graph[i][minCur] && cost[i] > cost[minCur] + 1)
			{
				cost[i] = cost[minCur] + 1;
				pre[i] = minCur;
			}
		}
		visit[minCur] = true;
	}

	return cost[ie];
}

void freeProject(map<char*, int> project)
{
	for(map<char*, int>::iterator it = project.begin(); it != project.end(); it++)
	{
		delete[] (*it).first;
	}
}

int main()
{
	int i = 0, j = 0;

	map<char*, int> project;
	vector<vector<bool> > graph;		
	vector<pair<char*, char*> > links;

	while(true)
	{
		char* node1 = new char[5];
		char* node2 = new char[5];

		cin >> node1 >> node2;
		if(strcmp(node1, "-1") == 0 && strcmp(node2, "-1") == 0)
		{
			break;
		}

		addPairToMap(node1, project);
		addPairToMap(node2, project);

		pair<char*, char*> tpair;

		tpair.first = node1;
		tpair.second = node2;
		links.push_back(tpair);
	}

	int n = project.size();
	
	for(i = 0; i < n; i++)
	{
		graph.push_back(vector<bool>(n, false));
	}

	for(vector<pair<char*, char*> >::iterator it = links.begin(); it != links.end(); it++)
	{
		int t1 = project[(*it).first];
		int t2 = project[(*it).second];
		graph[t1][t2] = true;
		graph[t2][t1] = true;
	}

	char* start = new char[5];
	char* end = new char[5];

	int is = 0, ie = 0;

	cin >> start >> end;

	is = findIndex(start, project);
	ie = findIndex(end, project);

	if(is == -1)
	{
		cout << "Start node is not exist." << endl;
	}
	if(ie == -1)
	{
		cout << "End node is not exist." << endl;
	}
	if(is == -1 || ie == -1)
	{
		delete[] start;
		delete[] end;

		return 0;
	}

	cout << findShortestPathFloyd(is, ie, graph) << endl;
	cout << findShortestPathDijkstra(is, ie, graph) << endl;

	delete[] start;
	delete[] end;

	freeProject(project);

	return 0;
}
