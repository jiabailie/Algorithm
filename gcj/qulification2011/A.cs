using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJ
{
    public class A
    {
        public A()
        {
            int i = 0;
            int T = 0;
            int min = 0;
            string items = null;
            StreamReader sRead = new StreamReader(new FileStream(@"E:\GCJ\file\A-small-attempt0.in", FileMode.Open));
            StreamWriter sWrite = new StreamWriter(new FileStream(@"E:\GCJ\file\A-small-attempt0.out", FileMode.OpenOrCreate));
            T = Convert.ToInt32(sRead.ReadLine());
            for (i = 0; i < T; i++)
            {
                items = sRead.ReadLine();
                min = calTime(items.Split(' '));
                sWrite.WriteLine("Case #{0}: {1}", i + 1, min);
            }

            sRead.Close();
            sWrite.Close();
        }

        private int calTime(string[] p)
        {
            int i = 0;
            int j = 0;
            int posO = 1;
            int posB = 1;
            int cost = 0;
            int sucO = -1;
            int sucB = -1;
            int dirO = -1;
            int dirB = -1;
            int N = Convert.ToInt32(p[0]);
            char[] robot = new char[N];
            int[] button = new int[N];

            List<string> step = new List<string>();

            for (i = 1, j = 0; i < p.Length; i += 2, j++)
            {
                robot[j] = p[i][0];
                button[j] = Convert.ToInt32(p[i + 1]);
                if (dirO == -1 && p[i] == "O")
                {
                    sucO = button[j];
                    dirO = button[j] > posO ? 1 : 0;
                }
                if (dirB == -1 && p[i] == "B")
                {
                    sucB = button[j];
                    dirB = button[j] > posB ? 1 : 0;
                }
            }

            for (i = 0; i < N; )
            {
                cost++;
                if ((robot[i] == 'O' && posO == button[i]) || (robot[i] == 'B' && posB == button[i]))
                {
                    if (robot[i] == 'O')
                    {
                        for (j = i + 1; j < N; j++)
                        {
                            if (robot[j] == 'O')
                            {
                                sucO = button[j];
                                break;
                            }
                        }
                        posB += dirB;
                    }
                    if (robot[i] == 'B')
                    {
                        for (j = i + 1; j < N; j++)
                        {
                            if (robot[j] == 'B')
                            {
                                sucB = button[j];
                                break;
                            }
                        }
                        posO += dirO;
                    }
                    i++;
                }
                else
                {
                    posO += dirO;
                    posB += dirB;
                }
                dirB = sucB > posB ? 1 : (sucB == posB ? 0 : -1);
                dirO = sucO > posO ? 1 : (sucO == posO ? 0 : -1);
                step.Add(dirO + " " + dirB);
            }
            return cost;
        }
    }
}
