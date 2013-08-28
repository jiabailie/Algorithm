using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class ChessMetric
{
    public long howMany(int size, int[] start, int[] end, int numMoves)
    {
        int i = 0, j = 0;
        int x = 0, y = 0;
        int nx = 0, ny = 0;
        long[, ,] ways = new long[100, 100, 55];
        int[] dx = new int[16] { -1, 1, -2, -1, 0, 1, 2, -1, 1, -2, -1, 0, 1, 2, -1, 1 };
        int[] dy = new int[16] { 2, 2, 1, 1, 1, 1, 1, 0, 0, -1, -1, -1, -1, -1, -2, -2 };

        ways[start[0], start[1], 0] = 1;

        for (i = 1; i <= numMoves; i++)
        {
            for (x = 0; x < size; x++)
            {
                for (y = 0; y < size; y++)
                {
                    for (j = 0; j < 16; j++)
                    {
                        nx = x + dx[j];
                        ny = y + dy[j];
                        if (nx >= 0 && nx < size && ny >= 0 && ny < size)
                        {
                            ways[nx, ny, i] += ways[x, y, i - 1];
                        }
                    }
                }
            }
        }
        return ways[end[0], end[1], numMoves];
    }
}
