using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;

public class MakeitSmooth
{
    public MakeitSmooth()
    {
        int i = 0;
        int N = 0;
        int MinimumCost = 0;

        StreamReader sRead = new StreamReader(new FileStream(@"D:\ACM\GCJ\file\B-small-practice.in", FileMode.Open));
        StreamWriter sWrite = new StreamWriter(new FileStream(@"D:\ACM\GCJ\file\B-small-practice.out", FileMode.OpenOrCreate));
        N = Convert.ToInt32(sRead.ReadLine());

        for (i = 0; i < N; i++)
        {
            MinimumCost = Cal(sRead);

            sWrite.WriteLine("Case #{0}: {1}", i + 1, MinimumCost);
        }

        sRead.Close();
        sWrite.Close();

    }

    private int Cal(StreamReader sRead)
    {
        int i = 0;
        int D = 0;
        int I = 0;
        int M = 0;
        int N = 0;
        int mid = 0;
        int sum = 0;
        int cost = 0;

        int[] a = null;

        string[] temp = sRead.ReadLine().Split(' ');

        D = Convert.ToInt32(temp[0]);
        I = Convert.ToInt32(temp[1]);
        M = Convert.ToInt32(temp[2]);
        N = Convert.ToInt32(temp[3]);
        a = new int[N];

        temp = sRead.ReadLine().Split(' ');
        for (i = 0; i < N; i++)
        {
            a[i] = Convert.ToInt32(temp[i]);
            sum += a[i];
        }

        if (M > 0 && D > 0 && I > 0 && !IsSmooth(M, a))
        {
            cost = SubCal(1, D, I, M, ref a);
        }
        else if (M == 0 && D > 0)
        {
            mid = sum / N;

            if (sum * 1.0 / N - (int)(sum / N) > 0.5)
            {
                mid += 1;
            }

            for (i = 0; i < N; i++)
            {
                cost += Math.Abs(a[i] - mid);
            }

            sum = D * N;

            cost = Math.Min(cost, sum);
        }

        return cost;
    }

    private bool IsSmooth(int M, int[] a)
    {
        int i = 0;
        bool smooth = true;

        for (i = 1; i < a.Length; i++)
        {
            if (Math.Abs(a[i] - a[i - 1]) > M)
            {
                smooth = false;
                break;
            }
        }
        return smooth;
    }

    private int SubCal(int cur, int D, int I, int M, ref int[] a)
    {
        int deleteCost = 0;
        int insertCost = 0;
        int changeCost = 0;

        int temp = 0;

        if (cur < a.Length)
        {
            temp = a[cur];
            if (Math.Abs(a[cur] - a[cur - 1]) > M)
            {
                //delete
                a[cur] = a[cur - 1];
                deleteCost = D + SubCal(cur + 1, D, I, M, ref a);
                a[cur] = temp;

                //insert
                insertCost = I * ((int)((Math.Abs(a[cur] - a[cur - 1]) - 1) / M)) + SubCal(cur + 1, D, I, M, ref a);

                //change
                if (a[cur] > a[cur - 1])
                {
                    a[cur] = a[cur - 1] + M;
                    changeCost = (temp - a[cur]) + SubCal(cur + 1, D, I, M, ref a);
                    a[cur] = temp;
                }
                else if (a[cur] < a[cur - 1])
                {
                    a[cur] = a[cur - 1] - M;
                    changeCost = (a[cur] - temp) + SubCal(cur + 1, D, I, M, ref a);
                    a[cur] = temp;
                }
            }
        }

        return Math.Min(deleteCost, Math.Min(insertCost, changeCost));
    }
}

