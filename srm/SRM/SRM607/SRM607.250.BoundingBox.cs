using System;
using System.Collections.Generic;
using System.Text;

public class BoundingBox
{
    public int smallestArea(int[] X, int[] Y)
    {
        int minX = int.MaxValue;
        int minY = int.MaxValue;
        int maxX = int.MinValue;
        int maxY = int.MinValue;

        foreach (int x in X)
        {
            if (x < minX) { minX = x; }
            if (x > maxX) { maxX = x; }
        }
        foreach (int y in Y)
        {
            if (y < minY) { minY = y; }
            if (y > maxY) { maxY = y; }
        }

        return (maxX - minX) * (maxY - minY);
    }
}
