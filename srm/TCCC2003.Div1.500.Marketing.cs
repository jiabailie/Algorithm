/* Title: community.topcoder.com/stat?c=problem_statement&pm=1524&rd=4472&rm=&cr=107835 */
using System;
using System.Collections.Generic;
using System.Text;

public class Marketing
{
    public long howMany(string[] compete)
    {
        int i = 0;
        bool legal = true;
        long method = 1;
        int n = compete.Length;
        int[] color = new int[n];
        int top = 0, newColor = 0;
        List<List<int>> enemy = new List<List<int>>();
        Stack<int> istack = new Stack<int>();

        for (i = 0; i < n; i++)
        {
            enemy.Add(new List<int>());
        }
        for (i = 0; i < n; i++)
        {
            if (!string.IsNullOrEmpty(compete[i]))
            {
                string[] p = compete[i].Split(' ');
                
                foreach (string ss in p)
                {
                    newColor = Convert.ToInt32(ss);
                    enemy[i].Add(newColor);
                    enemy[newColor].Add(i);
                }
            }
        }

        while (true)
        {
            for (i = 0; i < n; i++)
            {
                if (color[i] == 0) { break; }
            }
            if (i == n) { break; }
            istack.Clear();
            istack.Push(i);
            color[i] = 1;
            while (istack.Count > 0)
            {
                top = istack.Pop();
                newColor = color[top] == 1 ? 2 : 1;
                foreach (int x in enemy[top])
                {
                    if (color[x] == 0)
                    {
                        color[x] = newColor;
                        istack.Push(x);
                    }
                    else if (color[x] == newColor)
                    {
                        continue;
                    }
                    else
                    {
                        legal = false;
                        break;
                    }
                }
                if (!legal) { break; }
            }
            if (!legal) { break; }
            else { method <<= 1; }
        }
        return legal ? method : -1;
    }
}
