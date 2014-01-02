using System;
using System.Collections.Generic;
using System.Text;

public class PilingRectsDiv2
{
	public int getmax(int[] X, int[] Y, int limit)
	{
		int i = 0, j = 0, k = 0;
		int ret = -1, tmp = 0, n = X.Length;

		for (i = 1; i <= 200; i++)
		{
			for (j = 1; j <= 200; j++)
			{
				if (i * j >= limit)
				{
					tmp = 0;
					for (k = 0; k < n; k++)
					{
						if ((X[k] >= i && Y[k] >= j) || (X[k] >= j && Y[k] >= i))
						{
							tmp += 1;
						}
					}

					if (tmp > 0 && tmp > ret)
					{
						ret = tmp;
					}
				}
			}
		}
		return ret;
	}
}