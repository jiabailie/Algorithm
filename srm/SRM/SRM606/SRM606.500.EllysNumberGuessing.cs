using System;
using System.Collections.Generic;
using System.Text;

public class EllysNumberGuessing
{
    public int getNumber(int[] guesses, int[] answers)
    {
        long ret = 0;
        long u = 0, d = 0;
        int i = 0, l = guesses.Length;
        Dictionary<long, int> possible = new Dictionary<long, int>();

        for (i = 0; i < l; i++)
        {
            u = Convert.ToInt64(guesses[i]) + Convert.ToInt64(answers[i]);
            d = Convert.ToInt64(guesses[i]) - Convert.ToInt64(answers[i]);

            if (u > 0 && u <= 1000000000)
            {
                if (possible.ContainsKey(u))
                {
                    possible[u] += 1;
                }
                else
                {
                    possible[u] = 1;
                }
            }
            if (d > 0 && d <= 1000000000)
            {
                if (possible.ContainsKey(d))
                {
                    possible[d] += 1;
                }
                else
                {
                    possible[d] = 1;
                }
            }
        }
        i = 0;
        foreach (KeyValuePair<long, int> kvp in possible)
        {
            if (kvp.Value == l)
            {
                i++;
                ret = kvp.Key;
            }
        }
        if (i == 0)
        {
            return -2;
        }
        else if (i == 1)
        {
            return Convert.ToInt32(ret);
        }
        return -1;
    }
}
