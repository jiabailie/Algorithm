/* Description: community.topcoder.com/stat?c=problem_statement&pm=1593&rd=4494 */
using System;
using System.Collections.Generic;
using System.Text;

public class Circuits
{
    public int howLong(string[] connects, string[] costs)
    {
        int i = 0, j = 0, k = 0;
        int t = 0, s = 0;
        int n = connects.Length;
        int[,] graph = new int[n, n];

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++) { graph[i, j] = 0; }
            if (!string.IsNullOrEmpty(connects[i]))
            {
                string[] s1 = connects[i].Split(' ');
                string[] s2 = costs[i].Split(' ');
                for (j = 0; j < s1.Length; j++)
                {
                    t = Convert.ToInt32(s1[j]);
                    s = Convert.ToInt32(s2[j]);
                    if (s > graph[i, t])
                    {
                        graph[i, t] = s;
                    }
                }
            }
        }
        t = int.MinValue;
        for (k = 0; k < n; k++)
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    if (graph[i, k] != 0 && graph[k, j] != 0 && graph[i, k] + graph[k, j] > graph[i, j])
                    {
                        graph[i, j] = graph[i, k] + graph[k, j];
                    }
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i, j] > t) { t = graph[i, j]; }
            }
        }
        return t;
    }
}
