//Qualification Round Africa and Arabia 2011 B
using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

public class InvestingattheMarket
{
    public InvestingattheMarket()
    {
        int i = 0;
        int N = 0;
        int M = 0;
        int start = 0;
        int end = 0;
        int profit = 0;
        bool impossible = false;
        string[] price = null;

        StreamReader sRead = new StreamReader(new FileStream(@"E:\GCJ\file\B-large-practice.in", FileMode.Open));
        StreamWriter sWrite = new StreamWriter(new FileStream(@"E:\GCJ\file\B-large-practice.out", FileMode.OpenOrCreate));

        N = Convert.ToInt32(sRead.ReadLine());

        for (i = 0; i < N; i++)
        {
            M = Convert.ToInt32(sRead.ReadLine());
            price = sRead.ReadLine().Trim().Split(' ');
            impossible = planInvestment(M, price, ref start, ref end, ref profit);
            if (impossible)
            {
                sWrite.WriteLine("Case #{0}: {1} {2} {3}", i + 1, start + 1, end + 1, profit);
            }
            else
            {
                sWrite.WriteLine("Case #{0}: IMPOSSIBLE", i + 1);
            }
        }
        sRead.Close();
        sWrite.Close();
    }

    private bool planInvestment(int M, string[] price, ref int start, ref int end, ref int profit)
    {
        int i = 0;
        int j = 0;
        int tmp = 0;
        int items = Int32.MaxValue;
        bool impo = false;
        int[] p = new int[12];

        profit = Int32.MinValue;
        for (i = 0; i < 12; i++)
        {
            p[i] = Convert.ToInt32(price[i]);
        }

        for (i = 0; i < 11; i++)
        {
            for (j = i + 1; j < 12; j++)
            {
                if (M >= p[i])
                {
                    tmp = (M / p[i]) * (p[j] - p[i]);
                    if (tmp > 0 && tmp > profit)
                    {
                        impo = true;
                        start = i;
                        end = j;
                        profit = tmp;
                        items = p[i];
                    }
                    else if (tmp > 0 && tmp == profit && p[i] < items)
                    {
                        start = i;
                        end = j;
                        items = p[i];
                    }
                }
            }
        }

        return impo;
    }
}
