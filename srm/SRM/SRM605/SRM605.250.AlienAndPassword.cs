using System;

public class AlienAndPassword
{
    public int getNumber(string S)
    {
        int ret = 1;
        char pre = S[0];
        for (int i = 1; i < S.Length; i++)
        {
            if (S[i] != pre)
            {
                ret++;
                pre = S[i];
            }
        }
        return ret;
    }
}
