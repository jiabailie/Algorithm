using System;
using System.Collections.Generic;
using System.Text;

public class TuringTape
{
    private int rev(int x)
    {
        int i = 0;
        int[] y = new int[8];
        while (x > 0)
        {
            y[i++] = x % 2;
            x >>= 1;
        }
        for (x = 0, i = 0; i < 8; i++)
        {
            x += y[i] * (1 << (7 - i));
        }
        return x;
    }
    public TuringTape()
    {
        int i = 0;
        int p = 0;
        int c = 0;
        string src = Console.ReadLine().Trim();

        for (i = 0; i < src.Length; i++)
        {
            c = (rev(p) - rev((int)src[i]) + 256) % 256;
            p = (int)src[i];
            Console.WriteLine(c);
        }
    }
}