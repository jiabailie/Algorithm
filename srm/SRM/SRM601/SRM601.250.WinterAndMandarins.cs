using System;
using System.Collections.Generic;
using System.Text;

public class WinterAndMandarins
{
    public int getNumber(int[] bags, int K)
    {
        int i = 0;
        int tmp = 0, min = int.MaxValue;
        Array.Sort(bags);

        for (i = K - 1; i < bags.Length; i++)
        {
            tmp = bags[i] - bags[i + 1 - K];
            if (tmp < min) { min = tmp; }
        }
        return min;
    }
}
