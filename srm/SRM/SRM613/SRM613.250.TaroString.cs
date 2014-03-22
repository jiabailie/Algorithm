using System;

public class TaroString
{
    public string getAnswer(string S)
    {
        int i = 0, j = 0;
        int[] cnt = new int[3];
        int[] pos = new int[3];
        string source = "CAT";
        for (; i < S.Length; ++i)
        {
            for (j = 0; j < 3; ++j)
            {
                if (S[i] == source[j])
                {
                    cnt[j] += 1;
                    pos[j] = i;
                }
            }
        }
        if (!(pos[0] < pos[1] && pos[1] < pos[2]))
        {
            return "Impossible";
        }
        for (i = 0; i < 3; ++i)
        {
            if (cnt[i] != 1)
            {
                return "Impossible";
            }
        }
        return "Possible";
    }
}