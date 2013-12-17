using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace lab
{
    public class InsertZ
    {
        public string canTransform(string init, string goal)
        {
            string rz = "";
            string ret = "No";

            for (int i = 0; i < goal.Length; i++)
            {
                if (goal[i] != 'z')
                {
                    rz += goal[i];
                }
            }

            if (rz.Equals(init))
            {
                ret = "Yes";
            }
            return ret;
        }
    }
}
