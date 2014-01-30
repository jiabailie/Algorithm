using System;
using System.Collections.Generic;
using System.Text;

public class EllysSubstringSorter
{
    public string getMin(string S, int L)
    {
        int i = 0, j = 0;

        char[] sa = new char[L];
        List<string> store = new List<string>();

        for (i = 0; i + L - 1 < S.Length; i++)
        {
            for (j = 0; j < L; j++)
            {
                sa[j] = S[i + j];
            }
            Array.Sort(sa);
            string tmp = S.Substring(0, i);
            foreach (char c in sa)
            {
                tmp += c;
            }
            tmp += S.Substring(i + L);
            store.Add(tmp);
        }
        store.Sort();

        return store[0];
    }
}
