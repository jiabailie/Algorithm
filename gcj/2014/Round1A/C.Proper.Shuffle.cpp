/**
 * This problem comes from GCJ Round 1A 2014.
 * I finished problem A and B, didn't finish problem C.
 * Reference: naoyat.hatenablog.jp/entry/GCJ2014R1A
 */
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
using namespace std;

int n = 1000;
int a[1000];
int ra[1000];
double at[1000];
double nx[1000];
vector<double> prepare(int w)
{
    int i = 0, pivot = 0;
    double d = 0.0, u = 0.0;
    double g = (double)(n - 1) / n;
    memset(at, 0, sizeof(at));
    at[w] = 1.0;
    
    for(pivot = 0; pivot < n; ++pivot)
    {
        memset(nx, 0, sizeof(nx));
        d = at[pivot] / n;
        for(i = 0; i < n; ++i)
        {
            if(i == pivot)
            {
                continue;
            }
            nx[i] = d + at[i] * g;
        }
        u = 0;
        for(i = 0; i < n; ++i)
        {
            u += at[i];
        }
        nx[pivot] = u / n;
        for(i = 0; i < n; ++i)
        {
            at[i] = nx[i];
        }
    }
    vector<double> lat(n, 0);
    for(i = 0; i < n; ++i)
    {
        lat[i] = log(at[i] * n);
    }
    return lat;
}
int main()
{
    int t = 0;
    int i = 0, j = 0;
    double lsum = 0.0;
    vector<vector<double> > lats(1000, vector<double>(1000));

    FILE* in = freopen("E:/Projects/lab/lab/file/C-small-practice.in", "r", stdin);
    FILE* out = freopen("E:/Projects/lab/lab/file/C-small-practice.out", "w", stdout);    
    
    fscanf(in, "%d", &t);
    for(i = 0; i < 1000; ++i)
    {
        vector<double> lat = prepare(i);
        lats[i].assign(lat.begin(), lat.end());
    }
    for(i = 0; i < t; ++i)
    {
        fscanf(in, "%d", &n);
        memset(a, 0, sizeof(a));
        memset(ra, 0, sizeof(ra));
        for(j = 0; j < n; ++j)
        {
            fscanf(in, "%d", &a[j]);
            ra[a[j]] = j;
        }
        lsum = 0;
        if(n == 1000)
        {
            for(j = 0; j < n; ++j)
            {
                lsum += lats[j][ra[j]];
            }
        }
        else
        {
            for(j = 0; j < n; ++j)
            {
                vector<double> lat = prepare(j);
                lsum += lat[ra[j]];
            }
        }
        if(lsum > log(1.1))
        {
            fprintf(out, "Case #%d: %s\n", (i + 1), "BAD");
        }
        else
        {
            fprintf(out, "Case #%d: %s\n", (i + 1), "GOOD");
        }
    }

    fclose(out);
    fclose(in);

    return 0;
}