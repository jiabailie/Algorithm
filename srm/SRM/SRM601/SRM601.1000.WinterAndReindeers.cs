using System;
using System.Collections.Generic;
using System.Text;

public class WinterAndReindeers
{
    private int[] findpos(string x, string y)
    {
        bool ok = false;
        int i = 0, j = 0, pos = 0;
        int[] position = new int[x.Length + 7];

        for (i = 0; i < x.Length; i++)
        {
            pos = i;
            ok = true;

            for (j = 0; j < y.Length && ok; j++)
            {
                while (pos < x.Length && y[j] != x[pos]) { pos++; }
                if (pos == x.Length) { ok = false; }
                if (pos < x.Length) { pos++; }
            }
            if (!ok) { pos = x.Length; }
            else { pos--; }
            position[i] = pos;
        }
        return position;
    }

    public int getNumber(string[] allA, string[] allB, string[] allC)
    {
        int i = 0, j = 0;
        int ii = 0, jj = 0;
        int a = 0, b = 0, c = 0;
        int res = 0;
        string sa = "", sb = "", sc = "";

        foreach (string s in allA) { sa += s; }
        foreach (string s in allB) { sb += s; }
        foreach (string s in allC) { sc += s; }

        a = sa.Length;
        b = sb.Length;
        c = sc.Length;

        int[] apos = findpos(sa, sc);
        int[] bpos = findpos(sb, sc);

        int[,] dleft = new int[a + 7, b + 7];
        int[,] dright = new int[a + 7, b + 7];

        for (i = 0; i <= a; i++)
        {
            for (j = 0; j <= b; j++)
            {
                if (i == 0 || j == 0)
                {
                    dleft[i, j] = 0;
                }
                else
                {
                    dleft[i, j] = 0;
                    dleft[i, j] = Math.Max(dleft[i, j], dleft[i - 1, j]);
                    dleft[i, j] = Math.Max(dleft[i, j], dleft[i, j - 1]);
                    if (sa[i - 1] == sb[j - 1])
                    {
                        dleft[i, j] = Math.Max(dleft[i, j], dleft[i - 1, j - 1] + 1);
                    }
                }
            }
        }

        for (i = a; i >= 0; i--)
        {
            for (j = b; j >= 0; j--)
            {
                if (i == a || j == b)
                {
                    dright[i, j] = 0;
                }
                else
                {
                    dright[i, j] = 0;
                    dright[i, j] = Math.Max(dright[i, j], dright[i + 1, j]);
                    dright[i, j] = Math.Max(dright[i, j], dright[i, j + 1]);
                    if (sa[i] == sb[j])
                    {
                        dright[i, j] = Math.Max(dright[i, j], dright[i + 1, j + 1] + 1);
                    }
                }
            }
        }

        for (i = 0; i < a; i++)
        {
            for (j = 0; j < b; j++)
            {
                ii = apos[i];
                jj = bpos[j];
                if (ii == a || jj == b) { continue; }
                res = Math.Max(res, dleft[i, j] + dright[ii + 1, jj + 1] + c);
            }
        }

        return res;
    }
}
