using System;
using System.Collections.Generic;
using System.Text;

public class PetrandBook
{
    public PetrandBook()
    {
        int i = 0;
        int sum = Convert.ToInt32(Console.ReadLine());
        int[] day = new int[7];
        string[] days = Console.ReadLine().Trim().Split(' ');
        for (i = 0; i < 7; day[i] = Convert.ToInt32(days[i]), i++) ;
        for (i = 0; sum > 0; sum -= day[i], i = (i + 1) % 7) ;
        Console.WriteLine(i);
    }
}
