#include <stdio.h>
#include <string.h>

double getmax(double a, double b) { return a > b ? a : b; }

int main()
{
    int t = 0;
    int i = 0;
    int j = 0;
    double p = 0.0;
    double t1 = 0.0;
    double t2 = 0.0;
    double max = -1.0;
    scanf("%d", &t);

    for(i = 0; i < t; i++)
    {
        scanf("%f", &p);
        max = -1.0;
        for(j = 0; j <= 10000; j++)
        {
            t1 = (3 - 2 * p) * j * 1.0 - 10000;
            t2 = (3 - 2 * (1 - p)) * j * 1.0 - 10000;
            max = getmax(max, t1 * p + t2 * (1 - p));
            printf("%.6f %.6f\n", t1 ,t2);
        }
        printf("%.6f\n", max);
    }

    return 0;
}
