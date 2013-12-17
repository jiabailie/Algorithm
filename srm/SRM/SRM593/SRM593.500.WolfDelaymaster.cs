// srm593 500
using System;
using System.Collections.Generic;
using System.Text;

public class WolfDelaymaster
{
    public string check(string str)
    {
        int i = 0, j = 0;
        bool valid = true;
        int len = str.Length;

        if (len % 4 != 0)
        {
            valid = false;
        }
        else
        {
            int tlen = -1;
            char[] dc = new char[50];
            int[] dt = new int[50];

            for (i = 0; i < len && valid; i++)
            {
                tlen++;
                dc[tlen] = str[i];
                dt[tlen] = 0;
                for (j = i; j < len && str[j] == str[i]; j++, dt[tlen]++) ;
                i = j - 1;
                if ((tlen + 1) % 4 == 0)
                {
                    if (!(dc[tlen - 3] == 'w' && dc[tlen - 2] == 'o' && dc[tlen - 1] == 'l' && dc[tlen] == 'f'))
                    {
                        valid = false;
                    }
                    if (!(dt[tlen - 3] == dt[tlen - 2] && dt[tlen - 3] == dt[tlen - 1] && dt[tlen - 3] == dt[tlen]))
                    {
                        valid = false;
                    }
                }
            }
            if ((tlen + 1) % 4 != 0) { valid = false; }
        }
        return valid ? "VALID" : "INVALID";
    }
}
