using System;

public class AlienAndGame
{
    public int getNumber(string[] board)
    {
        bool check = true;
        int i = 0, j = 0;
        int m = 0, n = 0, k = Math.Min(board.Length, board[0].Length);

        for (; k >= 0; --k)
        {
            for (i = 0; i + k - 1 < board.Length; ++i)
            {
                for (j = 0; j + k - 1 < board[0].Length; ++j)
                {
                    check = true;
                    for (m = 0; check && m < k; ++m)
                    {
                        for (n = 0; check && n < k; ++n)
                        {
                            if (board[i + m][j + n] != board[i + m][j])
                            {
                                check = false;
                            }
                        }
                    }
                    if (check)
                    {
                        return k * k;
                    }
                }
            }
        }
        return 1;
    }
}
