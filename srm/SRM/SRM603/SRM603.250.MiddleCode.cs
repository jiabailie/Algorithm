using System;
using System.Collections.Generic;
using System.Text;

public class MiddleCode
{
    private int len = 0;
    private string gs = null;
    private bool[] used = null;

    private int find(int c)
    {
        int i = 0, k = 0;
        for (i = 0; i < len; i++)
        {
            if (!used[i])
            {
                k++;
                if (k == c)
                {
                    break;
                }
            }
        }
        return i;
    }
    public string encode(string s)
    {
        len = s.Length;
        gs = s;
        used = new bool[len];
        string t = "";
        int l = len;
        int c1, c2;
        while (l > 0)
        {
            if (l % 2 == 1)
            {
                c1 = find(l / 2 + 1);
                used[c1] = true;
                t += s[c1];
            }
            else
            {
                c1 = find(l / 2);
                c2 = find(l / 2 + 1);
                if (s[c1] > s[c2])
                {
                    c1 = c2;
                }
                used[c1] = true;
                t += s[c1];
            }
            l -= 1;
        }

        return t;
    }
}
