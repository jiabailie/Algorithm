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

struct Edge
{
	int node1;
	int node2;
	int weight;
	Edge() : node1(0), node2(0), weight(-1) {}
	Edge(int _node1, int _node2, int _weight) : node1(_node1), node2(_node2), weight(_weight) {}
	Edge(const Edge& _edge);
	Edge& operator=(const Edge& _edge);
	void partCopy(Edge& edge, const Edge& _edge);
	~Edge() {}
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
