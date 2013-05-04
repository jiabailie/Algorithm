/*
given a number, return possible combinations of constructing that number with 1,2 and 3
e.g.
input: 12 --> output: 19,

Input: 8 --> Output: 10
Explanation - Following are the possible combinations for team score of 8
1x8
1x6 + 2x1
1x4 + 2x2
1x2 + 2x3
2x4
1x5 + 3x1
1x3 + 2x1 + 3x1
1x1 + 2x2 + 3x1
1x2 + 3x2
2x1 + 3x2
*/
#include <cstdio>
#include <iostream>
using namespace std;

int find1(int n)
{
    int i = 0, j = 0, ret = 0;
    for(i = 0; i <= n / 3; i++)
    {
        for(j = 0; j <= n / 2; j++)
        {
            if(i * 3 + j * 2 <= n)
            {
                ret++;
            }
        }
    }
    return ret;
}

int find2(int n)
{
    int i = 0, ret = 0;
    for(i = 0; i <= n / 3; i++)
    {
        ret += 1 + (n - 3 * i) / 2;
    }
    return ret;
}

int main()
{
    int n = 0;
    cin >> n;
    cout << find1(n) << " " << find2(n);
    return 0;
}
