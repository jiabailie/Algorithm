using System;
using System.Collections.Generic;
using System.Text;

public class FoxAndFencingEasy
{
    public string WhoCanWin(int mov1, int mov2, int d)
    {
        if (mov1 >= d)
        {
            return "Ciel";
        }
        else if (mov1 > mov2 * 2)
        {
            return "Ciel";
        }
        else if (mov2 > mov1 * 2)
        {
            return "Liss";
        }
        return "Draw";
    }
}
