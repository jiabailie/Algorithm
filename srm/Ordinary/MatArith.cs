using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

public class MatArith
{
    private bool valid = true;
    private const long g_min = -2147483648;
    private const long g_max = 2147483647;

    private void transferStringToIArray(long h, string[] data, ref long w, ref long[][] idata)
    {
        long i = 0, j = 0;
        string[] ss = null;
        for (i = 0; i < h; i++)
        {
            ss = data[i].Split(' ');
            w = ss.Length;
            idata[i] = new long[w];
            for (j = 0; j < w; j++)
            {
                idata[i][j] = Convert.ToInt64(ss[j]);
            }
        }
    }

    private bool calMultiply(long[] h, long[] w, long[][][] matrix, string[] factor, ref long[] size, ref long[][] res)
    {
        bool legal = true;
        long i = 0, l = factor.Length;
        long[] ifactor = new long[l];

        for (i = 0; i < l; ifactor[i] = Convert.ToInt64(factor[i][0] - '0'), i++) ;

        long rh = h[ifactor[0]];
        long rw = w[ifactor[0]];

        res = matrix[ifactor[0]];

        for (i = 1; i < l && legal; i++)
        {
            if (w[ifactor[i - 1]] != h[ifactor[i]])
            {
                legal = false;
            }
        }
        if (legal)
        {
            for (i = 1; valid && i < l; i++)
            {
                res = calSubMultiply(rh, rw, h[ifactor[i]], w[ifactor[i]], res, matrix[ifactor[i]]);
                rw = w[ifactor[i]];
            }
            size = new long[] { rh, rw };
        }

        return legal;
    }

    private long[][] calAddition(long h, long w, long[][] m1, long[][] m2)
    {
        long[][] res = new long[h][];
        for (long i = 0; valid && i < h; i++)
        {
            res[i] = new long[w];
            for (long j = 0; valid && j < w; j++)
            {
                res[i][j] = m1[i][j] + m2[i][j];
                if (res[i][j] > g_max && res[i][j] < g_min) { valid = false; }
            }
        }
        return res;
    }

    private long[][] calSubMultiply(long h1, long w1, long h2, long w2, long[][] m1, long[][] m2)
    {
        long i = 0, j = 0, k = 0;
        long[][] res = new long[h1][];
        for (i = 0; valid && i < h1; i++)
        {
            res[i] = new long[w2];
            for (j = 0; valid && j < w2; j++)
            {
                res[i][j] = 0;
                for (k = 0; valid && k < w1; k++)
                {
                    res[i][j] += m1[i][k] * m2[k][j];
                    if (res[i][j] > g_max && res[i][j] < g_min) { valid = false; }
                }
            }
        }
        return res;
    }

    public string[] calculate(string[] A, string[] B, string[] C, string equation)
    {
        long i = 0, j = 0;
        long rh = 0, rw = 0;
        long[] h = new long[3] { A.Length, B.Length, C.Length };
        long[] w = new long[3];
        long[][] res = null;
        long[][][] matrix = new long[3][][];
        string[] factor = equation.Replace('A', '0').Replace('B', '1').Replace('C', '2').Split('+');
        Dictionary<string, long[][]> dFactor = new Dictionary<string, long[][]>();
        Dictionary<string, long[]> dFactorSize = new Dictionary<string, long[]>();

        for (i = 0; i < 3; i++)
        {
            matrix[i] = new long[h[i]][];
            transferStringToIArray(h[i], i == 0 ? A : (i == 1 ? B : C), ref w[i], ref matrix[i]);
        }

        for (i = 0; i < factor.Length && valid; i++)
        {
            if (dFactor.ContainsKey(factor[i])) { continue; }
            string[] mulFactor = factor[i].Split('*');
            if (mulFactor.Length == 1)
            {
                dFactor.Add(mulFactor[0], matrix[Convert.ToInt64(mulFactor[0][0] - '0')]);
                dFactorSize.Add(mulFactor[0], new long[] { h[Convert.ToInt64(mulFactor[0][0] - '0')], w[Convert.ToInt64(mulFactor[0][0] - '0')] });
            }
            else
            {
                long[] size = null;
                long[][] partRes = null;
                bool legal = calMultiply(h, w, matrix, mulFactor, ref size, ref partRes);
                if (legal)
                {
                    dFactor.Add(factor[i], partRes);
                    dFactorSize.Add(factor[i], size);
                }
            }
        }

        if (valid)
        {
            // do matrix addition
            rh = dFactorSize[factor[0]][0];
            rw = dFactorSize[factor[0]][0];

            if (factor.Length == 1)
            {
                res = dFactor[factor[0]];
            }
            else
            {
                for (i = 1; i < factor.Length && valid; i++)
                {
                    if (dFactorSize[factor[i - 1]][0] != dFactorSize[factor[i]][0] || dFactorSize[factor[i - 1]][1] != dFactorSize[factor[i]][1])
                    {
                        valid = false;
                    }
                }
                if (valid)
                {
                    res = dFactor[factor[0]];
                    for (i = 1; i < factor.Length; i++)
                    {
                        res = calAddition(rh, rw, res, dFactor[factor[i]]);
                    }
                }
            }
        }

        factor = new string[rh];
        for (i = 0; i < rh && valid; i++)
        {
            factor[i] = "";
            for (j = 0; j < rw && valid; j++)
            {
                if (res[i][j] > g_max && res[i][j] < g_min) { valid = false; }
                else { factor[i] += res[i][j].ToString() + " "; }
            }
            factor[i] = factor[i].Trim();
        }

        return valid ? factor : new string[] { };
    }
}