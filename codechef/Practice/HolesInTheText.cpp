#include <cstdio>
#include <cstring>

using namespace std;

int holes[26] = {
    1, /*A*/    2, /*B*/    0, /*C*/    1, /*D*/    0, /*E*/    0, /*F*/    0, /*G*/    0, /*H*/
    0, /*I*/    0, /*J*/    0, /*K*/    0, /*L*/    0, /*M*/    0, /*N*/    1, /*O*/    1, /*P*/
    1, /*Q*/    1, /*R*/    0, /*S*/    0, /*T*/    0, /*U*/    0, /*V*/    0, /*W*/    0, /*X*/
    0, /*Y*/    0  /*Z*/    };

int main()
{
    int i = 0, j = 0;
    int t = 0, ret = 0;
    char ary[101];

    scanf("%d", &t);
    for(i = 0; i < t; i++)
    {
        ret = 0;
        scanf("%s", &ary);
        for(j = 0; j < strlen(ary); j++)
        {
            ret += holes[ary[j] - 'A'];
        }
        printf("%d\n", ret);
    }

    return 0;
}
