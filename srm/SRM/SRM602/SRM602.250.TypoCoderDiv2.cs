using System;
using System.Collections.Generic;
using System.Text;

public class TypoCoderDiv2
{
    public int count(int[] rating)
    {
        int i = 0;
        int cnt = 0;
        bool brown = true;
        bool ciel = false;
        bool pre = ciel;
        bool cur = false;

        for (i = 0; i < rating.Length; i++)
        {
            cur = ciel;
            if (rating[i] >= 1200)
            {
                cur = brown;
            }
            if ((cur ^ pre))
            {
                cnt++;
            }
            pre = cur;
        }
        return cnt;
    }
}
