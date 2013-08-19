using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace lab
{
    public class calLabor
    {
        private static List<string> ReadLabor(string path)
        {
            List<string> timeSet = new List<string>();
            StreamReader sr = new StreamReader(path);
            string oneLine = sr.ReadLine();
            while (!string.IsNullOrEmpty(oneLine))
            {
                timeSet.Add(oneLine.Trim());
                oneLine = sr.ReadLine();
            }
            sr.Dispose();
            sr.Close();

            return timeSet;
        }

        private static int calTotalMin(List<string> timeSet)
        {
            int cnt = timeSet.Count;
            int totalMin = 0;
            foreach (string s in timeSet)
            {
                string[] sspan = s.Split(new char[] { '~', ':' });
                int startT = Convert.ToInt32(sspan[0]) * 60 + Convert.ToInt32(sspan[1]);
                int endT = Convert.ToInt32(sspan[2]) * 60 + Convert.ToInt32(sspan[3]);

                totalMin += endT - startT;
            }

            return totalMin;
        }

        public static void MainBranch()
        {
            List<string> timeSet = ReadLabor(@"..\..\txt\labor.txt");
            int totalMin = calTotalMin(timeSet);
            int needTime = 9 * 60 * timeSet.Count;

            Console.WriteLine(string.Format("You need to do extra work about {0} minutes", needTime - totalMin));
        }
    }
}