/* Using stack and queue to realize dfs and bfs. */
#include <cstdio>
#include <set>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int n = 7;

void dfs(int start, int graph[n][n])
{
	int i = 0;
	set<int> iset;
	stack<int> istack;
	vector<int> tmp;

	istack.push(start);

	for(i = 0; i < n; i++) { iset.insert(i); }

	while(!istack.empty())
	{
		int top = istack.top();
		istack.pop();
		iset.erase(top);

		cout << top << " ";

		tmp.clear();
		for(set<int>::iterator it = iset.begin(); it != iset.end(); it++)
        {
            if(graph[top][(*it)])
            {
                tmp.push_back(*it);
            }
        }
        for(vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
        {
            istack.push(*it);
            iset.erase(*it);
        }

		if(istack.empty() && !iset.empty()) // if there are more than one connected-components.
		{
			istack.push(*(iset.begin()));
		}
	}
}

void bfs(int start, int graph[n][n])
{
	int i = 0;
	set<int> iset;
	queue<int> iqueue;
	vector<int> tmp;

	iqueue.push(start);

	for(i = 0; i < n; i++) { iset.insert(i); }

	while(!iqueue.empty())
	{
		int front = iqueue.front();
		iqueue.pop();
		iset.erase(front);

		cout << front << " ";

		tmp.clear();
		for(set<int>::iterator it = iset.begin(); it != iset.end(); it++)
        {
            if(graph[front][(*it)])
            {
                tmp.push_back(*it);
            }
        }
        for(vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
        {
            iqueue.push(*it);
            iset.erase(*it);
        }

		if(iqueue.empty() && !iset.empty()) // if there are more than one connected-components.
		{
			iqueue.push(*(iset.begin()));
		}
	}
}

int main()
{
	int graph[n][n] =
	{
		{0, 1, 0, 0, 0, 0, 1,},
		{1, 0, 1, 0, 0, 0, 0,},
		{0, 1, 0, 1, 0, 0, 0,},
		{0, 0, 1, 0, 1, 0, 0,},
		{0, 0, 0, 1, 0, 1, 0,},
		{0, 0, 0, 0, 1, 0, 1,},
		{1, 0, 0, 0, 0, 1, 0,}
	};

	dfs(0, graph);
	cout << endl;
	bfs(0, graph);
	cout << endl;

	return 0;
}
