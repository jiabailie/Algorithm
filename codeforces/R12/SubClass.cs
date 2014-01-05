using System;
using System.Collections.Generic;
using System.Text;

namespace CodeForces
{
    class SubClass
    {
        public int VirusAnalyse()
        {
            int i = 1;
            int temp = 0;
            int count = 0;
            int x = Convert.ToInt32(Console.ReadLine());

            for (; i < (1 << 11); i++)
            {
                temp = Convert.ToInt32(Convert.ToString(i, 2));

                if (temp <= x)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }

            return count;
        }
    }
}
