using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class HyperKnight
{
    private long[] dx;
    private long[] dy;
    
    public long countCells(int a, int b, int numRows, int numColumns, int k)
    {
        dx = new long[8] { a, a, -a, -a, b, b, -b, -b };
        dy = new long[8] { b, -b, b, -b, a, -a, a, -a };
        return 0;
    }
}