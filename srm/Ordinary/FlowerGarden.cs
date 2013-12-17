using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class FlowerGarden
{
    public int[] getOrdering(int[] height, int[] bloom, int[] wilt)
    {
        int i = 0, j = 0, k = 0;
        int n = height.Length;
        bool[] done = new bool[n];
        int[] res = new int[n];

        for (i = 0; i < n; i++)
        {
            int best = -1;
            for (j = 0; j < n; j++)
            {
                if (!done[j])
                {
                    bool ok = true;
                    for (k = 0; k < n; k++)
                    {
                        if (k != j && 
                            !done[k] && 
                            height[k] < height[j] && 
                            bloom[k] <= wilt[j] && 
                            wilt[k] >= bloom[j])
                        {
                            ok = false;
                        }
                    }
                    if (ok && (best == -1 || height[j] > height[best]))
                    {
                        best = j;
                    }
                }
            }
            res[i] = height[best];
            done[best] = true;
        }

        return res;
    }
}

