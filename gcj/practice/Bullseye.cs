using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

public class Bullseye
{
    public Bullseye()
    {
        int i = 0;
        int j = 0;
        int T = 0;
        long r = 0;
        long t = 0;

        StreamReader sRead = new StreamReader(new FileStream(@"E:\Practice\GCJ\file\A-large.in", FileMode.Open));
        StreamWriter sWrite = new StreamWriter(new FileStream(@"E:\Practice\GCJ\file\A-large.out", FileMode.OpenOrCreate));
        T = Convert.ToInt32(sRead.ReadLine());

        for (i = 0; i < T; i++)
        {
            string[] tmp = sRead.ReadLine().Split(' ');
            r = Convert.ToInt64(tmp[0]);
            t = Convert.ToInt64(tmp[1]);
            sWrite.WriteLine("Case #{0}: {1}", i + 1, calMax(r, t));
        }

        sRead.Close();
        sWrite.Close();

    }

    private long cal(long r, long mid)
    {
        return (2 * r + 2 * mid + 1) * (mid + 1);
    }

    private long calMax(long r, long t)
    {
        long ret = 0;
        long start = 1, end = Math.Min((long)(Math.Sqrt(t) + 1), (t / (2 * r)) + 1);
        long mid = start + (end - start) / 2;
        while (true)
        {
            long t2 = cal(r, mid - 1);
            long t1 = cal(r, mid);
            long t3 = cal(r, mid + 1);
            if (t2 < 0) { end = mid - 1; mid = start + (end - start) / 2; continue; }
            if (t1 == t) { ret = mid; break; }
            if (t1 > t && t2 <= t) { ret = mid - 1; break; }
            if (t1 < t && t2 > t) { ret = mid; break; }
            else
            {
                if (t1 < t) { start = mid + 1; }
                if (t1 > t) { end = mid - 1; }
                mid = start + (end - start) / 2;
            }
        }
        return ret + 1;
    }
}
