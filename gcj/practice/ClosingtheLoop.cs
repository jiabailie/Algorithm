//Qualification Round Africa and Arabia 2011 A
using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

public class ClosingtheLoop
{
    public ClosingtheLoop()
    {
        int i = 0;
        int N = 0;
        int S = 0;
        int lenOfLoop = 0;
        string[] stmp = null;

        StreamReader sRead = new StreamReader(new FileStream(@"E:\GCJ\file\A-large-practice.in", FileMode.Open));
        StreamWriter sWrite = new StreamWriter(new FileStream(@"E:\GCJ\file\A-large-practice.out", FileMode.OpenOrCreate));

        N = Convert.ToInt32(sRead.ReadLine());

        for (i = 0; i < N; i++)
        {
            S = Convert.ToInt32(sRead.ReadLine());
            stmp = sRead.ReadLine().Trim().Split(' ');
            lenOfLoop = makeKnot(S, stmp);

            sWrite.WriteLine("Case #{0}: {1}", i + 1, lenOfLoop);
        }
        sRead.Close();
        sWrite.Close();
    }

    private int makeKnot(int S, string[] stmp)
    {
        int i = 0;
        int min = 0;
        int len = 0;
        List<int> red = new List<int>();
        List<int> blue = new List<int>();

        foreach (string s in stmp)
        {
            if (s[s.Length - 1] == 'R')
            {
                red.Add(Convert.ToInt32(s.Substring(0, s.Length - 1)));
            }
            else
            {
                blue.Add(Convert.ToInt32(s.Substring(0, s.Length - 1)));
            }
        }
        min = red.Count < blue.Count ? red.Count : blue.Count;

        red.Sort();
        blue.Sort();

        red.Reverse();
        blue.Reverse();

        for (i = 0; i < min; i++)
        {
            len += red[i] + blue[i] - 2;
        }
        return len;
    }
}
