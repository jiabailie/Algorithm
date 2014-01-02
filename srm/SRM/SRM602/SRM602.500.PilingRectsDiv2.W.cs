using System;
using System.Collections.Generic;
using System.Text;

public class PilingRectsDiv2
{
    public int getmax(int[] X, int[] Y, int limit)
    {
        int i = 0, j = 0;
        int m = 0, n = X.Length;
        int t1 = 0, t2 = 0;

        int[] mx = new int[n];
        int[] my = new int[n];
        int[] ct = new int[n];
        int[] max = new int[n];
        bool[] visit = new bool[n];
        Queue<int> queue = new Queue<int>();
        List<int>[] pos = new List<int>[n];
        List<int>[] pre = new List<int>[n];

        for (i = 0; i < n; i++)
        {
            if (visit[i]) { continue; }
            if (X[i] * Y[i] >= limit)
            {
                mx[m] = X[i] <= Y[i] ? X[i] : Y[i];
                my[m] = X[i] >= Y[i] ? X[i] : Y[i];
                ct[m] = 1;

                visit[i] = true;
                for (j = i + 1; j < n; j++)
                {
                    if (visit[j]) { continue; }

                    if ((X[i] == X[j] && Y[i] == Y[j]) || (X[i] == Y[j]) && (Y[i] == X[j]))
                    {
                        visit[j] = true;
                        ct[m] = ct[m] + 1;
                    }
                }
                m = m + 1;
            }
        }

        if (m == 0) { return -1; }
        if (m == 1) { return ct[0]; }

        for (i = 0; i < m; i++)
        {
            pos[i] = new List<int>();
            pre[i] = new List<int>();
            max[i] = -1;
        }

        for (i = 0; i < m; i++)
        {
            t1 = int.MaxValue;

            for (j = 0; j < m; j++)
            {
                if (j == i) { continue; }
                t2 = mx[j] + my[j] - mx[i] - my[i];
                if (mx[i] <= mx[j] && my[i] <= my[j])
                {
                    if (t2 < t1)
                    {
                        t1 = t2;
                        pos[i].Clear();
                        pos[i].Add(j);
                    }
                    else if (t2 == t1)
                    {
                        pos[i].Add(j);
                    }
                }
            }

            if (pos[i].Count > 0)
            {
                foreach (int x in pos[i])
                {
                    pre[x].Add(i);
                }
            }
        }

        for (i = 0; i < m; i++)
        {
            if (pre[i].Count == 0)
            {
                queue.Enqueue(i);
                max[i] = ct[i];

                while (queue.Count > 0)
                {
                    t1 = queue.Dequeue();
                    if (pos[t1].Count > 0)
                    {
                        foreach (int x in pos[t1])
                        {
                            max[x] = Math.Max(max[x], max[t1] + ct[x]);
                            queue.Enqueue(x);
                        }
                    }
                }
            }
        }

        for (t1 = -1, i = 0; i < m; i++)
        {
            if (max[i] > t1)
            {
                t1 = max[i];
            }
        }

        return t1;
    }
}
