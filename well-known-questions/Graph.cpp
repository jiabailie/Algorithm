#include "Graph.h"

Edge::Edge(const Edge& _edge)
{
	partCopy(*this, _edge);
}

Edge& Edge::operator=(const Edge& _edge)
{
	if(&_edge != this)
	{
		partCopy(*this, _edge);
	}
	return *this;
}

void Edge::partCopy(Edge& edge, const Edge& _edge)
{
	edge.node1 = _edge.node1;
	edge.node2 = _edge.node2;
	edge.weight = _edge.weight;
}

Graph::Graph()
{
	int i = 0;

	cout << "Please input the amount of different nodes: " << endl;
	cin >> n;

	for(i = 0; i < n; i++)
	{
		vector<int> line(n, INT_MAX);
		weight.push_back(line);
	}

	cout << "Please input the amount of different edges: " << endl;
	cin >> e;

	cout << "Please select the graph type:" << endl
		 << "0. Undirected Graph" << endl
		 << "1. Directed Graph" << endl;
	cin >> i;
	gType = GraphTypes(i);

	cout << "Please input the infomation about the graph (n1, n2, weight):" << endl;
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

Graph::Graph(int _n, int _e, GraphTypes _gType, vector<vector<int> >& _weight)
{
	n = _n;
	e = _e;
	gType = _gType;
	weight = _weight;
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
