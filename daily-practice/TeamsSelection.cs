using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace lab
{
    public class TeamsSelection
    {
        public string simulate(int[] preference1, int[] preference2)
        {
            int i = 0;
            int p1 = -1;
            int p2 = -1;
            int n = preference1.Length;
            string ret = "";
            int[] team = new int[n];

            while (p1 + 1 < n || p2 + 1 < n)
            {
                while (p1 + 1 < n)
                {
                    p1++;
                    if (team[preference1[p1] - 1] == 0)
                    {
                        team[preference1[p1] - 1] = 1;
                        break;
                    }
                }
                while (p2 + 1 < n)
                {
                    p2++;
                    if (team[preference2[p2] - 1] == 0)
                    {
                        team[preference2[p2] - 1] = 2;
                        break;
                    }
                }
            }

            for (i = 0; i < n; i++)
            {
                ret += team[i].ToString();
            }

            return ret;
        }
    }
}
