#include <stdio.h>
#include <string.h>

int main()
{
    int t = 0;
    int l = 0;
    int i = 0, j = 0;
    int rec[128];
    char in[1005];

    scanf("%d", &t);

    for(i = 0; i < t; i++)
    {
        scanf("%s", in);
        l = strlen(in);

        memset(rec, 0, sizeof(rec));
        for(j = 0; j < l / 2; j++)
        {
            rec[(int)in[j]] += 1;
        }
        if(l % 2 == 1) { rec[(int)in[l / 2]] += 1; }
        for(j = l / 2; j < l; j++)
        {
            rec[(int)in[j]] -= 1;
            if(rec[(int)in[j]] < 0)
            {
                printf("NO\n");
                break;
            }
        }
        if(j == l)
        {
            printf("YES\n");
        }
    }
    return 0;
}

