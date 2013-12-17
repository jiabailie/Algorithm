using System;
using System.Collections.Generic;
using System.Text;

public class TheArithmeticProgression
{
    public double minimumChange(int a, int b, int c)
    {
        double cx = Math.Abs(2 * b - c - a);
        double cy = Math.Abs(0.5 * (a + c) - b);
        double cz = Math.Abs(2 * b - a - c);
        double minChange = cx < cy ? (cx < cz ? cx : cz) : (cy < cz ? cy : cz);
        return minChange;
    }
}
