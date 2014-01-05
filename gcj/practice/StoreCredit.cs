using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJ
{
    class StoreCredit
    {
        public StoreCredit()
        {
            int i = 0;
            int N = 0;
            int C = 0;
            int I = 0;
            int[] index = null;
            string[] items = null;
            StreamReader sRead = new StreamReader(new FileStream(@"D:\ACM\Codes\GCJ\file\A-large-practice.in", FileMode.Open));
            StreamWriter sWrite = new StreamWriter(new FileStream(@"D:\ACM\Codes\GCJ\file\A-large-practice.out", FileMode.OpenOrCreate));
            N = Convert.ToInt32(sRead.ReadLine());

            for (i = 0; i < N; i++)
            {
                C = Convert.ToInt32(sRead.ReadLine());
                I = Convert.ToInt32(sRead.ReadLine());
                items = sRead.ReadLine().Split(' ');

                index = GetIndex(C, I, items);

                sWrite.WriteLine("Case #{0}: {1} {2}", i + 1, index[0], index[1]);
            }

            sRead.Close();
            sWrite.Close();
        }

        public static int[] GetIndex(int C, int I, string[] items)
        {
            int i = 0;
            int j = 0;
            bool flag = false;
            int[] index = null;
            int[] elem = new int[I];

            for (i = 0; i < I; i++)
            {
                elem[i] = Convert.ToInt32(items[i]);
            }

            for (i = 0; i < I - 1 && !flag; i++)
            {
                for (j = i + 1; j < I && !flag; j++)
                {
                    if (i != j && elem[i] + elem[j] == C)
                    {
                        index = new int[] { i + 1, j + 1 };
                        flag = true;
                    }
                }
            }
            Array.Sort(index);

            return index;
        }

    }
}
