using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace lab
{
    public class CalPow
    {
        /// <summary>
        /// x^y
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static long CalPowUsingRecursive(long x, long y)
        {
            int sign = 1;
            if (y < 0)
            {
                if (x == 0) 
                {
                    throw new Exception("The 0 can not be the divisor.");
                }
                else
                {
                    sign = -1;
                }
            }

            return sign * CalPowDetail(x, sign * y);
        }

        public static long CalPowDetail(long x, long y)
        {
            if (y == 0) { return 1; }
            if (y == 1) { return x; }

            long tmp = CalPowUsingRecursive(x, y / 2);
            tmp = tmp * tmp;
            if ((y & 1) == 0) { return tmp; }
            if ((y & 1) == 1) { return x * tmp; }
            return 1;
        }
    }
}
