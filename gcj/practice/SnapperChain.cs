using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

class SnapperChain
{
    public SnapperChain()
    {
        int i = 0;
        int N = 0;
        int K = 0;
        int Num = 0;
        string status = null;
        string[] items = null;
        StreamReader sRead = new StreamReader(new FileStream(@"D:\ACM\Codes\GCJ\file\A-large.in", FileMode.Open));
        StreamWriter sWrite = new StreamWriter(new FileStream(@"D:\ACM\Codes\GCJ\file\A-large.out", FileMode.OpenOrCreate));
        Num = Convert.ToInt32(sRead.ReadLine());

        for (i = 0; i < Num; i++)
        {
            items = sRead.ReadLine().Split(' ');
            N = Convert.ToInt32(items[0]);
            K = Convert.ToInt32(items[1]);

            status = SnapperStatus(N, K);

            sWrite.WriteLine("Case #{0}: {1}", i + 1, status);
        }

        sRead.Close();
        sWrite.Close();
    }

    private string SnapperStatus(int N, int K)
    {
        int count = 1;
        string status = "OFF";

        count <<= N;

        if ((K + 1) % count == 0)
        {
            status = "ON";
        }

        return status;
    }
}
