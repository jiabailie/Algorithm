using System;
using System.Collections.Generic;
using System.Text;

public class AstronomicalRecordsEasy
{
    public int minimalPlanets(int[] A, int[] B)
    {
        int i = 0;
        int res = A.Length + B.Length;
        HashSet<int> iset = new HashSet<int>();
        foreach (int p in A)
        {
            foreach (int q in B)
            {
                iset.Clear();
                for (i = 0; i < A.Length; i++)
                {
                    iset.Add(A[i] * q);
                }
                for (i = 0; i < B.Length; i++)
                {
                    iset.Add(B[i] * p);
                }
                res = Math.Min(res, iset.Count);
            }
        }

        return res;
    }
}
