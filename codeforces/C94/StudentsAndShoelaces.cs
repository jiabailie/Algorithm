using System;
using System.Collections.Generic;
using System.Text;

public class StudentsAndShoelaces
{
    public StudentsAndShoelaces()
    {
        int i = 0;
        int x = 0;
        int y = 0;
        int kick = 0;
        string[] s = Console.ReadLine().Split(' ');
        int n = Convert.ToInt32(s[0]);
        int m = Convert.ToInt32(s[1]);
        int[] connect = new int[n + 1];
        int[,] board = new int[n + 1, n + 1];
        List<int> remove = new List<int>();
        for (i = 0; i < m; i++)
        {
            s = Console.ReadLine().Split(' ');
            x = Convert.ToInt32(s[0]);
            y = Convert.ToInt32(s[1]);
            board[x, y] = board[y, x] = 1;
            connect[x]++;
            connect[y]++;
        }
        while (true)
        {
            remove.Clear();
            for (i = 1; i <= n; i++)
            {
                if (connect[i] == 1)
                {
                    remove.Add(i);
                }
            }
            if (remove.Count >= 1)
            {
                kick++;
                for (i = 0; i < remove.Count; i++)
                {
                    for (x = 1; x <= n; x++)
                    {
                        if (board[remove[i], x] == 1)
                        {
                            board[remove[i], x] = board[x, remove[i]] = 0;
                            connect[remove[i]]--;
                            connect[x]--;
                            break;
                        }
                    }
                }
            }
            else
            {
                break;
            }
        }
        Console.WriteLine(kick);
    }
}