using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ.qulification
{
    public class ManageyourEnergy
    {
        public ManageyourEnergy()
        {
            int i = 0;
            int j = 0;
            int T = 0;
            long e = 0, r = 0, n = 0;
            long[] v = null;

            StreamReader sRead = new StreamReader(new FileStream(@"E:\Practice\GCJ\file\1.in", FileMode.Open));
            StreamWriter sWrite = new StreamWriter(new FileStream(@"E:\Practice\GCJ\file\1.out", FileMode.OpenOrCreate));
            T = Convert.ToInt32(sRead.ReadLine());

            for (i = 0; i < T; i++)
            {
                string[] tmp = sRead.ReadLine().Split(' ');
                e = Convert.ToInt64(tmp[0]);
                r = Convert.ToInt64(tmp[1]);
                n = Convert.ToInt64(tmp[2]);
                v = new long[n];
                tmp = sRead.ReadLine().Split(' ');
                for (j = 0; j < n; j++)
                {
                    v[j] = Convert.ToInt64(tmp[j]);
                }
                sWrite.WriteLine("Case #{0}: {1}", i + 1, calMax(e, r, n, v));
            }

            sRead.Close();
            sWrite.Close();
        }

        private long calMax(long e, long r, long n, long[] v)
        {
            long i = 0, j = 0;
            long max = 0, map = 0;
            long[] dp = new long[e + 1];
            long[] ep = new long[e + 1];
            for (i = 0; i <= e; i++) { dp[i] = 0; ep[i] = e; }
            for (i = 1; i <= n; i++)
            {
                for (j = e; j >= 0; j--)
                {
                    if (ep[j] >= j)
                    {
                        dp[j] += v[i - 1] * j;
                        ep[j] = Math.Min(ep[j] - j + r, e);
                        if (dp[j] > max) { max = dp[j]; map = ep[j]; }
                    }
                }
            }
            return dp[e];
        }
    }
}
