using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJ
{
    public class B
    {
        public B()
        {
            int i = 0;
            int T = 0;
            string temp = null;
            StreamReader sRead = new StreamReader(new FileStream(@"E:\GCJ\file\b.in", FileMode.Open));
            StreamWriter sWrite = new StreamWriter(new FileStream(@"E:\GCJ\file\b.out", FileMode.OpenOrCreate));
            T = Convert.ToInt32(sRead.ReadLine());
            for (i = 0; i < T; i++)
            {
                temp = invoke(sRead.ReadLine().Split(' '));
                sWrite.WriteLine("Case #{0}: {1}", i + 1, temp);
            }

            sRead.Close();
            sWrite.Close();
        }

        private string invoke(string[] items)
        {
            int i = 0;
            int j = 0;
            int k = 0;
            int C = Convert.ToInt32(items[0]);
            int D = 0;
            int len = 0;
            bool flag = false;
            string res = null;
            string tmp = null;
            char[] elements = null;
            List<string> delete = new List<string>();
            Dictionary<string, char> combine = new Dictionary<string, char>();

            for (j = 0; j < C; j++)
            {
                i++;
                tmp = "" + items[i][0] + items[i][1];
                if (!combine.ContainsKey(tmp))
                {
                    combine.Add(tmp, items[i][2]);
                }
                tmp = "" + items[i][1] + items[i][0];
                if (!combine.ContainsKey(tmp))
                {
                    combine.Add(tmp, items[i][2]);
                }
            }
            D = Convert.ToInt32(items[++i]);
            for (j = 0; j < D; j++)
            {
                i++;
                tmp = "" + items[i][0] + items[i][1];
                if (!delete.Contains(tmp))
                {
                    delete.Add(tmp);
                }
                tmp = "" + items[i][1] + items[i][0];
                if (!delete.Contains(tmp))
                {
                    delete.Add(tmp);
                }
            }
            len = Convert.ToInt32(items[++i]);
            elements = new char[len];
            elements[0] = items[++i][0];

            for (j = 1; j < len; j++)
            {
                //test combine
                //judge the pre char has not been removed
                elements[j] = items[i][j];
                if (combine.Count > 0 && elements[j - 1] != '*')
                {
                    tmp = "" + elements[j - 1] + elements[j];
                    if (combine.ContainsKey(tmp))
                    {
                        elements[j - 1] = '*';
                        elements[j] = combine[tmp];
                    }
                }
                //test delete
                if (delete.Count > 0)
                {
                    flag = false;
                    for (k = j - 1; k > -1; k--)
                    {
                        tmp = "" + elements[k] + elements[j];
                        if (delete.Contains(tmp))
                        {
                            flag = true;
                            break;
                        }
                    }
                    if (flag)
                    {
                        for (k = 0; k <= j; k++)
                        {
                            elements[k] = '*';
                        }
                    }
                }
            }

            res = "[";
            for (j = 0; j < elements.Length; j++)
            {
                if (elements[j] != '*')
                {
                    res += elements[j] + ", ";
                }
            }
            res = res == "[" ? res + "]" : res.Substring(0, res.Length - 2) + "]";
            return res;
        }
    }
}
