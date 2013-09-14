using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class AvoidRoads
{
    private void orderString(string[] bad, ref int[,] ibad)
    {
        int i = 0, j = 0, t = 0;
        int len = bad.Length;
        for (i = 0; i < len; i++)
        {
            string[] p = bad[i].Split(' ');
            for (j = 0; j < 4; j++)
            {
                ibad[i, j] = Convert.ToInt32(p[j]);
            }
            for (j = 0; j <= 1; j++)
            {
                if (ibad[i, j] > ibad[i, j + 2])
                {
                    t = ibad[i, j];
                    ibad[i, j] = ibad[i, j + 2];
                    ibad[i, j + 2] = t;
                }
            }
        }
    }
    private bool notContainsInBad(int lenBad, int[] path, int[,] bad)
    {
        int i = 0, j = 0;
        bool ret = true;
        for (i = 0; i < lenBad && ret; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (path[j] != bad[i, j]) { break; }
            }
            if (j == 4) { ret = false; }
        }
        return ret;
    }

    public long numWays(int width, int height, string[] bad)
    {
        int i = 0, j = 0;
        int lenBad = bad.Length;
        int[,] ibad = new int[lenBad, 4];
        long[,] ways = new long[width + 1, height + 1];

        orderString(bad, ref ibad);

        for (i = 1; i <= width; i++)
        {
            if (notContainsInBad(lenBad, new int[] { i - 1, 0, i, 0 }, ibad)) { ways[i, 0] = 1; }
            else { break; }
        }
        for (i = 1; i <= height; i++)
        {
            if (notContainsInBad(lenBad, new int[] { 0, i - 1, 0, i }, ibad)) { ways[0, i] = 1; }
            else { break; }
        }

        for (i = 1; i <= width; i++)
        {
            for (j = 1; j <= height; j++)
            {
                ways[i, j] = 0;
                if (notContainsInBad(lenBad, new int[] { i - 1, j, i, j }, ibad))
                {
                    ways[i, j] += ways[i - 1, j];
                }
                if (notContainsInBad(lenBad, new int[] { i, j, i, j - 1 }, ibad))
                {
                    ways[i, j] += ways[i, j - 1];
                }
            }
        }
        return ways[width, height];
    }
}
