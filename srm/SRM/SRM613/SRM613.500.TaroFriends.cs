using System;

public class TaroFriends
{
    public int getNumber(int[] coordinates, int X)
    {
        int i = 0, j = 0;
        int min = 0, max = 0;
        int n = coordinates.Length;
        int[] r = new int[n];
        int[] l = new int[n];
        int ret = int.MaxValue;

        Array.Sort(coordinates);
        for (i = 0; i < n; ++i)
        {
            r[i] = coordinates[i] + X;
            l[i] = coordinates[i] - X;
        }

        for (i = 0; i < n; ++i)
        {
            min = int.MaxValue;
            max = int.MinValue;
            for (j = 0; j < i; ++j)
            {
                if (r[j] < min)
                {
                    min = r[j];
                }
                if (r[j] > max)
                {
                    max = r[j];
                }
            }
            for (j = i; j < n; ++j)
            {
                if (l[j] < min)
                {
                    min = l[j];
                }
                if (l[j] > max)
                {
                    max = l[j];
                }
            }

            if (max - min < ret)
            {
                ret = max - min;
            }
        }
        return ret;
    }
}