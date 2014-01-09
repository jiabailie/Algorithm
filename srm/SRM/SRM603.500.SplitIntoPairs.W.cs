using System;
using System.Collections.Generic;
using System.Text;

public class SplitIntoPairs
{
    public int makepairs(int[] A, int X)
    {
        int cnt = A.Length / 2;
        int negative = 0;
        int positive = 0;
        long minPositive = long.MaxValue;
        long maxNegative = long.MinValue;

        foreach (int i in A)
        {
            if (i < 0)
            {
                positive++;
                if (i > maxNegative)
                {
                    maxNegative = i;
                }
            }
            else
            {
                negative++;
                if (i < minPositive)
                {
                    minPositive = i;
                }
            }
        }
        if (negative % 2 == 1 && minPositive * maxNegative < X)
        {
            cnt--;
        }
        return cnt;
    }
}
