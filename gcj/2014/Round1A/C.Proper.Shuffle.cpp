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

int n = 0;
int arr[1000];
inline int iabs(int x) { return x > 0 ? x : -x; }
inline string solve()
{
    int i = 0, j = 0;
    vector<int> pos(n, 0);
    vector<int> minus;
    for(i = 0; i < n; ++i)
    {        
        pos[arr[i]] = i;
        minus.push_back(iabs(arr[i] - i));
    }
    for(i = 0; i < n; ++i)
    {
        if(pos[i] == i)
        {
            return "BAD";
        }
    }
    for(i = 0; i < minus.size() - 1; ++i)
    {
        if(minus[i] == minus[i + 1])
        {
            return "BAD";
        }
    }
    return "GOOD";
}
int main()
{
    int t = 0;        
    int i = 0, j = 0;

    FILE* in = freopen("D:/Lab/Contests/Contests/file/C-small-attempt2.in", "r", stdin);
    FILE* out = freopen("D:/Lab/Contests/Contests/file/C-small-attempt2.out", "w", stdout);

    fscanf(in, "%d", &t);

    for(i = 0; i < t; i++)
    {
        fscanf(in, "%d", &n);
        if(n == 1)
        {
            fprintf(out, "Case #%d: %s\n", (i + 1), "GOOD");
        }
        for(j = 0; j < n; ++j)
        {
            fscanf(in, "%d", &arr[j]);
        }
        fprintf(out, "Case #%d: %s\n", (i + 1), solve().c_str());
    }

    fclose(out);
    fclose(in);

    return 0;
}