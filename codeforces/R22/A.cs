using System;
using System.Collections.Generic;
using System.Text;

public class R22A
{
    public int GetSecondPosition(int count, int[] array)
    {
        //the minimum
        int m1 = Int32.MaxValue;
        //the second minimum
        int m2 = Int32.MaxValue;

        foreach (int i in array)
        {
            if (i != m1 && i != m2)
            {
                if (i < m2)
                {
                    if (i < m1)
                    {
                        m2 = m1;
                        m1 = i;
                    }
                    else
                    {
                        m2 = i;
                    }
                }
            }
        }

        return m2;
    }
}

