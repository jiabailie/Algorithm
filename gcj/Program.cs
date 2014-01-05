using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJ
{
    class Program
    {
        static void Main(string[] args)
        {
            Moist m = new Moist();
            Console.WriteLine("finished");
            Console.ReadLine();
        }
    }

    public class Moist
    {
        private void dfs(int cur, int n, int[] orderNum, ref bool[] visited)
        {
            if (!visited[cur])
            {
                visited[cur] = true;
                int next = orderNum[cur];
                if (!visited[next])
                {
                    dfs(next, n, orderNum, ref visited);
                }
            }
        }

        private int calculateMoves(bool[] visited)
        {
            int c = 0;
            int n = visited.Length;
            for (int i = 0; i < n; )
            {
                if (visited[i])
                {
                    c++;
                    while (i < n && visited[i]) { i++; }
                }
                i++;
            }
            return c;
        }

        private int calculateFees(int n, string[] cardsDeck, string[] ocardsDeck)
        {
            int i = 0, j = 0;
            int ret = 0;
            int[] orderNum = new int[n];
            Dictionary<string, int> cardIndex = new Dictionary<string, int>();
            for (i = 0; i < n; i++)
            {
                cardIndex.Add(ocardsDeck[i], i);
            }
            for (i = 0; i < n; i++)
            {
                orderNum[i] = cardIndex[cardsDeck[i]];
            }
            bool[] gVisited = new bool[n];
            for (i = 0; i < n; i++)
            {
                if (gVisited[i]) { continue; }
                if (orderNum[i] == i) { gVisited[i] = true; }
                if (orderNum[i] != i)
                {
                    bool[] visited = new bool[n];
                    dfs(orderNum[i], n, orderNum, ref visited);
                    for (j = 0; j < n; j++)
                    {
                        if (visited[j])
                        {
                            gVisited[j] = true;
                        }
                    }
                    ret += calculateMoves(visited);
                }
            }
            return ret;
        }

        public Moist()
        {
            int i = 0, j = 0;
            int T = 0, N = 0;

            StreamReader sRead = new StreamReader(new FileStream(@"..\..\file\C-small-1-attempt1.in", FileMode.Open));
            StreamWriter sWrite = new StreamWriter(new FileStream(@"..\..\file\C-small-1-attempt1.out", FileMode.OpenOrCreate));
            T = Convert.ToInt32(sRead.ReadLine());
            for (i = 0; i < T; i++)
            {
                N = Convert.ToInt32(sRead.ReadLine());

                string tmp = null;
                string[] cardsDeck = new string[N];
                string[] ocardsDeck = new string[N];

                for (j = 0; j < N; j++)
                {
                    tmp = sRead.ReadLine();
                    cardsDeck[j] = tmp;
                    ocardsDeck[j] = tmp;
                }
                Array.Sort(ocardsDeck);
                int chargeFees = calculateFees(N, cardsDeck, ocardsDeck);
                sWrite.WriteLine("Case #{0}: {1}", (i + 1), chargeFees);
            }

            sRead.Close();
            sWrite.Close();
        }
    }
}
