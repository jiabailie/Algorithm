using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class JumpFurther
{
    public int furthest(int N, int badStep)
    {
        int a = 1 + 8 * badStep;
        int b = Convert.ToInt32(Math.Sqrt(a));
        int c = N * (N + 1) / 2;

        if (b * b == a && b > 0 && b <= N)
        {
            c = c - 1;
        }

        return c;
    }
    //{
    //    int i = 0, j = 0;
    //    int max = -1, t1 = 0, t2 = 0;
    //    int[] f = new int[N + 1];

    //    for (i = 1; i <= N; i++)
    //    {
    //        max = f[0];
    //        for (j = 0; j < i; j++)
    //        {
    //            t1 = f[j];
    //            t2 = f[j] + i;
    //            if (t1 != badStep && t1 > max) { max = t1; }
    //            if (t2 != badStep && t2 > max) { max = t2; }
    //        }
    //        f[i] = max;
    //    }
    //    return f[N];
    //}
}

