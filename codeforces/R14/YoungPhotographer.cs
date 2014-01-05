using System;
using System.Collections.Generic;
using System.Text;

namespace CodeForces
{
    public class YoungPhotographer
    {
        public int MinimumStep()
        {
            int i = 0;
            int j = 0;
            int n = 0;
            int x = 0;
            int t = 0;
            int i1 = 0, i2 = 0;
            int[] cal = new int[1001];
            string[] temp = Console.ReadLine().Split(' ');

            n = Convert.ToInt32(temp[0]);
            x = Convert.ToInt32(temp[1]);

            for (i = 0; i < n; i++)
            {
                temp = Console.ReadLine().Split(' ');
                i1 = Convert.ToInt32(temp[0]);
                i2 = Convert.ToInt32(temp[1]);

                for (j = Math.Min(i1, i2); j <= Math.Max(i1, i2); j++)
                {
                    cal[j]++;
                }
            }

            j = 2000;

            for (i = 0; i < 1001; i++)
            {
                if (cal[i] == n)
                {
                    t = Math.Abs(i - x);
                    if (t < j)
                    {
                        j = t;
                    }
                }
            }

            return j == 2000 ? -1 : j;
        }
    }
}
