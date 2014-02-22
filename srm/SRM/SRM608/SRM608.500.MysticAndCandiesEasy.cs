using System;
public class MysticAndCandiesEasy
{
    public int minBoxes(int C, int X, int[] high)
    {
        int sum = 0, b = 0;
        int t = 0, n = high.Length;

        foreach (int x in high) { sum += x; }

        Array.Sort(high);

        for (t = 1; t < high.Length; ++t)
        {
            b += high[n - t];
            if (C - sum + b >= X)
            {
                return t;
            }
        }
        return high.Length;
    }
}
