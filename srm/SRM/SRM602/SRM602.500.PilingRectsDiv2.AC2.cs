using System;
using System.Collections.Generic;
using System.Text;

public class PilingRectsDiv2
{
    private int n = 0;
    private int[] gx = new int[210];
    private int[] gy = new int[210];
    private int calc(int x, int y)
    {
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            if ((x <= gx[i] && y <= gy[i]) || (x <= gy[i] && y <= gx[i]))
            {
                ret++;
            }
        }
        return ret;
    }
    public int getmax(int[] X, int[] Y, int limit)
    {
        n = X.Length;
        int max = -1;
        int i = 0, j = 0, k = 0;

        for (i = 0; i < n; i++)
        {
            gx[i] = X[i];
            gy[i] = Y[i];
        }

        for (i = 1; i <= 200; i++)
        {
            for (j = 1; j <= 200; j++)
            {
                k = calc(i, j);
                if (i * j >= limit)
                {
                    if (k > 0 && k > max)
                    {
                        max = k;
                    }
                }
            }
        }

        return max;
    }
}
