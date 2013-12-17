using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class BadNeighbors
{
    private int iMax(int x, int y)
    {
        return x > y ? x : y;
    }

    public int maxDonations(int[] donations)
    {
        int i = 0;
        int n = donations.Length;
        int[, ,] dp = new int[n, 2, 2];

        dp[0, 0, 0] = 0;
        dp[0, 0, 1] = 0;
        dp[0, 1, 0] = 0;
        dp[0, 1, 1] = donations[0];

        for (i = 1; i < n - 1; i++)
        {
            dp[i, 0, 0] = iMax(dp[i - 1, 0, 0], dp[i - 1, 1, 0]);
            dp[i, 0, 1] = iMax(dp[i - 1, 0, 1], dp[i - 1, 1, 1]);
            dp[i, 1, 0] = dp[i - 1, 0, 0] + donations[i];
            dp[i, 1, 1] = dp[i - 1, 0, 1] + donations[i];
        }
        dp[n - 1, 0, 0] = iMax(dp[n - 2, 0, 0], dp[n - 2, 1, 0]);
        dp[n - 1, 0, 1] = iMax(dp[n - 2, 0, 1], dp[n - 2, 1, 1]);
        dp[n - 1, 1, 0] = dp[n - 2, 0, 0] + donations[n - 1];
        dp[n - 1, 1, 1] = dp[n - 2, 0, 1];

        return iMax(iMax(dp[n - 1, 0, 0], dp[n - 1, 0, 1]), iMax(dp[n - 1, 1, 0], dp[n - 1, 1, 1]));
    }
}
