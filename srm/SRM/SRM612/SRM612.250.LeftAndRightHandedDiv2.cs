using System;

public class LeftAndRightHandedDiv2
{
    public int count(string S)
    {
        int i = 0;
        int cnt = 0;
        for (i = 0; i < S.Length - 1; ++i)
        {
            if (S[i] == 'R' && S[i + 1] == 'L')
            {
                cnt += 1;
            }
        }
        return cnt;
    }
}