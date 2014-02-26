using System;
using System.Collections.Generic;

public class DivideByZero
{
    public int CountNumbers(int[] numbers)
    {
        int i = 0, j = 0;
        int r = 0, cnt = numbers.Length;
        bool changed = false;
        bool[] exist = new bool[101];

        for (i = 0; i < numbers.Length; ++i)
        {
            exist[numbers[i]] = true;
        }

        while (true)
        {
            changed = false;

            for (i = 1; i <= 100; ++i)
            {
                if (exist[i])
                {
                    for (j = i + 1; j <= 100; ++j)
                    {
                        if (exist[j])
                        {
                            r = j / i;
                            if (!exist[r])
                            {
                                cnt++;
                                exist[r] = true;
                                changed = true;
                            }
                        }
                    }
                }
            }

            if (!changed)
            {
                break;
            }
        }

        return cnt;
    }
}
