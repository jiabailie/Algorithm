using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

namespace lab.algorithm
{
    public class LIS
    {
        public static int longest_increasing_substring_dp(int[] ary)
        {
            int i = 0, j = 0;
            int n = ary.Length;
            int[] tmp = new int[n];

            ArrayList.Repeat(1, n).CopyTo(tmp);

            for (i = 1; i < n; i++)
            {
                for (j = 0; j < i; j++)
                {
                    if (ary[i] > ary[j] && tmp[i] < tmp[j] + 1)
                    {
                        tmp[i] = tmp[j] + 1;
                    }
                }
            }
            j = Int32.MinValue;
            for (i = 0; i < n; i++)
            {
                if (tmp[i] > j)
                {
                    j = tmp[i];
                }
            }
            return j;
        }
    }
}