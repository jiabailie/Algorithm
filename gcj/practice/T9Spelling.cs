using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJ
{
    public class T9Spelling
    {
        public T9Spelling()
        {
            int i = 0;
            int N = 0;
            string t9 = null;
            string items = null;
            Dictionary<char, int> KeyBoard = new Dictionary<char, int>();
            Dictionary<char, string> KeyCode = new Dictionary<char, string>();

            KeyBoard.Add(' ', '0');
            KeyBoard.Add('a', '2');
            KeyBoard.Add('b', '2');
            KeyBoard.Add('c', '2');
            KeyBoard.Add('d', '3');
            KeyBoard.Add('e', '3');
            KeyBoard.Add('f', '3');
            KeyBoard.Add('g', '4');
            KeyBoard.Add('h', '4');
            KeyBoard.Add('i', '4');
            KeyBoard.Add('j', '5');
            KeyBoard.Add('k', '5');
            KeyBoard.Add('l', '5');
            KeyBoard.Add('m', '6');
            KeyBoard.Add('n', '6');
            KeyBoard.Add('o', '6');
            KeyBoard.Add('p', '7');
            KeyBoard.Add('q', '7');
            KeyBoard.Add('r', '7');
            KeyBoard.Add('s', '7');
            KeyBoard.Add('t', '8');
            KeyBoard.Add('u', '8');
            KeyBoard.Add('v', '8');
            KeyBoard.Add('w', '9');
            KeyBoard.Add('x', '9');
            KeyBoard.Add('y', '9');
            KeyBoard.Add('z', '9');

            KeyCode.Add(' ', "0");
            KeyCode.Add('a', "2");
            KeyCode.Add('b', "22");
            KeyCode.Add('c', "222");
            KeyCode.Add('d', "3");
            KeyCode.Add('e', "33");
            KeyCode.Add('f', "333");
            KeyCode.Add('g', "4");
            KeyCode.Add('h', "44");
            KeyCode.Add('i', "444");
            KeyCode.Add('j', "5");
            KeyCode.Add('k', "55");
            KeyCode.Add('l', "555");
            KeyCode.Add('m', "6");
            KeyCode.Add('n', "66");
            KeyCode.Add('o', "666");
            KeyCode.Add('p', "7");
            KeyCode.Add('q', "77");
            KeyCode.Add('r', "777");
            KeyCode.Add('s', "7777");
            KeyCode.Add('t', "8");
            KeyCode.Add('u', "88");
            KeyCode.Add('v', "888");
            KeyCode.Add('w', "9");
            KeyCode.Add('x', "99");
            KeyCode.Add('y', "999");
            KeyCode.Add('z', "9999");
            StreamReader sRead = new StreamReader(new FileStream(@"D:\ACM\Codes\GCJ\file\C-large-practice.in", FileMode.Open));
            StreamWriter sWrite = new StreamWriter(new FileStream(@"D:\ACM\Codes\GCJ\file\C-large-practice.out", FileMode.OpenOrCreate));
            N = Convert.ToInt32(sRead.ReadLine());

            for (i = 0; i < N; i++)
            {
                items = sRead.ReadLine();

                t9 = GetT9Code(items, KeyBoard, KeyCode);

                sWrite.WriteLine("Case #{0}: {1}", i + 1, t9);
            }

            sRead.Close();
            sWrite.Close();
        }

        private string GetT9Code(string items, Dictionary<char, int> KeyBoard, Dictionary<char, string> KeyCode)
        {
            int i = 0;
            int pre = 0;
            string spelling = KeyCode[items[0]];

            for (i = 1; i < items.Length; i++)
            {
                if (KeyBoard[items[i]] == KeyBoard[items[pre]])
                {
                    spelling += " ";
                }

                spelling += KeyCode[items[i]];
                pre = i;
            }

            return spelling;
        }
    }
}
