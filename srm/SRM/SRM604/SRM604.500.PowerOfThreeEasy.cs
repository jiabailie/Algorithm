using System;
using System.Collections.Generic;
using System.Text;

public class PowerOfThreeEasy
{
    private long gx = 0;
    private long gy = 0;
    private bool legal = false;

    private void step(long cx, long cy, long len)
    {
        if (legal || len >= 2000000000)
        {
            return;
        }
        if (cx == gx && cy == gy)
        {
            legal = true;
            return;
        }
        step(cx + len, cy, len * 3);
        step(cx, cy + len, len * 3);
    }

    public string ableToGet(int x, int y)
    {
        gx = x;
        gy = y;

        step(0, 0, 1);

        return legal ? "Possible" : "Impossible";
    }
}
