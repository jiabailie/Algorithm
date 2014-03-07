using System;

public class TheMatrix
{
    private bool checkRow(int row, int start, int end, string[] board)
    {
        if (start == end) { return true; }
        for (int i = start + 1; i <= end; ++i)
        {
            if (board[row][i] == board[row][i - 1])
            {
                return false;
            }
        }
        return true;
    }

    private bool checkRowDown(int row, int start, int end, string[] board)
    {
        for (int i = start; i <= end; ++i)
        {
            if (board[row][i] == board[row - 1][i])
            {
                return false;
            }
        }
        return true;
    }

    public int MaxArea(string[] board)
    {
        int max = 1;
        int tmp = 0;
        int i = 0, j = 0;
        int up = 0, down = 0;
        int w = board[0].Length;
        int h = board.Length;

        for (i = 0; i < w; ++i)
        {
            for (j = 0; j < w; ++j)
            {
                up = 0;
                down = 0;
                while (up < h)
                {
                    while (up < h && !checkRow(up, i, j, board))
                    {
                        up = up + 1;
                    }

                    if (up == h)
                    {
                        break;
                    }

                    down = up + 1;

                    while (down < h && checkRowDown(down, i, j, board))
                    {
                        down = down + 1;
                    }

                    tmp = (j - i + 1) * (down - up);

                    if (tmp > max)
                    {
                        max = tmp;
                    }

                    up = down;
                }
            }
        }
        return max;
    }
}