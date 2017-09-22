using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab3 {
    public class CordanSharp {
        public bool[,] Sharp = new bool[8, 8];
        public char[,] Cipher = new char[8, 8];
        public String Text { get; set; }
        public int Length = 0;
        public bool Check = true;

        // Методы считают значения по позиции элемента в каждой четверти

        public int GetNumber0 (int size, int row, int col)    //Вычисление номера в первой четверти
        {
            return size*(row-1)+col;
        }
        public int GetNumber90 (int size, int row, int col)   //Вычисление номера во второй четверти
        {
            return size*(size-col)+row;
        }
        public int GetNumber180 (int size, int row, int col)  //Вычисление номера в третьей четверти
        {
            return size*(size-row)+size-col+1;
        }
        public int GetNumber270 (int size, int row, int col)  //Вычисление номера в четвёртой четверти
        {
            return size*(col-1)+size-row+1;
        }

        public void GetSharp ()       //Вычисляем решётку Кардано
        {
            Random rand = new Random();
            int Check = 0, i, j;
            int[] Holes = new int[16];
            while (Check!=16) {
                i=rand.Next(0, 7);
                j=rand.Next(0, 7);
                int k = 2*(i/4)+j/4;
                switch (k) {
                    case 0:
                        k=GetNumber0(4, i%4+1, j%4+1);
                        break;
                    case 1:
                        k=GetNumber90(4, i%4+1, j%4+1);
                        break;
                    case 2:
                        k=GetNumber270(4, i%4+1, j%4+1);
                        break;
                    case 3:
                        k=GetNumber180(4, i%4+1, j%4+1);
                        break;
                }
                if (Array.IndexOf(Holes, k)==-1) {
                    Holes[Check]=k;
                    Check++;
                    Sharp[i, j]=true;
                }
            }
        }

        public void PrintSharp ()         //Выводим решётку Кардано
        {
            for (int i = 0;i<Sharp.GetLength(0);i++) {
                for (int j = 0;j<Sharp.GetLength(1);j++) {
                    Console.Write(Convert.ToInt32(Sharp[i, j])+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }

        public void PrintCipher ()        //Выводим полный шифр
        {
            for (int i = 0;i<Cipher.GetLength(0);i++) {
                for (int j = 0;j<Cipher.GetLength(1);j++) {
                    Console.Write(Cipher[i, j]+" ");
                }
            }
            Console.WriteLine();
        }

        public void Rotate ()         //Поворот против часовой стрелки
        {
            bool[,] newMatrix = new bool[Sharp.GetLength(1), Sharp.GetLength(0)];
            int newColumn, newRow = 0;
            for (int oldColumn = Sharp.GetLength(1)-1;oldColumn>=0;oldColumn--) {
                newColumn=0;
                for (int oldRow = 0;oldRow<Sharp.GetLength(0);oldRow++) {
                    newMatrix[newRow, newColumn]=Sharp[oldRow, oldColumn];
                    newColumn++;
                }
                newRow++;
            }
            Sharp=newMatrix;
        }

        public void PrintCordanoSharp ()      //Выводим на экран каждый поворот шифрования
        {
            for (int i = 0;i<Sharp.GetLength(0);i++) {
                for (int j = 0;j<Sharp.GetLength(1);j++) {
                    if (Sharp[i, j]) {
                        Cipher[i, j]=Text[Length];
                        Length++;
                        if (Length==Text.Length) {
                            Check=false;
                            Length=0;
                        }
                        Console.Write(Cipher[i, j]+" ");
                        continue;
                    }
                    Console.Write("  ");
                }
                Console.WriteLine();
            }
            Rotate();
        }

        public void GetCipher ()          //Шифруем сообщение
        {
            Console.WriteLine("\nПосле наложения решётки:\n");
            PrintCordanoSharp();
            Console.WriteLine("\nПоворот на 90 градусов направо:\n");
            PrintCordanoSharp();
            Console.WriteLine("\nПоворот на 180 градусов направо:\n");
            PrintCordanoSharp();
            Console.WriteLine("\nПоворот на 270 градусов направо:\n");
            PrintCordanoSharp();
            Console.WriteLine("\nПолученный шифр:\n");
            PrintCipher();
        }
    }
}
