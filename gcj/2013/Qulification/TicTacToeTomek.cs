using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace GCJ.qulification2013
{
    public class TicTacToeTomek
    {
        public TicTacToeTomek()
        {
            int i = 0;
            int j = 0;
            int T = 0;

            char[][] board = new char[4][];

            StreamReader sRead = new StreamReader(new FileStream(@"E:\Practice\GCJ\file\A-large.in", FileMode.Open));
            StreamWriter sWrite = new StreamWriter(new FileStream(@"E:\Practice\GCJ\file\A-large.out", FileMode.OpenOrCreate));
            T = Convert.ToInt32(sRead.ReadLine());

            for (i = 0; i < T; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    board[j] = sRead.ReadLine().ToCharArray();
                }
                string tmp = sRead.ReadLine();
                tmp = judgeResult(board);
                sWrite.WriteLine("Case #{0}: {1}", i + 1, tmp);
            }

            sRead.Close();
            sWrite.Close();

        }

        private void cope1(char c, ref int[] rec)
        {
            switch (c)
            {
                case '.': rec[0]++; break;
                case 'T': rec[1]++; break;
                case 'X': rec[2]++; break;
                case 'O': rec[3]++; break;
                default: break;
            }
        }
        /*
         * 0 draw
         * 1 X won
         * 2 O won
         * . T X O
         */
        private int cope2(int[] rec)
        {
            int ret = 0;
            if (rec[1] + rec[2] == 4) { ret = 1; }
            if (rec[1] + rec[3] == 4) { ret = 2; }
            return ret;
        }

        private string judgeResult(char[][] board)
        {
            int i = 0;
            int j = 0;
            int t1 = 0;
            int t2 = 0;
            int full = 1; // whether the board is full, 1 true, 0 false
            int[] rec1 = null;
            int[] rec2 = null;
            string ret = "Draw";

            for (i = 0; i < 4; i++)
            {
                rec1 = new int[4];// . T X O
                rec2 = new int[4];
                for (j = 0; j < 4; j++)
                {
                    cope1(board[i][j], ref rec1);
                    cope1(board[j][i], ref rec2);
                }
                if (rec1[0] + rec2[0] > 0) { full = 0; }
                t1 = cope2(rec1);
                t2 = cope2(rec2);
                if (t1 > 0) { ret = t1 == 1 ? "X won" : "O won"; }
                if (t2 > 0) { ret = t2 == 1 ? "X won" : "O won"; }
                if (t1 + t2 > 0) { break; }
            }

            // diagonal 
            if (ret == "Draw")
            {
                rec1 = new int[4];// . T X O
                rec2 = new int[4];
                for (i = 0; i < 4; i++)
                {
                    cope1(board[i][i], ref rec1);
                    cope1(board[i][3 - i], ref rec2);
                }
                if (rec1[0] + rec2[0] > 0) { full = 0; }
                t1 = cope2(rec1);
                t2 = cope2(rec2);
                if (t1 > 0) { ret = t1 == 1 ? "X won" : "O won"; }
                if (t2 > 0) { ret = t2 == 1 ? "X won" : "O won"; }
            }

            if (ret == "Draw" && full == 0) { ret = "Game has not completed"; }

            return ret;
        }
    }
}
