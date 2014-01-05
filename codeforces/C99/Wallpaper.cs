using System;
using System.Collections.Generic;
using System.Text;

public class Wallpaper
{
    private static long cal(long l, long w, long h, long x, long y, long price)
    {
        long s = (x * y) / h;
        long p = (2 * (l + w) + s - 1) / s;
        return price * p;
    }
    public Wallpaper()
    {
        int i = 0;
        int j = 0;
        long t = 0;
        long z = 0;
        int n = Convert.ToInt32(Console.ReadLine());
        long c = 0;
        long[,] area = new long[n, 3];
        string[] s = null;

        for (i = 0; i < n; i++)
        {
            s = Console.ReadLine().Trim().Split(' ');
            area[i, 0] = Convert.ToInt64(s[0]);
            area[i, 1] = Convert.ToInt64(s[1]);
            area[i, 2] = Convert.ToInt64(s[2]);
        }
        int m = Convert.ToInt32(Console.ReadLine());
        long[,] p = new long[m, 3];
        for (i = 0; i < m; i++)
        {
            s = Console.ReadLine().Trim().Split(' ');
            p[i, 0] = Convert.ToInt64(s[0]);
            p[i, 1] = Convert.ToInt64(s[1]);
            p[i, 2] = Convert.ToInt64(s[2]);
        }

        for (i = 0; i < n; i++)
        {
            t = int.MaxValue;
            for (j = 0; j < m; j++)
            {
                z = cal(area[i, 0], area[i, 1], area[i, 2], p[j, 0], p[j, 1], p[j, 2]);
                if (z < t)
                {
                    t = z;
                }
            }
            c += t;
        }
        Console.WriteLine(c);
    }
}
