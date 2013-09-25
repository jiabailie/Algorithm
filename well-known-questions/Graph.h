#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

enum GraphTypes
{
	Undirected = 0,
	Directed = 1
};

struct Graph
{
	int n; // The amount of different nodes.
	int e; // The amount of different edges.
	GraphTypes gType;
	vector<vector<int> > weight; // The weight matrix of this graph.
	Graph();
	Graph(int, int, GraphTypes, vector<vector<int> >&);
	Graph(const Graph& _graph);
	Graph& operator=(const Graph& _graph);
	void partCopy(Graph& graph, const Graph& _graph);
	~Graph() { };
};
