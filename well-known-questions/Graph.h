#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

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
	Graph(const Graph& _graph);
	Graph& operator=(const Graph& _graph);
	void partCopy(Graph& graph, const Graph& _graph);
	~Graph() { };
};

Graph::Graph()
{
	int i = 0;

	cout << "Please input the amount of different nodes: ";
	cin >> n;

	for(i = 0; i < n; i++)
	{
		vector<int> line(n, 0);
		weight.push_back(line);
	}

	cout << "Please input the amount of different edges: ";
	cin >> e;

	cout << "Please select the graph type:" << endl
		 << "0. Undirected Graph" << endl
		 << "1. Directed Graph" << endl;
	cin >> i;
	gType = GraphTypes(i);

	cout << "Please input the infomation about the graph (n1, n2, weight):";
	int n1 = 0, n2 = 0, v = 0;
	
	for(i = 0; i < e; i++)
	{
		cin >> n1 >> n2 >> v;
		weight[n1][n2] = v;
		if(gType == Undirected)
		{
			weight[n2][n1] = v;
		}
	}
}

Graph::Graph(const Graph& _graph)
{
	partCopy(*this, _graph);
}

Graph& Graph::operator=(const Graph& _graph)
{
	if(&_graph != this)
	{
		partCopy(*this, _graph);
	}
	return *this;
}

void Graph::partCopy(Graph& graph, const Graph& _graph)
{
	graph.n = _graph.n;
	graph.e = _graph.e;
	graph.gType = _graph.gType;

	for(int i = 0; i < n; i++)
	{
		vector<int> line(_graph.weight[i].begin(), _graph.weight[i].end());
		graph.weight.push_back(line);
	}
}
