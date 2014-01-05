using System;
using System.Collections.Generic;
using System.Text;

public class Statues
{
    private char[][] board = new char[8][];
    public Statues()
    {
        int i = 0;
        int j = 0;
        int c = 0;
        int px = 7;
        int py = 0;
        bool flg = false;
        string res = "WIN";
        for (i = 0; i < 8; i++)
        {
            board[i] = Console.ReadLine().ToCharArray();
            for (j = 0; j < 8; j++)
            {
                if (board[i][j] == 'S')
                {
                    c++;
                }
            }
        }
        for (i = -1; i <= 1; i++)
        {
            for (j = -1; j <= 1; j++)
            {
                if (px + i >= 0 && px + i <= 7 && py + j >= 0 && py + j <= 7 && board[px + i][py + j] != 'S')
                {
                    flg |= nextStep(c, px + i, py + j);
                }
            }
        }

        if (!flg)
        {
            res = "LOSE";
        }
        Console.WriteLine(res);
    }

    private bool nextStep(int c, int px, int py)
    {
        int i = 0;
        int j = 0;
        bool flg = true;
        bool sflg = true;
        for (i = 0; i <= 7 && flg; i++)
        {
            for (j = 0; j <= 7 && flg; j++)
            {
                if (board[i][j] == 'S')
                {
                    board[i][j] = '.';
                    if (i <= 6)
                    {
                        board[i + 1][j] = 'S';
                        if (i + 1 == px && j == py)
                        {
                            flg = false;
                        }
                    }
                    else if (i == 7)
                    {
                        c--;
                    }
                }
            }
        }
        if (flg && (c > 0) && (px != 0 || py != 7))
        {
            sflg = false;
            for (i = -1; i <= 1; i++)
            {
                for (j = -1; j <= 1; j++)
                {
                    if (px + i >= 0 && px + i <= 7 && py + j >= 0 && py + j <= 7 && board[px + i][py + j] != 'S')
                    {
                        sflg |= nextStep(c, px + i, py + j);
                    }
                }
            }
        }
        return flg & sflg;
    }
}
