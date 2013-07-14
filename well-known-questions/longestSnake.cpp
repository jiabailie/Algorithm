/*
You are given a 2-D array with same number of rows and columns. You have to determine the longest snake in the array. 
The property to find the snake is the difference between the adjacent(left, right, up or down) should be either 1 or -1. 
If there are more than one snakes with maximum length, the output should print both of them. 

Example--> 

The given array elements are as follows: 

4	7	9	8 
5	6	5	4 
6	7	8	5 
10	9	7	6 

The longest snakes are 7->6->5->4->5->6 and 7->6->7->6->5->4
 */
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#define MAX 100

using namespace std;

int n = 0;
int board[MAX][MAX];
bool g_visited[MAX][MAX];
vector<vector<int> > res;
vector<vector<int> > g_px;
vector<vector<int> > g_py;

int mlength = INT_MIN;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

inline int abs(int x) { return x > 0 ? x : -x; }

void dfs(int x, int y, vector<int> current, vector<int> px, vector<int> py, bool visited[][MAX])
{
    int change = 0, i = 0;
    for(i = 0; i < 4; i++)
    {
        if(x + dx[i] >= 0 && x + dx[i] < n &&
           y + dy[i] >= 0 && y + dy[i] < n &&
           !visited[x + dx[i]][y + dy[i]] &&
           abs(board[x][y] - board[x + dx[i]][y + dy[i]]) == 1)
        {
            change = 1;
            visited[x + dx[i]][y + dy[i]] = true;
            current.push_back(board[x + dx[i]][y + dy[i]]);
            px.push_back(x + dx[i]);
            py.push_back(y + dy[i]);

            dfs(x + dx[i], y + dy[i], current, px, py, visited);

            visited[x + dx[i]][y + dy[i]] = false;
            current.pop_back();
            px.pop_back();
            py.pop_back();
        }
    }
    if(!change && current.size() > 0)
    {
        if((int)current.size() >= mlength)
        {
            if((int)current.size() > mlength)
            {
                res.clear();
                g_px.clear();
                g_py.clear();
                mlength = current.size();
            }
            res.push_back(current);
            g_px.push_back(px);
            g_py.push_back(py);
            for(i = 0; i < (int)current.size(); i++)
            {
                printf("%d ", current[i]);
            }
            printf("\n");
        }
    }
}

bool checkpath(int x, int y)
{
    bool ret = false;
    for(int i = 0; i < (int)g_px.size() && !ret; i++)
    {
        for(int j = 0; j < (int)g_px[i].size() && !ret; j++)
        {
            if(g_px[i][j] == x && g_py[i][j] == y)
            {
                ret = true;
            }
        }
    }
    return ret;
}
int find()
{
    int i = 0, j = 0;
    vector<int> current;
    vector<int> px;
    vector<int> py;
    bool visited[MAX][MAX];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
	    /* if the position doesn't exist in the current longest snakes, it will be check now */
            /* if the position exist int the current longest snakes, which means it has been visited and checked, 
               just ignore it */
            if(!checkpath(i, j))
            {
                current.clear();
		px.clear();
		py.clear();
		memset(visited, 0, sizeof(visited));

		visited[i][j] = true;

		current.push_back(board[i][j]);
		px.push_back(i);
		py.push_back(j);
		dfs(i, j, current, px, py, visited);
            }
        }
    }
    return 0;
}

int main()
{
    int i = 0, j = 0;
    memset(board, 0, sizeof(board));

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    find();

    return 0;
}
