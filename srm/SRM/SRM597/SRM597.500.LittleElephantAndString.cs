using System;
using System.Collections.Generic;
using System.Text;

public class LittleElephantAndString
{
    public int getNumber(string A, string B)
    {
        if (A == B) { return 0; }

        int i = 0, j = 0;
        int n = A.Length;
        int[,] cnt = new int[26, 2];

        for (i = 0; i < n; i++)
        {
            cnt[A[i] - 'A', 0] += 1;
            cnt[B[i] - 'A', 1] += 1;
        }
        for (i = 0; i < 26 && cnt[i, 0] == cnt[i, 1]; i++) ;
        if (i < 26) { return -1; }

        for (i = n - 1, j = n - 1; i >= 0 && j >= 0; i--)
        {
            if (A[i] == B[j])
            {
                j--;
            }
        }

        return j + 1;
    }
}
