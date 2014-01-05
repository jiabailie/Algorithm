using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJ
{
    public class C
    {
        public C()
        {
            int i = 0;
            int j = 0;
            int T = 0;
            int N = 0;
            int[] candy = null;
            string[] tmp = null;
            StreamReader sRead = new StreamReader(new FileStream(@"E:\GCJ\file\C-small-attempt14.in", FileMode.Open));
            StreamWriter sWrite = new StreamWriter(new FileStream(@"E:\GCJ\file\C-small-attempt14.out", FileMode.OpenOrCreate));
            T = Convert.ToInt32(sRead.ReadLine());
            for (i = 0; i < T; i++)
            {
                N = Convert.ToInt32(sRead.ReadLine());
                tmp = sRead.ReadLine().Split(' ');
                candy = new int[N];
                for (j = 0; j < N; j++)
                {
                    candy[j] = Convert.ToInt32(tmp[j]);
                }
                Array.Sort(candy);
                sWrite.WriteLine("Case #{0}: {1}", i + 1, splitCandy(N, candy));
            }

            sRead.Close();
            sWrite.Close();
        }

        private string splitCandy(int N, int[] candy)
        {
            int i = 0;
            int c = 0;
            int t = 0;
            long m = -1;
            int[] hold = new int[N];

            //{patric, sean}
            long[] calSean = new long[2];
            long[] calPatrick = new long[2];

            while (true)
            {
                c = 1;
                for (i = 0; c != 0 && i < N; i++)
                {
                    t = hold[i];
                    hold[i] = (t + c) % 2;
                    c = (t + c) / 2;
                }
                calSean[0] = 0;
                calSean[1] = 0;
                calPatrick[0] = 0;
                calPatrick[1] = 0;
                for (i = 0; i < N; i++)
                {
                    if (hold[i] == 1)
                    {
                        calSean[0] += candy[i];
                        calPatrick[0] = calPatrick[0] ^ candy[i];
                    }
                    else
                    {
                        calSean[1] += candy[i];
                        calPatrick[1] = calPatrick[1] ^ candy[i];
                    }
                }
                if (calSean[0] * calSean[1] * calPatrick[0] * calPatrick[1] > 0 &&
                    calPatrick[0] == calPatrick[1] &&
                    calSean[0] <= calSean[1])
                {
                    m = calSean[1] > m ? calSean[1] : m;
                }
                else if (calSean[0] > calSean[1])
                {
                    break;
                }
            }
            return m == -1 ? "NO" : m.ToString();
        }
    }
}