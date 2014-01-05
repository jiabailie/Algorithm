using System;
using System.Collections.Generic;
using System.Text;

namespace CodeForces
{
    public class Letter
    {
        public string[] TrimBlocks(int n, int m, string[] blocks)
        {
            int i = 0;
            int j = 0;

            int top = 50;
            int bottom = 0;
            int left = 50;
            int right = 0;

            string[] draw = null;

            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    if (blocks[i][j] == '*')
                    {
                        top = Math.Min(i, top);
                        bottom = Math.Max(i, bottom);
                        left = Math.Min(j, left);
                        right = Math.Max(j, right);
                    }
                }
            }

            draw = new string[bottom - top + 1];
            for (i = 0; i < bottom - top + 1; i++)
            {
                draw[i] = "";
                for (j = left; j <= right; j++)
                {
                    draw[i] += blocks[top + i][j];
                }
            }

            return draw;
        }
    }
}
