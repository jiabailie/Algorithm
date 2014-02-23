using System;
public class PackingBallsDiv2
{
    public int minPacks(int R, int G, int B)
    {
        int res = 100;
        int i = 0, j = 0;
        int t = 0, r = 0;
        int[] p = new int[] { R, G, B };

        for (i = 0; i < 100; ++i)
        {
            t = i;
            for (j = 0; j < 3; ++j)
            {
                r = Math.Max(0, p[j] - i);
                t += (r + 2) / 3;
            }
            res = Math.Min(res, t);
        }
        return res;
    }
}
