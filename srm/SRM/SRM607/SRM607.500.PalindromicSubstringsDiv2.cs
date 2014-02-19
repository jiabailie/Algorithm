using System;
using System.Text;

public class PalindromicSubstringsDiv2
{
    public int count(string[] S1, string[] S2)
    {
        int ret = 0;
        int i = 0, j = 0;
        int m = 0, n = 0, e = 0;
        StringBuilder sb = new StringBuilder();
        string all = "";
        foreach (string s in S1) { sb.Append(s); }
        foreach (string s in S2) { sb.Append(s); }

        all = sb.ToString();
        n = all.Length;

        for (m = 0; m < n; ++m)
        {
            for (e = 0; e < 2; ++e)
            {
                if (e == 0) // even
                {
                    i = m;
                    j = m + 1;
                }
                else // odd
                {
                    i = m - 1;
                    j = m + 1;
                    ++ret;
                }
                bool p = true;
                while (i >= 0 && j < n && p)
                {
                    p = p & (all[i] == all[j]);
                    if (p) { ++ret; }
                    i--;
                    j++;
                }
            }
        }
        return ret;
    }
}
