using System;
using System.Collections.Generic;

public class LCMSetEasy
{
    private long gcd(long a, long b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    private long lcm(long a, long b)
    {
        if (a < b)
        {
            return lcm(b, a);
        }
        return (a / gcd(a, b)) * b;
    }

    public string include(int[] S, int x)
    {
        List<long> div = new List<long>();

        foreach (int y in S)
        {
            if (x % y == 0)
            {
                div.Add(Convert.ToInt64(y));
            }
        }

        if (div.Count == 0)
        {
            return "Impossible";
        }

        long ret = 1;
        foreach (long y in div)
        {
            ret = lcm(ret, y);
        }
        return ret == x ? "Possible" : "Impossible";
    }
}