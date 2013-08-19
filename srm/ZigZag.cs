using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class ZigZag
{
    public int longestZigZag(int[] sequence)
    {
        int n = sequence.Length;

        if (n < 3)
        {
            return n;
        }
        int i = 0, j = 0;
        int[] dp = new int[n];
        int[] sign = new int[n];
        dp[0] = 1;
        dp[1] = 2;
        for (i = 1; i < n; i++)
        {
            sign[i] = sequence[i] - sequence[i - 1] > 0 ? 1 : -1;
        }
        for (i = 2; i < n; i++)
        {
            for (j = i - 1; j >= 0; j--)
            {
                if (sign[i] * sign[j] == -1)
                {
                    dp[i] = dp[j] + 1;
                    break;
                }
            }
        }
        return dp[n - 1];
    }
}

