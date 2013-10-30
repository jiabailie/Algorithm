using System;
using System.Collections.Generic;
using System.Text;

public class LittleElephantAndXor
{
    private int len = 32;
    private string sa = null;
    private string sb = null;
    private string sc = null;
    private long[, , ,] dp = null;

    private string reverse(string s)
    {
        string ret = "";
        for (int i = s.Length - 1; i >= 0; i--) { ret += s[i]; }
        return ret;
    }

    private long solve(int t, int eA, int eB, int eC)
    {
        int i = 0, j = 0, k = 0;
        if (dp[t, eA, eB, eC] == -1)
        {
            dp[t, eA, eB, eC] = 0;
            if (t == 0)
            {
                dp[t, eA, eB, eC] = 1;
            }
            else
            {
                dp[t, eA, eB, eC] = 0;
                for (i = 0; i < 2; i++)
                {
                    for (j = 0; j < 2; j++)
                    {
                        k = i ^ j;
                        if ((eA == 0 || i <= (sa[t - 1] - '0')) &&
                            (eB == 0 || j <= (sb[t - 1] - '0')) &&
                            (eC == 0 || k <= (sc[t - 1] - '0')))
                        {
                            dp[t, eA, eB, eC] += solve(
                                t - 1,
                                (eA == 1 && i == (sa[t - 1] - '0')) ? 1 : 0,
                                (eB == 1 && j == (sb[t - 1] - '0')) ? 1 : 0,
                                (eC == 1 && k == (sc[t - 1] - '0')) ? 1 : 0);
                        }
                    }
                }
            }
        }
        return dp[t, eA, eB, eC];
    }

    public long getNumber(int A, int B, int C)
    {
        int i = 0, j = 0, m = 0, n = 0;
        sa = Convert.ToString(A, 2);
        sb = Convert.ToString(B, 2);
        sc = Convert.ToString(C, 2);
        sa = sa.PadLeft(len, '0');
        sb = sb.PadLeft(len, '0');
        sc = sc.PadLeft(len, '0');

        sa = reverse(sa);
        sb = reverse(sb);
        sc = reverse(sc);

        dp = new long[len + 1, 2, 2, 2];

        for (i = 0; i <= len; i++)
        {
            for (j = 0; j < 2; j++)
            {
                for (m = 0; m < 2; m++)
                {
                    for (n = 0; n < 2; n++) { dp[i, j, m, n] = -1; }
                }
            }
        }

        return solve(len, 1, 1, 1);
    }
}
