using System;
using System.Collections.Generic;
using System.Text;

public class YetAnotherTwoTeamsProblem
{
    public long count(int[] skill)
    {
        int sum = 0;
        int i = 0, j = 0;
        int n = skill.Length;
        long res = 0;

        for (i = 0; i < n; i++) { sum += skill[i]; }
        Array.Sort(skill);

        long[] dp = new long[sum + sum / 2];
        int mid = (sum - 1) >> 1;
        dp[0] = 1;
        for (i = n - 1; i >= 0; i--)
        {
            for (j = mid + skill[i]; j >= skill[i]; j--)
            {
                dp[j] += dp[j - skill[i]];
                //if (j > sum - j && j - skill[i] < sum - j + skill[i])
                if (2 * j > sum && 2 * (j - skill[i]) < sum)
                {
                    res += dp[j - skill[i]];
                }
            }
        }
        return res;
    }
}
