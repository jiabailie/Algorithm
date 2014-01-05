using System;
using System.Collections.Generic;
using System.Text;

namespace CodeForces
{
    public class B
    {
        public string CorrectAnswer(string ask, string answer)
        {
            int i = 0;
            int temp = 0;
            string m = "";
            int[] ans = new int[ask.Length];

            for (i = 0; i < ask.Length; i++)
            {
                ans[i] = ask[i] - '0';
            }
            Array.Sort(ans);

            for (i = 0; i < ask.Length; i++)
            {
                if (ans[i] > 0)
                {
                    temp = ans[i];
                    ans[i] = ans[0];
                    ans[0] = temp;

                    break;
                }
            }
            for (i = 0; i < ask.Length; i++)
            {
                m += ans[i];
            }

            return m == answer ? "OK" : "WRONG_ANSWER";
        }
    }
}
