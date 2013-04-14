using System;
using System.Collections.Generic;
using System.Text;

public class CharacterBoard2
{
    private long pow26(long x)
    {
        long ret = 1;
        for (long i = 0; i < x; i++)
        {
            ret = (ret * 26) % 1000000009;
        }
        return ret;
    }

    public int countGenerators(string[] fragment, int W, int i0, int j0)
    {
        int finish = 0;
        bool suc = true;
        long index = 0;
        long ret = 0;
        long i = 0, j = 0, k = 0;

        for (k = 1; k <= W; k++)
        {
            finish = 0;
            suc = true;
            char[] source = new char[k];
            bool[] generate = new bool[k];

            for (i = 0; i < fragment.Length && suc; i++)
            {
                for (j = 0; j < fragment[0].Length && suc; j++)
                {
                    index = ((i + i0) * W + (j0 + j)) % k;
                    if (!generate[index])
                    {
                        source[index] = fragment[(int)i][(int)j];
                        generate[index] = true;
                        finish++;
                    }
                    else
                    {
                        if (fragment[(int)i][(int)j] == source[index]) { continue; }
                        else { suc = false; break; }
                    }
                }
            }
            if (suc)
            {
                if (finish == k) { ret = (ret + 1) % 1000000009; }
                else if (finish < k) { ret = (ret + pow26(k - finish)) % 1000000009; }
            }
        }
        return (int)ret;
    }
}
