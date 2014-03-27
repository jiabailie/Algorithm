using System;
public class FoxAndGomoku
{
    public string win(string[] board)
    {
        int i = 0, j = 0;
        int m = 0, n = 0;
        int k = 0, c = 0;
        int cnt = 0;
        int h = board.Length;
        int w = board[0].Length;
        bool found = false;
        int[] incX = new int[] { 1, 0, 1, -1 };
        int[] incY = new int[] { 0, 1, 1, 1 };

        for (k = 0; k < 4 && !found; ++k)
        {
            for (i = 0; i < h && !found; ++i)
            {
                for (j = 0; j < w && !found; ++j)
                {
                    if (board[i][j] == '.')
                    {
                        continue;
                    }
                    cnt = 0;
                    for (c = 0; c < 5; ++c)
                    {
                        m = i + c * incX[k];
                        n = j + c * incY[k];

                        if (m >= 0 && m < h && n >= 0 && n < w && board[m][n]=='o')
                        {
                            cnt += 1;
                        }
                    }
                    if (cnt == 5)
                    {
                        found = true;
                    }
                }
            }
        }

        return found ? "found" : "not found";
    }
}