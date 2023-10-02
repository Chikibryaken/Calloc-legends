/*  Вариант 24. Цветы.
    Класс для первой части – роза.
    Варианты свойств: сорт, цвет, здоровье, цена.
    Варианты методов: вдохнуть аромат, полить, насладиться, узнать,
    как ухаживать (статический).
    Возможные классы иерархии: цветок(базовый), гладиолус, пион,
    ромашка.
    Возможный интерфейс: ISmell, дополнительный класс – духи. */

using System;

namespace pr1
{
    class Rose
    {
        //элементы разного доступа
        private string name;
        private string sort;
        private string color;
        private string shape;
        public int height;

        //константное поле
        public const string baseColor = "Красный";

        //свойства
        public string Name
        {
            set { name = value; }
            get { return name; }
        }
        public string Sort
        {
            set { sort = value; }
            get { return sort; }
        }
        public string Color
        {
            set { color = value; }
            get { return color; }
        }
        public string Shape
        {
            set { shape = value; }
            get { return shape; }
        }

        //конструкторы
        public Rose() //по умолчанию
        {
            name = "Ирина";
            sort = "Мисс Пигги";
            color = baseColor;
            shape = "Розетковидная";
            height = 50;
        }
        public Rose(string Name, string Sort, string Color, string Shape, int Height) //с параметрами
        {
            name = Name;
            sort = Sort;
            color = Color;
            shape = Shape;
            height = Height;
        }
        public Rose(Rose r) //копирования
        {
            name = r.name;
            sort = r.sort;
            color = r.color;
            shape = r.shape;
            height = r.height;
        }

        //методы
        public void smellThat()
        {
            Console.WriteLine($"Вы вдыхаете аромат розы {name}. Сорт - {sort}");
            Console.WriteLine("*пахнет, как дух юности...*");
        }
        public void water()
        {
            Console.WriteLine($"Роза {name} полита.");
            Console.WriteLine("*это наполняет Вас решимостью*");
        }
        public void stroke()
        {
            Console.WriteLine($"Вы погладили розу {name}.");
            Console.WriteLine("В ответ она уколола Вас.");
        }

        //статический метод
        public static void wiki()
        {
            Console.WriteLine("-----------ИНСТРУКЦИЯ-----------");
            Console.WriteLine("|    Как ухаживать за розой    |");
            Console.WriteLine("--------------------------------");
            Console.WriteLine("| 1. Сначала розу нужно полить |");
            Console.WriteLine("| 2. Затем погладить           |");
            Console.WriteLine("| 3. В конце ее нужно понюхать |");
            Console.WriteLine("| 4. Вуаля! Она довольна :)    |");
            Console.WriteLine("--------------------------------");
        }

        //перегрузка ToString
        public override string ToString()
        {
            return $"Имя: {name}\nСорт: {sort}\nЦвет: {color}\nФорма: {shape}\nВысота: {height} см";
        }

        //перегрузка операторов сравнения
        public static bool operator >(Rose r1, Rose r2)
        {
            if (r1.height > r2.height)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        public static bool operator <(Rose r1, Rose r2)
        {
            if (r1.height < r2.height)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        //перегрузка оператора сложения
        public static Rose operator +(Rose left, Rose right)
        {
            Rose result = new Rose();
            result.name = left.name + " & " + right.name;
            result.sort = left.sort + " & " + right.sort;
            result.color = left.color + " & " + right.color;
            result.shape = left.shape + " & " + right.shape;
            result.height = left.height + right.height;

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int menu, MENU;
            int cnt = 3, h = 0, high, num;
            string n, sr, c, sh;
            bool integer = true;

            Rose[] arrRose = new Rose[20];

            arrRose[0] = new Rose("Наталья", "Пиано Ред", "Желтый", "Плоская", 43);
            arrRose[1] = new Rose("Владлена", "Ламбада", "Розовый", "Кувшинчатая", 30);
            arrRose[2] = new Rose("Лидия", "Лидия", "Оранжевый", "Помпонная", 70);
            arrRose[3] = new Rose("Анатолий", "Пимпинеллифолия", "Небесный", "Крестовидно-розеточная", 80);

            do
            {
                Console.WriteLine("-----------------------------Меню-----------------------------");
                Console.WriteLine("| 1. Добавить розу                                           |");
                Console.WriteLine("| 2. Оглядеться и посмотреть какие розы есть вокруг          |");
                Console.WriteLine("| 3. Инструкция как сохранить розе отличное настроение       |");
                Console.WriteLine("| 4. Сделать розе приятно                                    |");
                Console.WriteLine("| 0. Сбежать от роз                                          |");
                Console.WriteLine("--------------------------------------------------------------");

                if (int.TryParse(Console.ReadLine(), out menu))
                {
                    switch (menu)
                    {
                        case 1:
                            Console.Clear();

                            Console.WriteLine("Введите имя вашего цветочка: ");
                            n = Console.ReadLine();
                            Console.WriteLine("Введите сорт: ");
                            sr = Console.ReadLine();
                            Console.WriteLine("Введите цвет: ");
                            c = Console.ReadLine();
                            Console.WriteLine("Введите форму: ");
                            sh = Console.ReadLine();

                            do
                            {
                                Console.WriteLine("Введите высоту: ");
                                if (int.TryParse(Console.ReadLine(), out high) && high <= 80 && high >= 30)
                                {
                                    h = high;
                                    integer = true;
                                }
                                else
                                {
                                    integer = false;
                                    Console.WriteLine("Введите целое значение от 30 до 80 в сантиметрах");
                                }
                            } while (integer == false);

                            cnt++;
                            arrRose[cnt] = new Rose(n, sr, c, sh, h);
                            break;

                        case 2:
                            Console.Clear();

                            Console.WriteLine("--------------------------------");
                            for (int i = 0; arrRose[i] != null; i++)
                            {
                                Console.WriteLine(i + 1 + ". " + arrRose[i].ToString());
                                Console.WriteLine("--------------------------------");
                            }
                            break;

                        case 3:
                            Console.Clear();
                            Rose.wiki();
                            break;

                        case 4:
                            Console.Clear();

                            do
                            {
                                Console.WriteLine("--------------------------");
                                Console.WriteLine("| 1. Полить розу         |");
                                Console.WriteLine("| 2. Понюхать розу       |");
                                Console.WriteLine("| 3. Погладить розу      |");
                                Console.WriteLine("| 0. Вернуться           |");
                                Console.WriteLine("--------------------------");

                                if (int.TryParse(Console.ReadLine(), out MENU))
                                {
                                    switch (MENU)
                                    {
                                        case 1:
                                            Console.Clear();

                                            Console.WriteLine("--------------------------------");
                                            for (int i = 0; arrRose[i] != null; i++)
                                            {
                                                Console.WriteLine(i + 1 + ". " + arrRose[i].ToString());
                                                Console.WriteLine("--------------------------------");
                                            }

                                            do
                                            {
                                                Console.WriteLine("Введите номер розы, котороую нужно полить: ");
                                                if (int.TryParse(Console.ReadLine(), out num) && num <= cnt + 1 && num > 0)
                                                {
                                                    int i = num;
                                                    arrRose[i - 1].water();
                                                    integer = true;
                                                }
                                                else
                                                {
                                                    integer = false;
                                                    Console.WriteLine("Цветка под данным номером нет");
                                                }
                                            } while (integer == false);

                                            break;

                                        case 2:
                                            Console.Clear();

                                            Console.WriteLine("--------------------------------");
                                            for (int i = 0; arrRose[i] != null; i++)
                                            {
                                                Console.WriteLine(i + 1 + ". " + arrRose[i].ToString());
                                                Console.WriteLine("--------------------------------");
                                            }

                                            do
                                            {
                                                Console.WriteLine("Введите номер розы, котороую нужно нюхнуть: ");
                                                if (int.TryParse(Console.ReadLine(), out num) && num <= cnt + 1 && num > 0)
                                                {
                                                    int i = num;
                                                    arrRose[i - 1].smellThat();
                                                    integer = true;
                                                }
                                                else
                                                {
                                                    integer = false;
                                                    Console.WriteLine("Цветка под данным номером нет");
                                                }
                                            } while (integer == false);

                                            break;

                                        case 3:
                                            Console.Clear();

                                            Console.WriteLine("--------------------------------");
                                            for (int i = 0; arrRose[i] != null; i++)
                                            {
                                                Console.WriteLine(i + 1 + ". " + arrRose[i].ToString());
                                                Console.WriteLine("--------------------------------");
                                            }

                                            do
                                            {
                                                Console.WriteLine("Введите номер розы, котороую нужно погладить: ");
                                                if (int.TryParse(Console.ReadLine(), out num) && num <= cnt + 1 && num > 0)
                                                {
                                                    int i = num;
                                                    arrRose[i - 1].stroke();
                                                    integer = true;
                                                }
                                                else
                                                {
                                                    integer = false;
                                                    Console.WriteLine("Цветка под данным номером нет");
                                                }
                                            } while (integer == false);

                                            break;

                                        case 0:
                                            Console.Clear();
                                            break;
                                        default:
                                            Console.WriteLine("Пункта меню под данным номером не существует");
                                            break;
                                    }
                                }
                            } while (MENU != 0);
                            break;

                        case 0:
                            Console.Clear();
                            break;
                        default:
                            Console.WriteLine("Пункта меню под данным номером не существует");
                            break;
                    }
                }
            } while (menu != 0);
        }
    }
}