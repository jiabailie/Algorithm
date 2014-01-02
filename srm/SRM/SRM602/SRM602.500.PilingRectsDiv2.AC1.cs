using System;
using System.Collections.Generic;
using System.Text;

public class PilingRectsDiv2
{
    private int maxintersection(int x1, int y1, int x2, int y2)
    {
        int area1 = Math.Min(x1, x2) * Math.Min(y1, y2);
        int area2 = Math.Min(x1, y2) * Math.Min(y1, x2);

        return Math.Max(area1, area2);
    }

    public int getmax(int[] X, int[] Y, int limit)
    {
        bool legal = true;
        int i = 0, j = 0, k = 0;
        int m = 0, n = X.Length;

        int[] mx = new int[n];
        int[] my = new int[n];
        List<int> set = new List<int>();

        for (i = 0; i < n; i++)
        {
            if (X[i] * Y[i] >= limit)
            {
                mx[m] = X[i] <= Y[i] ? X[i] : Y[i];
                my[m] = X[i] >= Y[i] ? X[i] : Y[i];

                m = m + 1;
            }
        }

        if (m == 0) { return -1; }
        if (m == 1) { return 1; }

        int[,] intersection = new int[m, m];

        for (i = 0; i < m - 1; i++)
        {
            for (j = i + 1; j < m; j++)
            {
                intersection[i, j] = intersection[j, i] = maxintersection(mx[i], my[i], mx[j], my[j]);
            }
        }

        n = 0;
        for (i = 0; i < m; i++)
        {
            set.Clear();
            bool[] visit = new bool[m];

            set.Add(i);
            visit[i] = true;

            while (true)
            {
                for (j = 0; j < m; j++)
                {
                    if (!visit[j])
                    {
                        legal = true;
                        for (k = 0; k < set.Count && legal; k++)
                        {
                            if (intersection[set[k], j] < limit)
                            {
                                legal = false;
                            }
                        }
                        if (legal)
                        {
                            visit[j] = true;
                            set.Add(j);
                            break;
                        }
                    }
                }
                if (j == m)
                {
                    break;
                }
            }
            if (set.Count > n)
            {
                n = set.Count;
            }
        }

        return n;
    }
}
