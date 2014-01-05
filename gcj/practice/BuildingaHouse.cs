//Qualification Round Africa and Arabia 2011 C
using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

public class BuildingaHouse
{
    public BuildingaHouse()
    {
        int i = 0;
        int j = 0;
        int N = 0;
        int L = 0;
        int W = 0;
        int area = 0;
        string[] tmp = null;
        char[][] condition = null;

        StreamReader sRead = new StreamReader(new FileStream(@"E:\GCJ\file\C-large-practice.in", FileMode.Open));
        StreamWriter sWrite = new StreamWriter(new FileStream(@"E:\GCJ\file\C-large-practice.out", FileMode.OpenOrCreate));

        N = Convert.ToInt32(sRead.ReadLine());
        for (i = 0; i < N; i++)
        {
            tmp = sRead.ReadLine().Trim().Split(' ');
            L = Convert.ToInt32(tmp[0]);
            W = Convert.ToInt32(tmp[1]);

            condition = new char[W][];
            for (j = 0; j < W; j++)
            {
                condition[j] = sRead.ReadLine().ToCharArray();
            }

            area = getMaxRectangular(L, W, condition);
            sWrite.WriteLine("Case #{0}: {1}", i + 1, area);
        }
        sRead.Close();
        sWrite.Close();
    }

    private int getMaxRectangular(int L, int W, char[][] condition)
    {
        int i = 0;
        int j = 0;
        int m = 0;
        int n = 0;
        int pX = 0;
        int pY = 0;
        int area = 0;
        int maxArea = 0;
        bool possible = true;
        bool find = false;

        for (i = W; i > 0; i--)
        {
            for (j = L; j > 0; j--)
            {
                find = false;
                for (pX = 0; pX + i <= W && !find; pX++)
                {
                    for (pY = 0; pY + j <= L && !find; pY++)
                    {
                        possible = true;
                        for (m = 0; m < i && possible; m++)
                        {
                            for (n = 0; n < j && possible; n++)
                            {
                                if (condition[pX + m][pY + n] != 'G' && condition[pX + m][pY + n] != 'S')
                                {
                                    possible = false;
                                }
                            }
                        }
                        if (possible)
                        {
                            find = true;
                            area = i * j;
                        }

                    }
                }
                if (find && area > maxArea)
                {
                    maxArea = area;
                }
            }
        }
        return maxArea;
    }
}