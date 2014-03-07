using System;

public class InterestingNumber
{
    public string isInteresting(string x)
    {
        int n = x.Length;
        if (n % 2 != 0 || n > 20)
        {
            return "Not interesting";
        }
        int i = 0;
        int[] pos = new int[10];
        int[] cnt = new int[10];

        for (i = 0; i < 10; pos[i] = -1, cnt[i] = 0, ++i) ;

        for (i = 0; i < n; ++i)
        {
            int t = x[i] - '0';
            cnt[t] = cnt[t] + 1;
            if (pos[t] == -1)
            {
                pos[t] = i;
            }
            else
            {
                if (i - pos[t] - 1 != t)
                {
                    return "Not interesting";
                }
                else
                {
                    pos[t] = -1;
                }
            }
        }

        for (i = 0; i < 10; ++i)
        {
            if (pos[i] != -1 || (cnt[i] != 0 && cnt[i] != 2))
            {
                return "Not interesting";
            }
        }
        return "Interesting";
    }
}