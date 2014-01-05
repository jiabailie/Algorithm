using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ.practice
{
    /*
    public class BadHorse1
    {
        private int M = 0;
        private int n = 0;
        private bool[,] badPair = null;

        // x is compatible with the elememts of source.
        private bool Compatible(int x, int p, int[] source)
        {
            for (int i = 0; i <= p; i++)
            {
                if (badPair[x, source[i]]) { return false; }
            }
            return true;
        }

        // in visit[], random two which are false status are all compatible.
        private bool Compatible(bool[] visit)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (!visit[i])
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        if (!visit[j] && badPair[i, j])
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }

        private string canBeSplit()
        {
            bool canSplit = false;
            int i = 0, j = 0;

            for (i = 0; i < n && !canSplit; i++)
            {
                int p = 0;
                bool[] visit = new bool[n];
                int[] part = new int[n + 1];

                visit[i] = true;
                part[p] = i;

                for (j = 0; j < n && !canSplit; j++)
                {
                    if (Compatible(visit))
                    {
                        canSplit = true;
                        continue;
                    }
                    if (!visit[j])
                    {
                        if (!Compatible(j, p, part))
                        {
                            continue;
                        }
                        part[++p] = j;
                        visit[j] = true;
                        if (Compatible(visit))
                        {
                            canSplit = true;
                        }
                    }
                }
            }

            return canSplit ? "Yes" : "No";
        }

        public BadHorse1()
        {
            int i = 0, j = 0;
            int T = 0, c = 0; ;

            StreamReader sRead = new StreamReader(new FileStream(@"..\..\file\A-small-2-attempt4.in", FileMode.Open));
            StreamWriter sWrite = new StreamWriter(new FileStream(@"..\..\file\A-small-2-attempt4.out", FileMode.OpenOrCreate));
            T = Convert.ToInt32(sRead.ReadLine());

            for (i = 0; i < T; i++)
            {
                c = 0;
                M = Convert.ToInt32(sRead.ReadLine());
                if (M == 1)
                {
                    sRead.ReadLine();
                    sWrite.WriteLine("Case #{0}: Yes", (i + 1));
                    continue;
                }
                Dictionary<string, int> nameMapping = new Dictionary<string, int>();
                badPair = new bool[200, 200];
                for (j = 0; j < M; j++)
                {
                    string[] tmp = sRead.ReadLine().Trim().Split(' ');
                    foreach (string s in tmp)
                    {
                        if (!nameMapping.ContainsKey(s))
                        {
                            nameMapping.Add(s, c++);
                        }
                    }
                    badPair[nameMapping[tmp[0]], nameMapping[tmp[1]]] = true;
                    badPair[nameMapping[tmp[1]], nameMapping[tmp[0]]] = true;
                }
                n = nameMapping.Count;
                if (M * 2 == n)
                {
                    sWrite.WriteLine("Case #{0}: Yes", (i + 1));
                    continue;
                }

                sWrite.WriteLine("Case #{0}: {1}", (i + 1), canBeSplit());
            }

            sRead.Close();
            sWrite.Close();
        }
    }

    public class BadHorse2
    {
        private int n = 0;
        private bool[,] badPair = null;
        private bool gCanSplit = true;

        private void split()
        {
            int i = 0;
            List<int> unassigned = new List<int>();
            List<int> A = new List<int>();
            List<int> B = new List<int>();

            for (i = 0; i < n; i++) { unassigned.Add(i); }

            while (unassigned.Count > 0 && gCanSplit)
            {
                int first = unassigned[0];
                A.Add(first);
                unassigned.Remove(first);

                for (i = 0; i < n && gCanSplit && unassigned.Count > 0; i++)
                {
                    if (unassigned.Contains(i))
                    {
                        bool canPutA = true;
                        bool canPutB = true;

                        if (A.Count > 0)
                        {
                            foreach (int a in A)
                            {
                                if (badPair[i, a]) { canPutA = false; break; }
                            }
                        }
                        if (B.Count > 0)
                        {
                            foreach (int b in B)
                            {
                                if (badPair[i, b]) { canPutB = false; break; }
                            }
                        }
                        if (!canPutA && !canPutB)
                        {
                            gCanSplit = false;
                        }
                        else if (canPutA && !canPutB)
                        {
                            A.Add(i);
                            unassigned.Remove(i);
                        }
                        else if (!canPutA && canPutB)
                        {
                            B.Add(i);
                            unassigned.Remove(i);
                        }
                    }
                }
            }
        }

        public BadHorse2()
        {
            int i = 0, j = 0;
            int T = 0, M = 0, c = 0; ;

            StreamReader sRead = new StreamReader(new FileStream(@"..\..\file\A-small-2-attempt10.in", FileMode.Open));
            StreamWriter sWrite = new StreamWriter(new FileStream(@"..\..\file\A-small-2-attempt10.out", FileMode.OpenOrCreate));
            T = Convert.ToInt32(sRead.ReadLine());

            for (i = 0; i < T; i++)
            {
                c = 0;
                M = Convert.ToInt32(sRead.ReadLine());
                if (M == 1)
                {
                    sRead.ReadLine();
                    sWrite.WriteLine("Case #{0}: Yes", (i + 1));
                    continue;
                }
                Dictionary<string, int> nameMapping = new Dictionary<string, int>();
                badPair = new bool[200, 200];
                for (j = 0; j < M; j++)
                {
                    string[] tmp = sRead.ReadLine().Trim().Split(' ');
                    foreach (string s in tmp)
                    {
                        if (!nameMapping.ContainsKey(s))
                        {
                            nameMapping.Add(s, c++);
                        }
                    }
                    badPair[nameMapping[tmp[0]], nameMapping[tmp[1]]] = true;
                    badPair[nameMapping[tmp[1]], nameMapping[tmp[0]]] = true;
                }
                n = nameMapping.Count;
                split();
                sWrite.WriteLine("Case #{0}: {1}", (i + 1), gCanSplit ? "Yes" : "No");
            }

            sRead.Close();
            sWrite.Close();
        }
    }
    */
    public class BadHorse
    {
        private int n = 0;
        private bool[,] badPair = null;
        private bool gCanSplit = true;

        private void dfs(int p, int len, bool[] visited, int[] record)
        {
            for (int i = 1; i <= n && gCanSplit; i++)
            {
                if (len > 2 && visited[i] && badPair[p, i])
                {
                    int c = 1;
                    for (int j = len; j >= 0 && record[j] != i; j--, c++) ;
                    if ((c & 1) == 1)
                    {
                        gCanSplit = false;
                        continue;
                    }
                }
                if (!visited[i] && badPair[p, i])
                {
                    visited[i] = true;
                    record[len + 1] = i;

                    dfs(i, len + 1, visited, record);

                    visited[i] = false;
                    record[len + 1] = 0;
                }
            }
        }

        private void split()
        {
            for (int i = 1; i <= n && gCanSplit; i++)
            {
                bool[] visited = new bool[n + 1];
                int[] record = new int[n + 1];

                visited[i] = true;
                record[1] = i;

                dfs(i, 1, visited, record);
            }
        }

        public BadHorse()
        {
            int i = 0, j = 0;
            int T = 0, M = 0, c = 0; ;

            StreamReader sRead = new StreamReader(new FileStream(@"..\..\file\A-small-2-attempt10.in", FileMode.Open));
            StreamWriter sWrite = new StreamWriter(new FileStream(@"..\..\file\A-small-2-attempt10.out", FileMode.OpenOrCreate));
            T = Convert.ToInt32(sRead.ReadLine());

            for (i = 0; i < T; i++)
            {
                c = 1;
                M = Convert.ToInt32(sRead.ReadLine());
                if (M == 1)
                {
                    sRead.ReadLine();
                    sWrite.WriteLine("Case #{0}: Yes", (i + 1));
                    continue;
                }
                Dictionary<string, int> nameMapping = new Dictionary<string, int>();
                badPair = new bool[201, 201];
                for (j = 0; j < M; j++)
                {
                    string[] tmp = sRead.ReadLine().Trim().Split(' ');
                    foreach (string s in tmp)
                    {
                        if (!nameMapping.ContainsKey(s))
                        {
                            nameMapping.Add(s, c++);
                        }
                    }
                    badPair[nameMapping[tmp[0]], nameMapping[tmp[1]]] = true;
                    badPair[nameMapping[tmp[1]], nameMapping[tmp[0]]] = true;
                }
                n = nameMapping.Count;
                split();
                sWrite.WriteLine("Case #{0}: {1}", (i + 1), gCanSplit ? "Yes" : "No");
            }

            sRead.Close();
            sWrite.Close();
        }
    }
}
