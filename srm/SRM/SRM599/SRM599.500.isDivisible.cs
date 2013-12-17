using System;
using System.Collections.Generic;
using System.Text;

public class BigFatInteger2
{
    private List<int> prime = new List<int>();

    private bool isprime(int x)
    {
        bool yes = true;
        if (x == 1) { return false; }
        if (x == 2) { return true; }
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                yes = false;
                break;
            }
        }
        return yes;
    }

    private void separate(int x, int p, Dictionary<long, long> dic)
    {
        int add = 0;
        while (x > 1)
        {
            if (isprime(x))
            {
                add = x;
            }
            else
            {
                foreach (int i in prime)
                {
                    if (x % i == 0)
                    {
                        add = i;
                        break;
                    }
                }
            }
            if (dic.ContainsKey(add))
            {
                dic[add] += p;
            }
            else
            {
                dic[add] = p;
            }
            x /= add;
        }
    }

    public string isDivisible(int A, int B, int C, int D)
    {
        if ((A == 1 && C == 1) || (A == C && B >= D)) { return "divisible"; }
        bool divisible = true;

        Dictionary<long, long> ab = new Dictionary<long, long>();
        Dictionary<long, long> cd = new Dictionary<long, long>();

        int i = 0, j = 0;
        bool[] f = new bool[100000];
        f[0] = true;
        f[1] = true;
        for (i = 2; i < 100000; i++)
        {
            if (!f[i] && i + i < 100000)
            {
                for (j = i + i; j < 100000; f[j] = true, j += i) ;
            }
        }
        for (i = 1; i < 100000; i++)
        {
            if (!f[i])
            {
                prime.Add(i);
            }
        }

        separate(A, B, ab);
        separate(C, D, cd);

        foreach (KeyValuePair<long, long> kvp in cd)
        {
            if ((!ab.ContainsKey(kvp.Key)) || (ab.ContainsKey(kvp.Key) && ab[kvp.Key] < kvp.Value))
            {
                divisible = false;
                break;
            }
        }

        return divisible ? "divisible" : "not divisible";
    }
}
