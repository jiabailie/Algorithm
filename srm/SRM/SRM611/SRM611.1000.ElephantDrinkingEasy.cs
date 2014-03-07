using System;

public class ElephantDrinkingEasy
{
    private int n = 0;
    private bool[,] imap = null;
    private int possible(int order)
    {
        bool f = true;
        int cnt = 0;
        int i = 0, j = 0;
        int div = 0, rem = 0;
        int[,] water = new int[n, n];
        for (i = 0; i < (n << 2); ++i)
        {
            if ((order & (1 << i)) == 0) { continue; }

            cnt = cnt + 1;
            div = i / n;
            rem = i % n;
            f = false;

            if (div > 1)
            {
                rem = n - 1 - rem;
            }

            // 0 to (n - 1)
            if (div == 0)
            {
                for (j = 0; j < n; ++j)
                {
                    if (water[rem, j] > 0) { return 0; }
                    water[rem, j] = 1;
                    if (imap[rem, j])
                    {
                        f = true;
                        break;
                    }
                }
            }
            // n to (2 * n - 1)
            else if (div == 1)
            {
                for (j = n - 1; j >= 0; --j)
                {
                    if (water[j, rem] > 0) { return 0; }
                    water[j, rem] = 1;
                    if (imap[j, rem])
                    {
                        f = true;
                        break;
                    }
                }
            }
            // 2 * n to (3 * n - 1)
            else if (div == 2)
            {
                for (j = n - 1; j >= 0; --j)
                {
                    if (water[rem, j] > 0) { return 0; }
                    water[rem, j] = 1;
                    if (imap[rem, j])
                    {
                        f = true;
                        break;
                    }
                }

            }
            // 3 * n to (4 * n - 1)
            else if (div == 3)
            {
                for (j = 0; j < n; ++j)
                {
                    if (water[j, rem] > 0) { return 0; }
                    water[j, rem] = 1;
                    if (imap[j, rem])
                    {
                        f = true;
                        break;
                    }
                }
            }
            if (!f) { return 0; }
        }

        return cnt;
    }

    public int maxElephants(string[] map)
    {
        int i = 0, j = 0;
        int ret = 0, tmp = 0;
        n = map.Length;
        imap = new bool[n, n];

        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                if (map[i][j] == 'Y')
                {
                    imap[i, j] = true;
                }
            }
        }
        for (i = 1; i < (1 << (n << 2)); ++i)
        {
            tmp = possible(i);
            if (tmp > ret)
            {
                ret = tmp;
            }
        }
        return ret;
    }
}