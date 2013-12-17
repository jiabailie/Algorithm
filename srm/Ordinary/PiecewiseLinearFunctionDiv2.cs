using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace lab
{
    public class PiecewiseLinearFunctionDiv2
    {
        public int[] countSolutions(int[] Y, int[] query)
        {
            int i = 0, j = 0;
            int n = query.Length;
            int[] ret = new int[n];

            for (i = 0; i < n; i++)
            {
                ret[i] = 0;
                for (j = 0; j < Y.Length; j++)
                {
                    if (Y[j] == query[i])
                    {
                        ret[i]++;
                    }
                }
                for (j = 1; j < Y.Length; j++)
                {
                    if (Y[j - 1] == Y[j] && Y[j] == query[i])
                    {
                        ret[i] = -1;
                        break;
                    }
                    if ((Y[j - 1] < query[i] && query[i] < Y[j]) || (Y[j - 1] > query[i] && query[i] > Y[j]))
                    {
                        ret[i]++;
                    }
                }
            }
            return ret;
        }
    }
}
