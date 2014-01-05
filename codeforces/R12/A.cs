using System;
using System.Collections.Generic;
using System.Text;

namespace CodeForces
{
   public class A
    {
       public string IsSymmetric(string[] code)
       {
           bool result = code[0][0] == code[2][2] &&
               code[0][1] == code[2][1] &&
               code[0][2] == code[2][0] &&
               code[1][0] == code[1][2];

           return result ? "YES" : "NO";
       }
    }
}
