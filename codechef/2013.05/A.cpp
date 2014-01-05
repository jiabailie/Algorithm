#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

void generateNext(string source, int next[])
{
    int len = source.length();
    memset(next, 0, sizeof(int) * len);
    next[0] = -1;
    if(len == 1) { return; }
    next[1] = 0;
    for(int i = 1; i < len; i++)
    {
        if(source[i] == source[next[i - 1] + 1])
        {
            next[i] = next[i - 1] + 1;
        }
        else
        {
            next[i] = 0;
        }
    }
}

int main()
{
    int m = 0;
    char buf[25001];
    vector<string> con;
    /*
    for(int i = 0; i < 6; i++)
    {
        scanf("%s", buf);
        con.push_back(buf);
    }
    */

    string s = "abcdabd";
    int next[7];
    generateNext(s, next);
    for(int i = 0; i < 7; i++)
    {
        cout << next[i] << " ";
    }

    return 0;
}
