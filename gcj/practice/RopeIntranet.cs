using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

public class RopeIntranet
{
    public RopeIntranet()
    {
        int i = 0;
        int j = 0;
        int T = 0;
        int N = 0;
        int CrossPoint = 0;

        int[] A = null;
        int[] B = null;
        string[] temp = null;

        StreamReader sRead = new StreamReader(new FileStream(@"D:\ACM\GCJ\file\A.in", FileMode.Open));
        StreamWriter sWrite = new StreamWriter(new FileStream(@"D:\ACM\GCJ\file\A.out", FileMode.OpenOrCreate));
        T = Convert.ToInt32(sRead.ReadLine());

        for (i = 0; i < T; i++)
        {
            N = Convert.ToInt32(sRead.ReadLine());
            A = new int[N];
            B = new int[N];

            for (j = 0; j < N; j++)
            {
                temp = sRead.ReadLine().Split(' ');
                A[j] = Convert.ToInt32(temp[0]);
                B[j] = Convert.ToInt32(temp[1]);
            }
            CrossPoint = CalCrossPoint(N, A, B);
            sWrite.WriteLine("Case #{0}: {1}", i + 1, CrossPoint);
        }

        sRead.Close();
        sWrite.Close();

    }

    private int CalCrossPoint(int N, int[] A, int[] B)
    {
        int i = 0;
        int j = 0;
        int mA = 0;
        int mB = 0;
        int cross = 0;

        for (i = 0; i < N - 1; i++)
        {
            for (j = i + 1; j < N; j++)
            {
                mA = A[i] - A[j];
                mB = B[i] - B[j];

                if (mA * mB < 0)
                {
                    cross++;
                }
            }
        }

        return cross;
    }
}
