using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJ
{
    public class ReverseWords
    {
        public ReverseWords()
        {
            int i = 0;
            int N = 0;
            string reverse = null;
            string[] items = null;
            StreamReader sRead = new StreamReader(new FileStream(@"D:\ACM\Codes\GCJ\file\B-large-practice.in", FileMode.Open));
            StreamWriter sWrite = new StreamWriter(new FileStream(@"D:\ACM\Codes\GCJ\file\B-large-practice.out", FileMode.OpenOrCreate));
            N = Convert.ToInt32(sRead.ReadLine());

            for (i = 0; i < N; i++)
            {
                items = sRead.ReadLine().Split(' ');

                reverse = ReverseItems(items);

                sWrite.WriteLine("Case #{0}: {1}", i + 1, reverse);
            }

            sRead.Close();
            sWrite.Close();
        }

        private string ReverseItems(string[] items)
        {
            int i = 0;
            string reverse = "";

            for (i = items.Length - 1; i >= 0; i--)
            {
                reverse += items[i] + " ";
            }

            return reverse.Substring(0, reverse.Length - 1);
        }
    }
}
