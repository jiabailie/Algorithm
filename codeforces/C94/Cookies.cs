using System;
using System.Collections.Generic;
using System.Text;

public class Cookies
{
    public Cookies()
    {
        int i = 0;
        int c = 0;
        int n = Convert.ToInt32(Console.ReadLine());
        int sum = 0;
        int[] a = new int[n];
        string[] s = Console.ReadLine().Split(' ');
        for (i = 0; i < n; i++)
        {
            a[i] = Convert.ToInt32(s[i]);
            sum += a[i];
        }
        foreach (int x in a)
        {
            if ((sum - x) % 2 == 0)
            {
                c++;
            }
        }
        Console.WriteLine(c);
    }
}
