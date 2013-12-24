using System;
using System.Collections.Generic;
using System.Text;

public class WinterAndCandies
{
    public int getNumber(int[] type)
    {
        int i = 0, j = 0;
        int ret = 0, t = 0;
        int[] cnt = new int[51];

        for (i = 0; i < type.Length; i++)
        {
            cnt[type[i]]++;
        }

        for (i = 1; i <= 50; i++)
        {
            t = 1;
            for (j = 1; j <= i; j++)
            {
                t *= cnt[j];
            }
            ret += t;
        }
        return ret;
    }
}
