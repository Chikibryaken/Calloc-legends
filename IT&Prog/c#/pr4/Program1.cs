//Вариант 24
//Найти разность модулей сумм всех отрицательных и всех положительных элементов вещественного массива М(50).

using System;
using System.Runtime.InteropServices;

namespace task1
{
    internal class Program
    {
        [DllImport("C:/c#/pr4/arrlib/x64/Debug/arrlib.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr fillArray();
        [DllImport("C:/c#/pr4/arrlib/x64/Debug/arrlib.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void deleteArr(IntPtr arr);
        [DllImport("C:/c#/pr4/arrlib/x64/Debug/arrlib.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void outputArray(IntPtr arr);
        [DllImport("C:/c#/pr4/arrlib/x64/Debug/arrlib.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void sumAbs(IntPtr arr, int len);

        static void Main(string[] args)
        {
            string menu;

            IntPtr arr = IntPtr.Zero;

            do
            {
                Console.WriteLine("----------------------------------------------------------------");
                Console.WriteLine("|                             МЕНЮ                             |");
                Console.WriteLine("----------------------------------------------------------------");
                Console.WriteLine("| 1. Создать массив и заполнить 50 элементами                  |");
                Console.WriteLine("| 2. Вывести массив                                            |");
                Console.WriteLine("| 3. Разность модулей сумм всех отрицательных                  |");
                Console.WriteLine("|    и всех положительных элементов вещественного массива      |");
                Console.WriteLine("| 0. Выход                                                     |");
                Console.WriteLine("----------------------------------------------------------------");

                menu = Console.ReadLine();
                switch (menu)
                {
                    case "1":
                        arr = fillArray();
                        Console.WriteLine("Массив создан");
                        break;

                    case "2":
                        if (arr != IntPtr.Zero)
                        {
                            outputArray(arr);
                        }
                        else
                        {
                            Console.WriteLine("Массив ещё не создан");
                        }
                        break;

                    case "3":
                        if (arr != IntPtr.Zero)
                        {
                            sumAbs(arr, 50);
                        }
                        else
                        {
                            Console.WriteLine("Массив ещё не создан");
                        }
                        break;

                    case "0":
                        deleteArr(arr);
                        break;
                    default:
                        Console.WriteLine("Пункта меню не существует");
                        break;
                }
            } while (menu != "0");
        }
    }
}