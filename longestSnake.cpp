#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#define MAX 100

using namespace std;

int n = 0;
int board[MAX][MAX];
vector<vector<int> > res;

int mlength = INT_MIN;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

inline int abs(int x) { return x > 0 ? x : -x; }

void dfs(int x, int y, vector<int> current, bool visited[][MAX])
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
            dfs(x + dx[i], y + dy[i], current, visited);

            visited[x + dx[i]][y + dy[i]] = false;
  		current.pop_back();
        }
    }
    if(!change && current.size() > 0)
    {
        if((int)current.size() >= mlength)
        {
            if((int)current.size() > mlength)
            {
                res.clear();
                mlength = current.size();
            }
            res.push_back(current);
            for(i = 0; i < (int)current.size(); i++)
            {
                printf("%d ", current[i]);
            }
            printf("\n");
        }
    }
}

int find()
{
    int i = 0, j = 0, k = 0;
    vector<int> current;
	bool visited[MAX][MAX];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            current.clear();
            memset(visited, 0, sizeof(visited));
            visited[i][j] = true;
            current.push_back(board[i][j]);
            dfs(i, j, current, visited);
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
