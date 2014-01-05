using System;
using System.Collections.Generic;
using System.Text;

namespace CodeForces
{
   public class C
    {
       public int[] GetFruits()
       {
           int i = 0;
           int n = 0;
           int m = 0;
           int min = 0;
           int max = 0;
           int[] price = null;
           int[] count = null;
           string[] items = null;
           string temp = Console.ReadLine();
           Dictionary<string, int> pair = new Dictionary<string, int>();

           n = Convert.ToInt32(temp.Split(' ')[0]);
           m = Convert.ToInt32(temp.Split(' ')[1]);

           price = new int[n];
           items = Console.ReadLine().Split(' ');
           for (i = 0; i < n; i++)
           {
               price[i] = Convert.ToInt32(items[i]);
           }
           Array.Sort(price);

           for (i = 0; i < m; i++)
           {
               temp = Console.ReadLine();
               if (pair.ContainsKey(temp))
               {
                   pair[temp]++;
               }
               else
               {
                   pair.Add(temp, 1);
               }
           }

           i = 0;
           count = new int[pair.Count];
           foreach (KeyValuePair<string, int> kvp in pair)
           {
               count[i++] = kvp.Value;
           }
           Array.Sort(count);

           for (i = 0; i < pair.Count; i++)
           {
               min += count[count.Length - i - 1] * price[i];
               max += count[count.Length - i - 1] * price[price.Length - i - 1];
           }

           return new int[] { min, max };
       }
   }
}
