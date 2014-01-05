using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ.practice
{
    public class Consonants
    {
        public Consonants()
        {
            int T = 0, n = 0;
            int i = 0, j = 0, ct = 0;
            int p = 0, q = 0, k = 0;
            long ret = 0;
            string s = null;
            string[] v = null;

            StreamReader sRead = new StreamReader(new FileStream(@"E:\Practice\GCJ\file\A-large.in", FileMode.Open));
            StreamWriter sWrite = new StreamWriter(new FileStream(@"E:\Practice\GCJ\file\A-large.out", FileMode.OpenOrCreate));
            T = Convert.ToInt32(sRead.ReadLine());

            for (i = 0; i < T; i++)
            {
                v = sRead.ReadLine().Split(' ');
                s = v[0];
                n = Convert.ToInt32(v[1]);
                ret = 0;
                string cons = "";
                string pattern = "".PadLeft(n, '1');


                for (j = 0; j < s.Length; j++)
                {
                    if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                    {
                        cons += "0";
                    }
                    else
                    {
                        cons += "1";
                    }
                }
                for (p = 0; p <= s.Length - n; p++)
                {
                    for (q = p + n - 1; q < s.Length; q++)
                    {
                        ct = 0;
                        string sub = cons.Substring(p, q - p + 1);
                        if (sub.Contains(pattern))
                        {
                            ret++;
                        }
                    }
                }
                sWrite.WriteLine("Case #{0}: {1}", (i + 1), ret);
            }

            sRead.Close();
            sWrite.Close();
        }

        private int calN(int p, int n)
        {
            int ret = 0;
            for (int i = n; i <= p; i++)
            {
                ret += p - i + 1;
            }
            return ret;
        }
    }
}
