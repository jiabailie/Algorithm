/* Using four methods to solve the maximum subarray problem. */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace lab.Algorithm
{
    public class findMaxSum
    {
        public int imax(int x, int y)
        {
            return x > y ? x : y;
        }
        
        /* Dynamic programming from left to right. */
        public int findMaxSum1(int n, int[] d)
        {
            int end = d[0];
            int all = d[0];
            for (int i = 1; i < n; i++)
            {
                end = imax(d[i], end + d[i]);
                all = imax(end, all);
            }
            return all;
        }
        
        /* Dynamic programming from right to left. */
        public int findMaxSum2(int n, int[] d)
        {
            int start = d[n - 1];
            int all = d[n - 1];
            for (int i = n - 2; i >= 0; i--)
            {
                start = imax(d[i], d[i] + start);
                all = imax(start, all);
            }
            return all;
        }
        
        /* Kadane's algorithm */
        public int findMaxSum3(int n, int[] d)
        {
            int ret = int.MinValue;
            int tmp = 0;
            for (int i = 0; i < n; i++)
            {
                tmp += d[i];
                if (tmp < 0) { tmp = 0; }
                else { if (tmp > ret) { ret = tmp; } }
            }
            return ret;
        }
        
        /* General O(n^2) method. */
        public int findMaxSum4(int n, int[] d)
        {
            int i = 0, j = 0;
            int ret = int.MinValue, tmp = 0;
            for (i = 0; i < n; i++)
            {
                tmp = 0;
                for (j = i; j < n; j++)
                {
                    tmp += d[j];
                    if (tmp > ret) { ret = tmp; }
                }
            }
            return ret;
        }
        
        /* Test if they have the same results. */
        public findMaxSum()
        {
            int cnt = 0;
            Random r = new Random();
            for (int k = 0; k < 100; k++)
            {
                int n = r.Next(10, 200);
                int[] d = new int[n];
                for (int i = 0; i < n; i++)
                {
                    d[i] = r.Next(-100, 100);
                }
                int r1 = findMaxSum1(n, d);
                int r2 = findMaxSum2(n, d);
                int r3 = findMaxSum3(n, d);
                int r4 = findMaxSum4(n, d);

                if (r1 == r2 && r1 == r3 && r1 == r4)
                {
                    cnt++;
                }
            }
            Console.WriteLine(cnt);
        }
    }
}
