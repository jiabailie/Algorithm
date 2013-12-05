using System;
using System.Collections.Generic;
using System.Text;

public class MiniatureDachshund
{
    public int maxMikan(int[] mikan, int weight)
    {
        int i = 0, j = 0;
        int v = 5000 - weight;
        int[] dp = new int[v + 1];

        for (i = 0; i < mikan.Length; i++)
        {
            for (j = v; j >= 0; j--)
            {
                if (j >= mikan[i])
                {
                    dp[j] = Math.Max(dp[j], dp[j - mikan[i]] + 1);
                }
            }
        }
        return dp[v];
    }
}
