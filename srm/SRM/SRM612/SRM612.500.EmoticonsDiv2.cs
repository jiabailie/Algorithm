using System;

public class EmoticonsDiv2
{
    private int Smiles = 0;
    private int p = 0;

    private void step(int clipboard, int ops, int window)
    {
        if (ops >= p) { return; }
        if (window >= Smiles)
        {
            if (window == Smiles)
            {
                p = Math.Min(p, ops);
            }
            return;
        }

        // copy
        if (window > clipboard)
        {
            step(window, ops + 1, window);
        }

        // paste
        if (clipboard > 0)
        {
            step(clipboard, ops + 1, window + clipboard);
        }
    }

    public int printSmiles(int smiles)
    {
        Smiles = smiles;
        p = 2000;
        step(0, 0, 1);

        return p;
    }
}