// srm593 1000
using System;
using System.Collections.Generic;
using System.Text;

public class MayTheBestPetWin
{
    public int calc(int[] A, int[] B)
    {
        int i = 0, j = 0, n = A.Length;
        int max = 2 * 50 * 10000;
        int[] dp = new int[max + 1];
        int[] sp = new int[n];
        int ta = 0, tb = 0;

        for (i = 0; i < n; i++)
        {
            ta += A[i];
            tb += B[i];
            sp[i] = A[i] + B[i];
        }

        for (i = 0; i < max; i++) { dp[i] = Math.Max(i - ta, tb - i); }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j + sp[i] <= max; j++)
            {
                dp[j] = Math.Min(dp[j], dp[j + sp[i]]);
            }
        }
        return dp[0];
    }
}
