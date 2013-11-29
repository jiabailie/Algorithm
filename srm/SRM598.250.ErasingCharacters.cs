using System;
using System.Collections.Generic;
using System.Text;

public class ErasingCharacters
{
    public string simulate(string s)
    {
        bool find = true;
        int i = 0, j = 0;
        int l = s.Length;
        string ret = "";
        bool[] flg = new bool[l];

        if (l == 1) { return s; }

        while (find)
        {
            find = false;
            for (i = 0; i < l - 1; i++)
            {
                if (!flg[i])
                {
                    for (j = i + 1; j < l && flg[j]; j++) ;
                    if (j == l) { break; }
                    if (s[i] == s[j])
                    {
                        find = true;
                        flg[i] = true;
                        flg[j] = true;
                        break;
                    }
                }
            }
        }
        for (i = 0; i < l; i++)
        {
            if (!flg[i])
            {
                ret += s[i];
            }
        }
        return ret;
    }
}
