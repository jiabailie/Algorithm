using System;
using System.Collections.Generic;
using System.Text;

public class FoxAndWord
{
    public int howManyPairs(string[] words)
    {
        int i = 0, j = 0;
        int ret = 0, n = words.Length;

        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (words[i].Length != words[j].Length)
                {
                    continue;
                }
                if (isInteresting(words[i], words[j]))
                {
                    ret++;
                }
            }
        }
        return ret;
    }

    private bool isInteresting(string p, string q)
    {
        int i = 0;
        string tmp = "";
        bool ret = false;

        for (i = 0; i < p.Length && !ret; i++)
        {
            if (p[i] == q[0])
            {
                tmp = p.Substring(i) + p.Substring(0, i);
                if (tmp == q)
                {
                    ret = true;
                }
            }
        }
        return ret;
    }
}
