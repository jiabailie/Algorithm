using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

class ThemePark
{
    public ThemePark()
    {
        int i = 0;
        int T = 0;
        int R = 0;
        int K = 0;
        int N = 0;
        int cost = 0;
        string[] items = null;

        StreamReader sRead = new StreamReader(new FileStream(@"D:\ACM\Codes\GCJ\file\C-large.in", FileMode.Open));
        StreamWriter sWrite = new StreamWriter(new FileStream(@"D:\ACM\Codes\GCJ\file\C-large.out", FileMode.OpenOrCreate));
        T = Convert.ToInt32(sRead.ReadLine());

        for (i = 0; i < T; i++)
        {
            items = sRead.ReadLine().Split(' ');
            R = Convert.ToInt32(items[0]);
            K = Convert.ToInt32(items[1]);
            N = Convert.ToInt32(items[2]);
            items = sRead.ReadLine().Split(' ');

            cost = ThemeIncome(R, K, N, items);

            sWrite.WriteLine("Case #{0}: {1}", i + 1, cost);
        }

        sRead.Close();
        sWrite.Close();
    }

    private int ThemeIncome(int R, int K, int N, string[] items)
    {
        int i = 0;
        int j = 0;
        int temp = 0;
        int ride = 0;
        int income = 0;

        List<int> queue = new List<int>();
        for (i = 0; i < N; i++)
        {
            queue.Add(Convert.ToInt32(items[i]));
        }

        for (i = 0; i < R; i++)
        {
            ride = 0;
            for (j = 0; j < N; j++)
            {
                temp = queue[0];
                if (ride + temp <= K)
                {
                    queue.RemoveAt(0);

                    ride += temp;
                    income += temp;

                    queue.Add(temp);
                }
                else
                {
                    break;
                }
            }
        }

        return income;
    }
}
