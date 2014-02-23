using System;

public class MagicalStringDiv2
{
    public int minimalMoves(string S)
    {
        int n = S.Length;
        int i = 0, cnt = 0;

        for (i = 0; i < n / 2; ++i)
        {
            if (S[i] == '<') { ++cnt; }
        }
        for (i = n / 2; i < n; ++i)
        {
            if (S[i] == '>') { ++cnt; }
        }
        return cnt;
    }
}
