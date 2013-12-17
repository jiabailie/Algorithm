using System;
using System.Collections.Generic;
using System.Text;

public class ORSolitaireDiv2
{
    public int getMinimum(int[] numbers, int goal)
    {
        int i = 0;
        int test = 0;
        int ret = int.MaxValue;
        int[] t = new int[31];
        int[] c = new int[31];
        List<int> generate = new List<int>();

        for (i = 1, t[0] = 1; i < 31; t[i] = t[i - 1] * 2, i++) ;

        for (i = 0; i < numbers.Length; i++)
        {
            if ((numbers[i] | goal) == goal)
            {
                generate.Add(numbers[i]);
                test |= numbers[i];
            }
        }

        if (generate.Count == 0 || test != goal)
        {
            ret = 0;
        }
        else
        {
            foreach (int x in generate)
            {
                for (i = 0; i < 31; i++)
                {
                    if ((x & t[i]) > 0)
                    {
                        c[i]++;
                    }
                }
            }
            for (i = 0; i < 31; i++)
            {
                if (c[i] > 0 && c[i] < ret)
                {
                    ret = c[i];
                }
            }
        }

        return ret;
    }
}
