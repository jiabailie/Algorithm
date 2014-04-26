#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;
const int N = 1001;
int n = 0;
bool g[N][N];
int board[N][N];
inline int nr(int p, int node)
{
	if(board[p][node] != -1)
	{
		return board[p][node];
	}
    int i = 0;
    vector<int> c;
    vector<int> a;
    for(i = 1; i <= n; ++i)
    {
        if(g[node][i] && i != p)
        {
            c.push_back(i);
        }
    }
    board[p][node] = 1;
    int len = c.size();
    if(len < 2) { return 1; }
    for(i = 0; i < len; ++i)
    {
        a.push_back(nr(node, c[i]));
    }
    sort(a.begin(), a.end());
    board[p][node] = 1 + a[len - 1] + a[len - 2];
    return board[p][node];
}
inline int remove(int root)
{
    int i = 0;
    vector<int> c;
    vector<int> s;
    for(i = 1; i <= n; ++i)
    {
        if(g[root][i]) { s.push_back(i); }
    }
    int len = s.size();
    if(len < 2) { return 1; }
    for(i = 0; i < len; ++i)
    {
        c.push_back(nr(root, s[i]));
    }
    sort(c.begin(), c.end());
    return 1 + c[len - 1] + c[len - 2];
}
inline int solve()
{
    int root = -1;
    int temp = 0;
    int rmax = -1;
    for(root = 1; root <= n; ++root)
    {
        temp = remove(root);
        if(temp > rmax)
        {
            rmax = temp;
        }
        if(rmax == n) { break; }
    }
    return n - rmax;
}
int main()
{
    int t = 0;        
    int i = 0, j = 0;
    int s = 0, e = 0;

    FILE* in = freopen("E:/Projects/lab/lab/file/B-large-practice.in", "r", stdin);
    FILE* out = freopen("E:/Projects/lab/lab/file/B-large-practice.out", "w", stdout);

    fscanf(in, "%d", &t);

    for(i = 0; i < t; i++)
    {
        fscanf(in, "%d", &n);
        memset(g, 0, sizeof(g));
        memset(board, 0xff, sizeof(board));
        for(j = 0; j < n - 1; ++j)
        {
            fscanf(in, "%d %d", &s, &e);
            g[s][e] = true;
            g[e][s] = true;
        }
        j = solve();
        fprintf(out, "Case #%d: %d\n", (i + 1), j);
    }

    fclose(out);
    fclose(in);

    return 0;
}