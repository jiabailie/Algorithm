using System;
using System.Collections.Generic;
using System.Text;

public class WinterAndReindeers
{
    private string a = null;
    private string b = null;
    private string c = null;
    private int[,] dp = null;

    private string composestring(string[] ss)
    {
        StringBuilder sb = new StringBuilder();
        foreach (string s in ss)
        {
            sb.Append(s);
        }
        return sb.ToString();
    }

    private int lcs(string x, string y)
    {
        if (x.Length * y.Length == 0) { return 0; }

        int i = 0, j = 0;
        dp = new int[x.Length + 1, y.Length + 1];
        for (i = 0; i < x.Length; i++)
        {
            for (j = 0; j < y.Length; j++)
            {
                if (x[i] == y[j])
                {
                    dp[i + 1, j + 1] = dp[i, j] + 1;
                }
                else
                {
                    dp[i + 1, j + 1] = Math.Max(dp[i + 1, j], dp[i, j + 1]);
                }
            }
        }

        return dp[x.Length, y.Length];
    }

    private Dictionary<int, int> getpos(string x, string y)
    {
        int i = 0, j = 0, k = 0;
        Dictionary<int, int> pos = new Dictionary<int, int>();

        for (i = 0; i < x.Length; i++)
        {
            if (x[i] == y[0])
            {
                j = i;
                k = 0;
                while (j < x.Length && k < y.Length)
                {
                    for (; j < x.Length && x[j] != y[k]; j++) ;
                    j++;
                    k++;
                }
                if (k == y.Length)
                {
                    pos.Add(i, j);
                }
            }
        }
        return pos;
    }

    public int getNumber(string[] allA, string[] allB, string[] allC)
    {
        int ret = 0, max = int.MinValue;
        int k = 0, l = 0;
        a = composestring(allA);
        b = composestring(allB);
        c = composestring(allC);
        if (c.Length > a.Length || c.Length > b.Length) { return 0; }

        if (lcs(a, c) == c.Length && lcs(b, c) == c.Length)
        {
            l = lcs(a, b);
            Dictionary<int, int> apos = getpos(a, c);
            Dictionary<int, int> bpos = getpos(b, c);

            foreach (KeyValuePair<int, int> akvp in apos)
            {
                foreach (KeyValuePair<int, int> bkvp in bpos)
                {
                    k = dp[akvp.Key, bkvp.Key];

                    if (akvp.Value != a.Length && bkvp.Value != b.Length)
                    {
                        k += l - dp[akvp.Value, bkvp.Value];
                    }

                    if (k > max)
                    {
                        max = k;
                    }
                }
            }

            ret = c.Length + max;
        }

        return ret;
    }
}
