using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

class FairWarning
{
    public FairWarning()
    {
        int i = 0;
        int C = 0;
        int p = 0;

        StreamReader sRead = new StreamReader(new FileStream(@"D:\ACM\Codes\GCJ\file\B.in", FileMode.Open));
        StreamWriter sWrite = new StreamWriter(new FileStream(@"D:\ACM\Codes\GCJ\file\B.out", FileMode.OpenOrCreate));
        C = Convert.ToInt32(sRead.ReadLine());

        for (i = 0; i < C; i++)
        {
            p = WarnNumber(sRead.ReadLine().Split(' '));

            sWrite.WriteLine("Case #{0}: {1}", i + 1, p);
        }

        sRead.Close();
        sWrite.Close();
    }

    private int WarnNumber(string[] items)
    {
        int i = 0;
        int j = 0;
        int cur = 0;
        int temp = 0;
        int maxGCD = Int32.MinValue;

        int N = Convert.ToInt32(items[0]);
        int[] times = new int[N];

        for (i = 0; i < N; i++)
        {
            times[i] = Convert.ToInt32(items[i + 1]);
        }

        Array.Sort(times);

        for (i = 0; i <= times[0]; i++)
        {
            for (j = 0; j < N; j++)
            {
                times[j]++;
            }
            temp = GetGCD(times);
            if (temp > maxGCD)
            {
                maxGCD = temp;
                cur = i;
            }
        }

        return cur;
    }

    private int GetGCD(int[] num)
    {
        int gcd = 0;
        Array.Sort(num);

        gcd = SubGCD(num[1], num[0]);

        if (num.Length == 3)
        {
            gcd = SubGCD(num[2], gcd);
        }
        return gcd;
    }

    private int SubGCD(int a, int b)
    {
        int gcd = 0;
        if (b == 0)
        {
            gcd = a;
        }
        else
        {
            gcd = SubGCD(b, a % b);
        }

        return gcd;
    }
}
