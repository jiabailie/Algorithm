#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vld.h>

using namespace std;

const int N = 10;

struct Node
{
	int data;
	vector<Node*> neighbors;
};

int arrGraph[N][N];

void displayArrGraph()
{
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			cout << arrGraph[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void bfs()
{
	int top = 0;
	bool visited[N];
	queue<int> ique;
	vector<int> neighbour;
	memset(visited, 0, sizeof(visited));
	ique.push(0);
	while(!ique.empty())
	{
		top = ique.front();
		ique.pop();
		if(visited[top])
		{
			continue;
		}
		visited[top] = true;
		neighbour.clear();
		for(int i = 0; i < N; ++i)
		{
			if(arrGraph[top][i] && !visited[i])
			{
				ique.push(i);
				neighbour.push_back(i);
			}
		}
		cout << top << ":" << " {";
		for(int i = 0; i < neighbour.size(); ++i)
		{
			cout << neighbour[i] << ",";
		}
		cout << "}" << endl;
	}
}

void bfs(Node *rootNode)
{
	if(!rootNode)
	{
		throw exception("The root node is NULL");
	}
	cout << endl << "bfs() starts." << endl;
	Node *top = 0;
	set<Node*> visited;
	queue<Node*> iqueue;
	iqueue.push(rootNode);
	while(!iqueue.empty())
	{
		top = iqueue.front();
		iqueue.pop();
		if(visited.find(top) != visited.end())
		{
			continue;
		}
		visited.insert(top);
		cout << top->data << " ";
		for(vector<Node*>::iterator it = top->neighbors.begin(); it != top->neighbors.end(); ++it)
		{
			iqueue.push(*it);
		}
	}
	cout << endl << "bfs() ends." << endl;
}

void destroyGraph(Node **rootNode)
{
	if(!rootNode || !(*rootNode))
	{
		return;
	}
	for(int i = 0; i < (*rootNode)->neighbors.size(); ++i)
	{
		destroyGraph(&((*rootNode)->neighbors[i]));
		(*rootNode)->neighbors[i] = 0;
	}
	if(rootNode && *rootNode && (*rootNode)->data >= 0)
	{
		delete (*rootNode);
		*rootNode = 0;
		rootNode = 0;
	}
}

Node *BuildGraph()
{
	int top = 0;
	bool visited[N];
	Node *vecGraph[N];
	memset(visited, 0, sizeof(visited));
	memset(vecGraph, 0, sizeof(vecGraph));

	queue<int> iqueue;
	iqueue.push(0);
	while(!iqueue.empty())
	{
		top = iqueue.front();
		iqueue.pop();
		if(visited[top])
		{
			continue;
		}
		visited[top] = true;
		if(!vecGraph[top])
		{
			vecGraph[top] = new Node();
			vecGraph[top]->data = 0;
		}
		for(int i = 0; i < N; ++i)
		{
			if(arrGraph[top][i] && !visited[i])
			{
				if(!vecGraph[i])
				{
					vecGraph[i] = new Node();
					vecGraph[i]->data = i;
				}
				vecGraph[top]->neighbors.push_back(vecGraph[i]);
				iqueue.push(i);
			}
		}
	}
	return vecGraph[0];
}

Node *clone(Node *graph)
{
	if(!graph)
	{
		return 0;
	}
	Node *top = 0;
	map<Node*, Node*> mapCopy;
	queue<Node*> iqueue;
	iqueue.push(graph);
	mapCopy[graph] = new Node();
	mapCopy[graph]->data = graph->data;

	while(!iqueue.empty())
	{
		top = iqueue.front();
		iqueue.pop();
		for(int i = 0; i < top->neighbors.size(); ++i)
		{
			if(mapCopy.find(top->neighbors[i]) == mapCopy.end())
			{
				mapCopy[top->neighbors[i]] = new Node();
				mapCopy[top->neighbors[i]]->data = top->neighbors[i]->data;
				iqueue.push(top->neighbors[i]);
			}
			mapCopy[top]->neighbors.push_back(mapCopy[top->neighbors[i]]);
		}
	}

	return mapCopy[graph];
}

int main()
{
	int i = 0, j = 0;
	memset(arrGraph, 0, sizeof(arrGraph));
	for(i = 0; i < N; ++i)
	{
		for(j = 0; j < i; ++j)
		{
			arrGraph[i][j] = arrGraph[j][i] = rand() % 2;
		}
	}
	displayArrGraph();
	bfs();

	Node *rootNode = BuildGraph();
	bfs(rootNode);

	Node *cloneNode = clone(rootNode);
	bfs(cloneNode);

	destroyGraph(&rootNode);
	destroyGraph(&cloneNode);

	return 0;
}