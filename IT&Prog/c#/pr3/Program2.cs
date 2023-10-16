//     Вариант 24
//     Оставить в первом файле только слова, отсутствующие во втором, а во втором – отсутствующие в первом.
//     Оставить в файлах только десять самых часто встречающихся в
//     них слов

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace task2
{
    public class Lib
    {
        [DllImport("C:/c#/pr3/task2/file32.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr open(string path, bool read);
        [DllImport("C:/c#/pr3/task2/file32.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void close(IntPtr file);
        [DllImport("C:/c#/pr3/task2/file32.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool read(IntPtr file, int num, StringBuilder word);
        [DllImport("C:/c#/pr3/task2/file32.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void write(IntPtr file, string text);
        [DllImport("C:/c#/pr3/task2/file32.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int length(IntPtr file);

        private IntPtr file;
        private bool disposed = false;

        public Lib(string filePath, bool read)
        {
            try
            {
                file = open(filePath, read);

                if (file == IntPtr.Zero)
                {
                    throw new InvalidOperationException("Не удалось открыть файл");
                }
            }
            catch
            {
                throw;
            }
        }

        public string Read(int num)
        {
            if (disposed)
            {
                throw new ObjectDisposedException("Lib", "Файл закрыт");
            }

            try
            {
                StringBuilder word = new StringBuilder(256);
                bool result = read(file, num, word);

                if (!result)
                {
                    throw new InvalidOperationException("Не удалось прочитать файл");
                }

                return word.ToString();
            }
            catch
            {
                throw;
            }
        }

        public void Write(string text)
        {
            if (disposed)
            {
                throw new ObjectDisposedException("Lib", "Файл закрыт");
            }

            try
            {
                write(file, text);
            }
            catch
            {
                throw;
            }
        }

        public int Length()
        {
            if (disposed)
            {
                throw new ObjectDisposedException("Lib", "Файл закрыт");
            }

            try
            {
                return length(file);
            }
            catch
            {
                throw;
            }
        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected virtual void Dispose(bool disposing)
        {
            if (!disposed)
            {
                if (disposing)
                {
                    // Закрыть файл и освободить управляемые ресурсы (если таковые есть)
                    close(file);
                }

                // Освободить неуправляемые ресурсы (если таковые есть) и пометить объект как утилизированный
                disposed = true;
            }
        }

        ~Lib()
        {
            Dispose(false);
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            string filePath1 = "24.txt", filePath2 = "25.txt";
            Lib fileHandler1 = null, fileHandler2 = null;
            bool filesOpened = false;

            while (true)
            {
                Console.WriteLine("----------------------------------------------------------------------------");
                Console.WriteLine("|================================== МЕНЮ ==================================|");
                Console.WriteLine("| 1. Открыть файлы                                                         |");
                Console.WriteLine("| 2. Получить количество слов в файлах                                     |");
                Console.WriteLine("| 3. Оставить только уникальные слова в обоих файлах                       |");
                Console.WriteLine("| 4. Оставить в файлах только десять самых часто встречающихся слов        |");
                Console.WriteLine("| 5. Закрыть файлы                                                         |");
                Console.WriteLine("| 0. Выйти                                                                 |");
                Console.WriteLine("----------------------------------------------------------------------------");

                string choice = Console.ReadLine();

                switch (choice)
                {
                    case "1":
                        if (!filesOpened)
                        {
                            try
                            {
                                fileHandler1 = new Lib("C:/c#/pr3/task2/" + filePath1, true);
                                fileHandler2 = new Lib("C:/c#/pr3/task2/" + filePath2, true);
                                filesOpened = true;
                                Console.WriteLine($"Файлы '{filePath1}' и '{filePath2}' успешно открыты");
                            }
                            catch (Exception ex)
                            {
                                Console.WriteLine($"Ошибка при открытии файлов: {ex.Message}");
                            }
                        }
                        else
                        {
                            Console.WriteLine("Файлы уже открыты");
                        }
                        break;

                    case "2":
                        if (filesOpened)
                        {
                            int wordCount1 = fileHandler1.Length();
                            int wordCount2 = fileHandler2.Length();
                            Console.WriteLine($"Количество слов в файле '{filePath1}': {wordCount1}");
                            Console.WriteLine($"Количество слов в файле '{filePath2}': {wordCount2}");
                        }
                        else
                        {
                            Console.WriteLine("Файлы закрыты");
                        }
                        break;

                    case "3":
                        if (filesOpened)
                        {
                            uniqueWords(fileHandler1, fileHandler2, filePath1, filePath2);
                            Console.WriteLine("Уникальные слова оставлены в каждом файле");
                        }
                        else
                        {
                            Console.WriteLine("Файлы не открыты");
                        }
                        break;

                    case "4":
                        if (filesOpened)
                        {
                            commonWords(fileHandler1, filePath1);
                            commonWords(fileHandler2, filePath2);
                            Console.WriteLine("Оставлено десять самых часто встречающихся слов в каждом файле");
                            filesOpened = false;
                        }
                        else
                        {
                            Console.WriteLine("Файлы закрыты");
                        }
                        break;

                    case "5":
                        if (filesOpened)
                        {
                            fileHandler1.Dispose();
                            fileHandler2.Dispose();
                            filesOpened = false;
                            Console.WriteLine("Файлы успешно закрыты");
                        }
                        else
                        {
                            Console.WriteLine("Файлы закрыты");
                        }
                        break;

                    case "0":
                        if (filesOpened)
                        {
                            fileHandler1.Dispose();
                            fileHandler2.Dispose();
                        }
                        Console.WriteLine("Программа завершена");
                        return;

                    default:
                        Console.WriteLine("Пункта меню не существует");
                        break;
                }
            }
        }

        static void uniqueWords(Lib fileHandler1, Lib fileHandler2, string filepath1, string filepath2)
        {
            string content1 = "", content2 = "";
            for (int i = 1; i <= fileHandler1.Length() && i <= fileHandler2.Length(); i++)
            {
                content1 += fileHandler1.Read(i) + " ";
                content2 += fileHandler2.Read(i) + " ";
            }

            List<string> words1 = content1.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Distinct().ToList();
            List<string> words2 = content2.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();

            string result1 = "", result2 = "";

            foreach (string word in words1)
            {
                if (!words2.Contains(word))
                {
                    result1 += word + " ";
                }
            }

            foreach (string word in words2)
            {
                if (!words1.Contains(word))
                {
                    result2 += word + " ";
                }
            }
                
            fileHandler1.Dispose();
            fileHandler2.Dispose();
            fileHandler1 = new Lib("C:/c#/pr3/task2/" + filepath1, false);
            fileHandler2 = new Lib("C:/c#/pr3/task2/" + filepath2, false);
            fileHandler1.Write(result1.Trim());
            fileHandler2.Write(result2.Trim());
        }

        static void commonWords(Lib fileHandler, string filepath)
        {
            string content = "";
            for (int i = 1; i <= fileHandler.Length(); i++)
            {
                content += fileHandler.Read(i) + " ";
            }

            List<string> words = content.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
            Dictionary<string, int> wordCounts = new Dictionary<string, int>();

            foreach (string word in words)
            {
                if (wordCounts.ContainsKey(word))
                {
                    wordCounts[word]++;
                }
                else
                {
                    wordCounts[word] = 1;
                }
            }

            var topWords = wordCounts.OrderByDescending(pair => pair.Value).Take(10).Select(pair => pair.Key);

            string result = string.Join(" ", topWords);
            fileHandler.Dispose();
            fileHandler = new Lib("C:/c#/pr3/task2/" + filepath, false);
            fileHandler.Write(result);
        }
    }
}
