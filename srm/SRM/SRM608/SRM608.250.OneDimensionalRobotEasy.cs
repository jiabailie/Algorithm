using System;

public class OneDimensionalRobotEasy
{
    public int finalPosition(string commands, int A, int B)
    {
        int pos = 0;

        A = -A;

        foreach (char c in commands)
        {
            if (c == 'L')
            {
                if (pos == A) { continue; }
                pos -= 1;
            }
            else if (c == 'R')
            {
                if (pos == B) { continue; }
                pos += 1;
            }
        }
        return pos;
    }
}
