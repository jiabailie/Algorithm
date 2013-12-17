/*References: apps.topcoder.com/wiki/display/tc/SRM+596 */
using System;
using System.Collections.Generic;
using System.Text;

public class ColorfulRoad
{
    public int getMin(string road)
    {
        int i = 0, j = 0;
        int max = 10000;
        int n = road.Length;
        int[] dp = new int[n];
        Dictionary<char, char> next = new Dictionary<char, char>();
        next.Add('R', 'G');
        next.Add('G', 'B');
        next.Add('B', 'R');
        dp[n - 1] = 0;
        for (i = n - 2; i >= 0; i--)
        {
            dp[i] = max;
            for (j = i + 1; j < n; j++)
            {
                if (road[j] == next[road[i]])
                {
                    dp[i] = Math.Min(dp[i], dp[j] + (j - i) * (j - i));
                }
            }
        }
        return dp[0] >= max ? -1 : dp[0];
    }
}
