using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace lab
{
    public class TestFunction
    {
        /// <summary>
        /// Transform one binary string to an unsigned long type integer.
        /// </summary>
        /// <param name="bitstring"></param>
        /// <returns></returns>
        public static ulong TransferstringToUnsignedLongInteger(string bitstring)
        {
            int i = 0;
            int len = bitstring.Length;
            ulong ret = 0;

            for (i = 0; i < len; i++)
            {
                ret <<= 1;
                if (bitstring[i] == '1')
                {
                    ret++;
                }
            }
            return ret;
        }

        public static string TransferUnsignedLongIntegerToString(ulong number)
        {
            ulong index = ((ulong)1 << 63);
            StringBuilder sbRet = new StringBuilder();

            while (index > 0)
            {
                sbRet.Append(((number & index) == 0 ? "0" : "1"));
                index >>= 1;
            }
            return sbRet.ToString();
        }

        /// <summary>
        /// The subBlock is a matrix size of [height, width].
        /// This function transforms the matrix to a ulong type array.
        /// </summary>
        /// <param name="subBlock"></param>
        /// <returns></returns>
        public static ulong[] TransferOneZerostringToUlongArray(string subBlock)
        {
            ulong[] ret = null;
            int i = 0, arrayLength = 0;
            int length = subBlock.Length + 1;

            subBlock = "1" + subBlock;

            arrayLength = length / 64;

            if (length % 64 != 0)
            {
                arrayLength++;
                length = (arrayLength << 6);

                subBlock = subBlock.PadRight(length, '0');
            }
            ret = new ulong[arrayLength];
            for (i = 0; i < arrayLength; i++)
            {
                ret[i] = TransferstringToUnsignedLongInteger(subBlock.Substring(i << 6, 64));
            }

            return ret;
        }
    }
}
