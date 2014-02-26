using System;

public class TheMatrix
{
    public int MaxArea(string[] board)
    {
        int i = 0, m = 0, n = 0;
        int lH = 0, lW = 0, rH = 0, rW = 0, ret = 1;
        int h = board.Length, w = board[0].Length;
        int tH = 0, tW = 0;

        int[] ph = new int[4] { 0, 1, 0, -1 };
        int[] pw = new int[4] { 1, 0, -1, 0 };
        int[,] rec = new int[h, w];

        for (m = 0; m < h; ++m)
        {
            for (n = 0; n < w; ++n)
            {
                for (i = 0; i < 4; ++i)
                {
                    tH = m + ph[i];
                    tW = n + pw[i];
                    if (tH >= 0 && tH < h && tW >= 0 && tW < w)
                    {
                        if (board[m][n] != board[tH][tW])
                        {
                            rec[m, n] |= (1 << i);
                        }
                    }
                }
            }
        }

        for (lH = 0; lH < h; ++lH)
        {
            for (lW = 0; lW < w; ++lW)
            {
                for (rH = h - 1; rH >= lH; --rH)
                {
                    for (rW = w - 1; rW >= lW; --rW)
                    {
                        bool check = true;

                        int csize = (rH - lH + 1) * (rW - lW + 1);

                        if (csize <= ret) { continue; }

                        if (lH == rH)
                        {
                            if ((rec[lH, lW] & 1) != 1) { check = false; }
                            if ((rec[rH, rW] & 4) != 4) { check = false; }
                            if (check)
                            {
                                for (i = lW + 1; i < rW && check; ++i)
                                {
                                    if ((rec[lH, i] & 5) != 5) { check = false; }
                                }
                            }
                        }
                        else if (lW == rW)
                        {
                            if ((rec[lH, lW] & 2) != 2) { check = false; }
                            if ((rec[rH, rW] & 8) != 8) { check = false; }
                            if (check)
                            {
                                for (i = lH + 1; i < rH && check; ++i)
                                {
                                    if ((rec[i, lW] & 10) != 10) { check = false; }
                                }
                            }
                        }
                        else
                        {
                            if ((rec[lH, lW] & 3) != 3) { check = false; }
                            if ((rec[lH, rW] & 6) != 6) { check = false; }
                            if ((rec[rH, lW] & 9) != 9) { check = false; }
                            if ((rec[rH, rW] & 12) != 12) { check = false; }

                            if (check)
                            {
                                for (i = lW + 1; i < rW && check; ++i)
                                {
                                    if ((rec[lH, i] & 7) != 7) { check = false; }
                                }
                            }

                            if (check)
                            {
                                for (i = lW + 1; i < rW && check; ++i)
                                {
                                    if ((rec[rH, i] & 13) != 13) { check = false; }
                                }
                            }

                            if (check)
                            {
                                for (i = lH + 1; i < rH && check; ++i)
                                {
                                    if ((rec[i, lW] & 11) != 11) { check = false; }
                                }
                            }

                            if (check)
                            {
                                for (i = lH + 1; i < rH && check; ++i)
                                {
                                    if ((rec[i, rW] & 14) != 14) { check = false; }
                                }
                            }

                            if (check)
                            {
                                for (m = lH + 1; m < rH && check; ++m)
                                {
                                    for (n = lW + 1; n < rW && check; ++n)
                                    {
                                        if ((rec[m, n] & 15) != 15) { check = false; }
                                    }
                                }
                            }
                        }

                        if (check)
                        {
                            ret = csize;
                        }
                    }
                }
            }
        }
        return ret;
    }
}