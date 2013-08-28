using System;
using System.Collections.Generic;
using System.Text;

public class GearsDiv2
{
    public int getmin(string Directions)
    {
        int i = 0, ret = 0;
        int c = 0, l = 0;
        char pre = '0';
        List<int> consistent = new List<int>();

        for (i = 0; i < Directions.Length; i++)
        {
            if (Directions[i] == pre) { c++; }
            else
            {
                if (c > 0) { consistent.Add(c); l++; }
                c = 1;
                pre = Directions[i];
            }
        }
        if (c > 0) { consistent.Add(c); l++; }
        if (l > 2 && Directions[0] == Directions[Directions.Length - 1])
        {
            consistent[0] += consistent[l - 1];
            consistent[l - 1] = 0;
            l--;
        }

        if (l == 1) { ret = (consistent[0] + 1) / 2; }
        else { for (i = 0; i < l; ret += consistent[i] / 2, i++) ;            }

        return ret;
    }
}