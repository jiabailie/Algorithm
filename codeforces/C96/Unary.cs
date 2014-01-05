using System;
using System.Collections.Generic;
using System.Text;

public class Unary
{
    public Unary()
    {
        int i = 0;
        int j = 0;
        int k = 0;
        int tmp = 0;
        int res = 0;
        string x = Console.ReadLine();
        int[] rec = new int[405];
        for (i = x.Length - 1; i >= 0; i--)
        {
            switch (x[i])
            {
                case '>':
                    rec[j++] = 0;
                    rec[j++] = 0;
                    rec[j++] = 0;
                    rec[j++] = 1;
                    break;
                case '<':
                    rec[j++] = 1;
                    rec[j++] = 0;
                    rec[j++] = 0;
                    rec[j++] = 1;
                    break;
                case '+':
                    rec[j++] = 0;
                    rec[j++] = 1;
                    rec[j++] = 0;
                    rec[j++] = 1;
                    break;
                case '-':
                    rec[j++] = 1;
                    rec[j++] = 1;
                    rec[j++] = 0;
                    rec[j++] = 1;
                    break;
                case '.':
                    rec[j++] = 0;
                    rec[j++] = 0;
                    rec[j++] = 1;
                    rec[j++] = 1;
                    break;
                case ',':
                    rec[j++] = 1;
                    rec[j++] = 0;
                    rec[j++] = 1;
                    rec[j++] = 1;
                    break;
                case '[':
                    rec[j++] = 0;
                    rec[j++] = 1;
                    rec[j++] = 1;
                    rec[j++] = 1;
                    break;
                case ']':
                    rec[j++] = 1;
                    rec[j++] = 1;
                    rec[j++] = 1;
                    rec[j++] = 1;
                    break;
                default:
                    break;
            }
        }
        for (i = 0; i < j; i++)
        {
            if (rec[i] == 1)
            {
                tmp = 1;
                for (k = 0; k < i; k++)
                {
                    tmp <<= 1;
                    tmp %= 1000003;
                }
                res += tmp;
                res %= 1000003;
            }
        }
        Console.WriteLine(res);
    }
}