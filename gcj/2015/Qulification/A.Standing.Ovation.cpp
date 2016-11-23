#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <vector>
#include <map>

using namespace std;

int Solve(int nMax, const char *pszShyest)
{
    int ret = 0;
    int standing = 0;

    for(size_t i = 0; i < strlen(pszShyest); ++i)
    {
        int nLevelI = int(pszShyest[i] - '0');
        if(standing < i)
        {
            ret += i - standing;
            standing += i - standing;
        }
        standing += nLevelI;
    } 
    return ret;
}

int main()
{
    int t = 0;	
    int i = 0;

    FILE* in = freopen("/home/ruyan/Documents/Files/A-large-practice.in", "r", stdin);
    FILE* out = freopen("/home/ruyan/Documents/Files/A-large-practice.out", "w", stdout);

    fscanf(in, "%d", &t);

    for(i = 0; i < t; i++)
    {
        int nMax = 0;
        char pszShyest[1024];

	fscanf(in, "%d %s", &nMax, pszShyest);

        int ret = Solve(nMax, pszShyest);
        fprintf(out, "Case #%d: %d\n", (i + 1), ret);
    }

    fclose(out);
    fclose(in);

    return 0;
}
