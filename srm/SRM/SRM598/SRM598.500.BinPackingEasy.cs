using System;
using System.Collections.Generic;
using System.Text;

public class BinPackingEasy
{
    public int minBins(int[] item)
    {
        int i = 0, j = 0;
        int n = item.Length;
        int rem = n, ret = 0;
        bool[] saved = new bool[n];
        List<List<int>> save = new List<List<int>>();
        for (i = 0; i <= 300; i++)
        {
            save.Add(new List<int>());
        }

        while (rem > 0)
        {
            int[] vol = new int[301];
            for (i = 0; i <= 300; i++) { save[i].Clear(); }

            for (j = 0; j < n; j++)
            {
                if (!saved[j])
                {
                    for (i = 300; i > 0; i--)
                    {
                        if (i >= item[j])
                        {
                            if (vol[i] < vol[i - item[j]] + item[j])
                            {
                                save[i].Clear();
                                foreach (int x in save[i - item[j]])
                                {
                                    save[i].Add(x);
                                }
                                save[i].Add(j);
                                vol[i] = vol[i - item[j]] + item[j];
                            }
                        }
                    }
                }
            }
            ret++;
            rem -= save[300].Count;
            foreach (int x in save[300])
            {
                saved[x] = true;
            }
        }

        return ret;
    }
}
