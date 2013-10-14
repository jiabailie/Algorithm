/* Using stack and queue to realize dfs and bfs. 
 */
#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include<cstring>

using namespace std;

const int n = 7;

void dfs(int start, int graph[n][n])
{
	int i = 0;
	int cvisit = 0;
	stack<int> istack;
	vector<bool> visit(n, false);
	istack.push(start);

	while(!istack.empty() && cvisit < n)
	{
		int top = istack.top();
		istack.pop();
		cvisit++;

		visit[top] = true;
		cout << top << " ";

		for(i = 0; i < n; i++)
		{
			if(graph[top][i] && !visit[i])
			{
				istack.push(i);
				break;
			}
		}
		if(istack.empty() && cvisit < n) // if there are more than one connected-components.
		{
			for(i = 0; i < n; i++)
			{
				if(!visit[i])
				{
					istack.push(i);
					break;
				}
			}
		}
	}
}

void bfs(int start, int graph[n][n])
{
	int i = 0;
	int cvisit = 0;
	queue<int> iqueue;
	vector<bool> visit(n, false);
	iqueue.push(start);
	
	while(!iqueue.empty() && cvisit < n)
	{
		int front = iqueue.front();
		iqueue.pop();
		cvisit++;

		visit[front] = true;
		cout << front << " ";
		for(i = 0; i < n; i++)
		{
			if(graph[front][i] && !visit[i])
			{
				iqueue.push(i);
			}
		}

		if(iqueue.empty() && cvisit < n)
		{
			for(i = 0; i < n; i++)
			{
				if(!visit[i])
				{
					iqueue.push(i);
					break;
				}
			}
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
