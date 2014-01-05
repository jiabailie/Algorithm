using System;
using System.Collections.Generic;
using System.Text;

public class HQ9
{
    public HQ9()
    {
        int i = 0;
        bool output = false;
        string x = Console.ReadLine().Trim();
        for (i = 0; i < x.Length; i++)
        {
            if (x[i] == 'H' || x[i] == 'Q' || x[i] == '9')
            {
                output = true;
                break;
            }
        }
        Console.WriteLine(output ? "YES" : "NO");
    }
}
