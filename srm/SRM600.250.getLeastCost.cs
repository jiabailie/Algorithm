using System;
using System.Collections.Generic;
using System.Text;

public class TheShuttles
{
    public int getLeastCost(int[] cnt, int baseCost, int seatCost)
    {
        int i = 0, j = 0;
        int n = cnt.Length;
        int cost = int.MaxValue;
        int tmpcost = 0;
        int shuttleCnt = 0;
        int maxseat = 0;

        Array.Sort(cnt);

        maxseat = cnt[n - 1];

        for (i = 1; i <= maxseat; i++)
        {
            shuttleCnt = 0;
            for (j = 0; j < n; j++)
            {
                shuttleCnt += (cnt[j] + i - 1) / i;
            }
            tmpcost = shuttleCnt * (baseCost + seatCost * i);
            if (tmpcost < cost)
            {
                cost = tmpcost;
            }
        }
        return cost;
    }
}
