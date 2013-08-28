using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

public class dijkstra
{
    public static void findShortestPath(int start, int end, int n, int[,] map, ref int[] path)
    {
        int i = 0, j = 0;
        int[] cost = new int[n];
        List<int> ipath = new List<int>();
        for (i = 0; i < n; i++)
        {
            cost[i] = int.MaxValue;
        }
        cost[start] = 0;
        path[start] = start;

        /* Find the shortest path. */
        for (i = 0; i < n; i++)
        {
            for (j = 1; j < n; j++)
            {
                if (i != j && map[i, j] > 0 && cost[j] > cost[i] + map[i, j])
                {
                    cost[j] = cost[i] + map[i, j];
                    path[j] = i;
                }
            }
        }

        /* Print the full path. */
        i = end;
        ipath.Add(i);
        while (i != start)
        {
            ipath.Add(path[i]);
            i = path[i];
        }
        for (i = ipath.Count - 1; i >= 0; i--)
        {
            Console.Write(ipath[i] + " ");
        }
    }

    public static void test()
    {
        const int n = 6;
        int[,] map = new int[n, n] { 
            { 0, 7, 9, 0, 0, 14 }, 
            { 7, 0, 10, 15, 0, 0 }, 
            { 9, 10, 0, 11, 0, 2 }, 
            { 0, 15, 11, 0, 6, 0 }, 
            { 0, 0, 0, 6, 0, 9 }, 
            { 14, 0, 2, 0, 9, 0 } };
        int[] path = new int[n];
        findShortestPath(0, 4, n, map, ref path);
    }
}