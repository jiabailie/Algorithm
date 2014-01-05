using System;
using System.Collections.Generic;
using System.Text;

public class DieRoll
{
    public DieRoll()
    {
        int A = 0;
        int B = 0;
        string[] str = Console.ReadLine().Split(' ');

        A = Convert.ToInt32(str[0]);
        B = Convert.ToInt32(str[1]);

        A = A > B ? A : B;
        A = 7 - A;
        B = GetGCD(6, A);
        Console.Write((A / B) + "/" + (6 / B));
    }

    //A>B
    public int GetGCD(int A, int B)
    {
        int gcd = 0;
        if (A % B == 0)
        {
            gcd = B;
        }
        else
        {
            gcd = GetGCD(B, A % B);
        }
        return gcd;
    }
}
