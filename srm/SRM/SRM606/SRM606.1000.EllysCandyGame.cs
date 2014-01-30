using System;
using System.Collections.Generic;
using System.Text;

public class EllysCandyGame
{
    // 0 Draw, 1 Elly, 2 Kris 
    private int win = 0;

    private int score = 0;

    // who = true, is Elly
    // who = false, is Kris
    private void onestep(bool who, int ellyScore, int krisScore, int[] sweets)
    {
        int len = sweets.Length;
        int max = -1, maxneighbour = 0;
        for (int i = 0; i < len; i++)
        {
            if (sweets[i] > 0)
            {
                if (max == -1)
                {
                    max = i;
                }
                else
                {
                    if (sweets[i] > sweets[max])
                    {
                        max = i;
                        maxneighbour = 0;
                        if (i - 1 >= 0)
                        {
                            maxneighbour += sweets[i - 1];
                        }
                        if (i + 1 < len)
                        {
                            maxneighbour += sweets[i + 1];
                        }
                    }
                    else if (sweets[i] == sweets[max])
                    {
                        int tmp = 0;
                        if (i - 1 >= 0)
                        {
                            tmp += sweets[i - 1];
                        }
                        if (i + 1 < len)
                        {
                            tmp += sweets[i + 1];
                        }
                        if (tmp < maxneighbour)
                        {
                            max = i;
                            maxneighbour = tmp;
                        }
                    }
                }
            }
        }
        if (max == -1)
        {
            if (ellyScore > krisScore && ellyScore > score)
            {
                win = 1;
                score = ellyScore;
            }
            else if (ellyScore < krisScore && krisScore > score)
            {
                win = 2;
                score = krisScore;
            }
            else if (ellyScore == krisScore && ellyScore > score)
            {
                win = 0;
                score = ellyScore;
            }
            else if ((ellyScore == score && win == 2) || (krisScore == score && win == 1))
            {
                win = 0;
            }
        }
        else
        {
            int[] copy = new int[len];
            for (int j = 0; j < len; copy[j] = sweets[j], j++) ;

            copy[max] = 0;

            if (max - 1 >= 0) { copy[max - 1] *= 2; }
            if (max + 1 < len) { copy[max + 1] *= 2; }

            if (who) { onestep(false, ellyScore + sweets[max], krisScore, copy); }
            else { onestep(true, ellyScore, krisScore + sweets[max], copy); }
        }
    }

    public string getWinner(int[] sweets)
    {
        onestep(true, 0, 0, sweets);

        if (win == 1) { return "Elly"; }
        if (win == 2) { return "Kris"; }
        return "Draw";
    }
}
