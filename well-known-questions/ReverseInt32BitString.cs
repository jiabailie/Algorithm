/* Function: Reverse the binary string of an integer(32-bit). */
using System;
using System.Collections.Generic;
using System.Text;

public class ReverseInt32BitString
{
    /// <summary>
    /// General method.
    /// </summary>
    /// <param name="x"></param>
    /// <returns></returns>
    public ulong reverse1(ulong x)
    {
        int i = 0;
        ulong ret = 0;
        for (i = 0; i < 32; i++)
        {
            ret = (ret << 1) | (x & 1);
            x >>= 1;
        }
        return ret;
    }

    /// <summary>
    /// New trick method.
    /// </summary>
    /// <param name="x"></param>
    /// <returns></returns>
    public ulong reverse2(ulong x)
    {
        x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
        x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2);
        x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4);
        x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
        x = ((x & 0xffff0000) >> 16) | ((x & 0x0000ffff) << 16);

        return x;
    }
}
