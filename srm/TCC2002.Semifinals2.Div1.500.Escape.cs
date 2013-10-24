/*
 * Description: community.topcoder.com/stat?c=problem_statement&pm=1170&rd=4371
 */
using System;
using System.Collections.Generic;
using System.Text;

public class Escape
{
    private const int n = 501;
    private int[,] map = new int[n, n];

    private void dealArray(int cost, string[] ary)
    {
        int i = 0, j = 0;
        string[] ss = null;
        int[] param = new int[4];
        foreach (string s in ary)
        {
            ss = s.Split(' ');
            for (i = 0; i < 4; i++) { param[i] = Convert.ToInt32(ss[i]); }
            for (i = Math.Min(param[0], param[2]); i <= Math.Max(param[0], param[2]); i++)
            {
                for (j = Math.Min(param[1], param[3]); j <= Math.Max(param[1], param[3]); j++)
                {
                    map[i, j] = cost;
                }
            }
        }
    }

    public int lowest(string[] harmful, string[] deadly)
    {
        int i = 0, j = 0;
        int nx = 0, ny = 0;
        int[] dx = new int[] { 1, -1, 0, 0 };
        int[] dy = new int[] { 0, 0, 1, -1 };
        int[,] cost = new int[n, n];
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                map[i, j] = 0;
                cost[i, j] = 1010;
            }
        }
        dealArray(1, harmful);
        dealArray(2, deadly);

        cost[0, 0] = 0;
        Queue<int> iqueue = new Queue<int>();
        iqueue.Enqueue(0);

        while (iqueue.Count > 0)
        {
            i = iqueue.Dequeue();
            int[] pos = new int[] { i / 1000, i % 1000 }; ;
            for (j = 0; j < 4; j++)
            {
                nx = pos[0] + dx[j];
                ny = pos[1] + dy[j];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx, ny] < 2)
                {
                    if (cost[nx, ny] == 1010)
                    {
                        cost[nx, ny] = cost[pos[0], pos[1]] + map[nx, ny];
                        iqueue.Enqueue(nx * 1000 + ny);
                    }
                    else if (cost[pos[0], pos[1]] + map[nx, ny] < cost[nx, ny])
                    {
                        cost[nx, ny] = cost[pos[0], pos[1]] + map[nx, ny];
                        iqueue.Enqueue(nx * 1000 + ny);
                    }
                }
            }
        }

        return cost[500, 500] == 1010 ? -1 : cost[500, 500];
    }
}
