using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab3 {
    class Program {
        static void Main (string[] args) {
            CordanSharp newSharp = new CordanSharp();
            Console.Write("Введите сообщение: ");
            newSharp.Text=Console.ReadLine();

            newSharp.GetSharp();
            Console.WriteLine("\nПолученная решётка:\n");
            newSharp.PrintSharp();

            int n = 1;
            while (newSharp.Check) {
                Console.WriteLine("\nРешётка №{0}:\n", n);
                n++;
                newSharp.GetCipher();
            }

            Console.WriteLine("Для продолжения нажмите на любую кнопку...");
            Console.ReadKey();
        }
    }
}
