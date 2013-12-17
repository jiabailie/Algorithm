using System;
using System.Collections.Generic;
using System.Text;

public class AstronomicalRecords
{
    private int getNum(long[] A, long[] B)
    {
        int i = 0, j = 0;
        int[,] dp = new int[A.Length + 1, B.Length + 1];

        for (i = 1; i <= A.Length; i++)
        {
            for (j = 1; j <= B.Length; j++)
            {
                if (A[i - 1] == B[j - 1]) { dp[i, j] = dp[i - 1, j - 1] + 1; }
                else { dp[i, j] = Math.Max(dp[i - 1, j], dp[i, j - 1]); }
            }
        }
        return A.Length + B.Length - dp[A.Length, B.Length];
    }
    public int minimalPlanets(int[] A, int[] B)
    {
        long l = 1;
        int i = 0, j = 0;
        int la = A.Length, lb = B.Length;
        int res = la + lb;
        long[][] cA = new long[lb][];
        long[] cB = new long[lb];

        for (i = 0; i < lb; i++)
        {
            cA[i] = new long[la];
            for (j = 0; j < la; j++)
            {
                cA[i][j] = l * A[j] * B[i];
            }
        }

        foreach (int x in A)
        {
            for (i = 0; i < lb; i++) { cB[i] = l * B[i] * x; }
            for (i = 0; i < lb; i++)
            {
                res = Math.Min(res, getNum(cA[i], cB));
            }
        }
        return res;
    }
}
