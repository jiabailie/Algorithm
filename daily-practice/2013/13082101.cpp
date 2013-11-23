#include <cstdio>
#include <iostream>

using namespace std;

int getMax(int c, int d)
{
    int a[3];
    int b[3];
    int max = 10;
    int res = 0;
    bool find = false;
    for(a[0] = 0; a[0] <=max; a[0]++) // a1
    {
        for(a[1] = 0; a[1] <=max; a[1]++) // a2
        {
            for(a[2] = 0; a[2] <=max; a[2]++) // a3
            {
                for(b[0] = 0; b[0] <=max; b[0]++) // b1
                {
                    for(b[1] = 0; b[1] <=max; b[1]++) // b2
                    {
                        for(b[2] = 0; b[2] <=max; b[2]++) // b3
                        {
                            int r1 = (a[1] - a[0]) * c + (b[1] - b[0]) * d;
                            int r2 = (a[2] - a[1]) * c + (b[2] - b[1]) * d;
                            int r3 = (a[2] - a[0]) * c + (b[3] - b[0]) * d;
                            if(r1 == 1 && r2 == 1 && r3 == 2)
                            {
                                tmp = a[0] * c + b[0] * d - 1;
                                find = true;
                            }
                        }
                    }
                }
            }
        }
    }
    if(!find)
    {
        res = (c < d ? c : d) - 1;
    }

    return res;
}

int main()
{
    int i = 0;
    int T = 0;
    int c = 0, d = 0;

    scanf("%d", &T);
    for(i = 0; i < T; i++)
    {
        scanf("%d %d", &c, &d);
        printf("%d\n", getMax(c, d));
    }
    return 0;
}
