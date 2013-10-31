using System;
using System.Collections.Generic;
using System.Text;

public class LittleElephantAndXor
{
    private int len = 32;
    private char[] sa = null;
    private char[] sb = null;
    private char[] sc = null;
    private long[, , ,] dp = null;

    private long solve(int t, int eA, int eB, int eC)
    {
        if (dp[t, eA, eB, eC] == -1)
        {
            dp[t, eA, eB, eC] = 0;
            if (t == len - 1)
            {
                dp[t, eA, eB, eC] = 1;
            }
            else
            {
                dp[t, eA, eB, eC] = 0;
                for (int i = 0; i < 2; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        int k = i ^ j;
                        if ((eA == 0 || i <= (sa[t + 1] - '0')) &&
                            (eB == 0 || j <= (sb[t + 1] - '0')) &&
                            (eC == 0 || k <= (sc[t + 1] - '0')))
                        {
                            dp[t, eA, eB, eC] += solve(
                                t + 1,
                                (eA == 1 && i == (sa[t + 1] - '0')) ? 1 : 0,
                                (eB == 1 && j == (sb[t + 1] - '0')) ? 1 : 0,
                                (eC == 1 && k == (sc[t + 1] - '0')) ? 1 : 0);
                        }
                    }
                }
            }
        }
        return dp[t, eA, eB, eC];
    }

    public long getNumber(int A, int B, int C)
    {
        sa = Convert.ToString(A, 2).PadLeft(len, '0').ToCharArray();
        sb = Convert.ToString(B, 2).PadLeft(len, '0').ToCharArray();
        sc = Convert.ToString(C, 2).PadLeft(len, '0').ToCharArray();

        dp = new long[len + 1, 2, 2, 2];

        for (int i = 0; i <= len; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int m = 0; m < 2; m++)
                {
                    for (int n = 0; n < 2; n++)
                    {
                        dp[i, j, m, n] = -1;
                    }
                }
            }
        }

        return solve(0, 1, 1, 1);
    }
}
