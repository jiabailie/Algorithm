/* References: apps.topcoder.com/wiki/display/tc/SRM+596 */
using System;
using System.Collections.Generic;
using System.Text;

public class SparseFactorialDiv2
{
    public long getCount(long lo, long hi, long divisor)
    {
        long i = 0, j = divisor, tmp = 0;
        long[] remaind = new long[divisor];

        for (i = 0; i < divisor; i++) { remaind[i] = -1; }
        for (i = 0, j = divisor; i * i <= hi && j > 0; i++, j--)
        {
            tmp = (i * i) % divisor;
            if (remaind[tmp] == -1)
            {
                remaind[tmp] = i;
            }
        }
        for (i = 0, j = 0; i < divisor; i++)
        {
            if (remaind[i] == -1) { continue; }
            tmp = remaind[i];
            long tlo = lo - 1 - tmp * tmp;
            long thi = hi - tmp * tmp;
            if (tlo < 0) { tlo = 0; }
            j += Convert.ToInt64(thi / divisor) - Convert.ToInt64(tlo / divisor);
        }
        return j;
    }
}
