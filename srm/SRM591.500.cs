using System;
using System.Collections.Generic;
using System.Text;

public class ConvertibleStrings
{
    private int minChange = int.MaxValue;
    private string ga = null;
    private string gb = null;

    private void swap(ref char a, ref char b) { char c = a; a = b; b = c; }

    private void permutation(int c, int n, char[] ca)
    {
        if (minChange == 0) { return; }
        if (c == n)
        {
            int cnt = 0;
            for (int i = 0; i < ga.Length; i++)
            {
                if (ga[i] != ca[gb[i] - 'A']) { cnt++; }
            }
            if (cnt < minChange) { minChange = cnt; }
            return;
        }
        for (int i = c; i < n; i++)
        {
            if (i != c) { swap(ref ca[i], ref ca[c]); }
            permutation(c + 1, n, ca);
            if (i != c) { swap(ref ca[i], ref ca[c]); }
        }
    }

    public int leastRemovals(string A, string B)
    {
        int i = 0;
        ga = A;
        gb = B;
        char[] p = new char[9];
        for (i = 0; i < 9; i++) { p[i] = (char)('A' + i); }
        permutation(0, 9, p);

        return minChange;
    }
}
