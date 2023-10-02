/*  Вариант 24. Цветы.
    Класс для первой части – роза.
    Варианты свойств: сорт, цвет, здоровье, цена.
    Варианты методов: вдохнуть аромат, полить, насладиться, узнать,
    как ухаживать (статический).
    Возможные классы иерархии: цветок(базовый), гладиолус, пион,
    ромашка.
    Возможный интерфейс: ISmell, дополнительный класс – духи.  */

using System;

namespace pr1
{
    abstract class flower
    {
        protected string name;
        protected string sort;
        protected string color;
        protected string shape;

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
        public flower() //по умолчанию
        {
            name = "";
            sort = "";
            color = "";
            shape = "";
        }
        public flower(string Name, string Sort, string Color, string Shape) //с параметрами
        {
            name = Name;
            sort = Sort;
            color = Color;
            shape = Shape;
        }
        public flower(flower f) //копирования
        {
            name = f.name;
            sort = f.sort;
            color = f.color;
            shape = f.shape;
        }

        //виртуальный метод
        public virtual string getClass()
        {
            return "Цветок";
        }

        //абстрактный метод
        public abstract string toString();

        //другие методы
        public void smell()
        {
            Console.WriteLine($"Цветок класса {this.getClass()} по имени {name} был понюхан");
        }
        public void water()
        {
            Console.WriteLine($"Цветок класса {this.getClass()} по имени {name} облился");
        }
        public void stroke()
        {
            Console.WriteLine($"Цветок класса {this.getClass()} по имени {name} стал выглаженым");
        }
    }

    class rose : flower
    {
        private int height;

        //свойство
        public int Height
        {
            set { height = value; }
            get { return height; }
        }

        //конструкторы
        public rose() : base() //по умолчанию
        {
            height = 0;
        }
        public rose(string Name, string Sort, string Color, string Shape, int H) : base(Name, Sort, Color, Shape) //с параметрами
        {
            height = H;
        }
        public rose(rose r) : base(r) //копирования
        {
            height = r.height;
        }


        //переопределенный вирутальный метод
        public override string getClass()
        {
            return "Роза";
        }

        //переопределенный абстрактный метод
        public override string toString()
        {
            return $"Имя: {name}\nСорт: {sort}\nЦвет: {color}\nФорма: {shape}\nВысота: {height} см";
        }

        //собственный метод
        public void injection()
        {
            Console.WriteLine("Эта роза решила приКОЛОТЬся :))");
        }
    }

    class tulip : flower
    {
        private int bugs;

        //свойство
        public int Bugs
        {
            set { bugs = value; }
            get { return bugs; }
        }

        //конструкторы
        public tulip() : base() //по умолчанию
        {
            bugs = 0;
        }
        public tulip(string Name, string Sort, string Color, string Shape, int Bugs) : base(Name, Sort, Color, Shape) //с параметрами
        {
            bugs = Bugs;
        }
        public tulip(tulip t) : base(t) //копирования
        {
            bugs = t.bugs;
        }

        //переопределенный вирутальный метод
        public override string getClass()
        {
            return "Тюльпан";
        }

        //переопределенный абстрактный метод
        public override string toString()
        {
            return $"Имя: {name}\nСорт: {sort}\nЦвет: {color}\nФорма: {shape}\nЖучков на цветке: {bugs}";
        }

        //собственный метод
        public void pollinate()
        {
            Console.WriteLine("Тюльпан помер от аллергии на пыль..");
        }
    }

    class chamomile : flower
    {
        private int petals;

        //свойство
        public int Petals
        {
            set { petals = value; }
            get { return petals; }
        }

        //конструкторы
        public chamomile() : base() //по умолчанию
        {
            petals = 0;
        }
        public chamomile(string Name, string Sort, string Color, string Shape, int Petals) : base(Name, Sort, Color, Shape) //с параметрами
        {
            petals = Petals;
        }
        public chamomile(chamomile c) : base(c) //копирования
        {
            petals = c.petals;
        }

        //переопределенный вирутальный метод 
        public override string getClass()
        {
            return "Ромашка";
        }

        //переопределенный абстрактный метод
        public override string toString()
        {
            return $"Имя: {name}\nСорт: {sort}\nЦвет: {color}\nФорма: {shape}\nЛепестков: {petals}";
        }

        //собственный метод
        public void sing_a_song()
        {
            Console.WriteLine("-----------------------------------------------------");
            Console.WriteLine("|                      Ромашки                      |");
            Console.WriteLine("-----------------------------------------------------");
            Console.WriteLine("|    И сотни роз не стоят ни одной твоей ромашки    |");
            Console.WriteLine("|               Ромашки летят в костёр              |");
            Console.WriteLine("|         Все ночи без тебя – они так тяжки         |");
            Console.WriteLine("|                  Мне тяжело одной                 |");
            Console.WriteLine("|         Нашу любовь не купишь за бумажки          |");
            Console.WriteLine("|            Она дороже всех твоих духов            |");
            Console.WriteLine("|     Ведь сотни роз не стоят и ромашки, ромашки    |");
            Console.WriteLine("|                                                   |");
            Console.WriteLine("|       Если любить, то сердцем, а не глазами       |");
            Console.WriteLine("|        Губы соврут, но душу ты не обманешь        |");
            Console.WriteLine("|  Не ранишь больно, но стреляешь словами, словами  |");
            Console.WriteLine("|                       О, да                       |");
            Console.WriteLine("|                   Это про меня                    |");
            Console.WriteLine("|           Ты не променял мой, мой океан           |");
            Console.WriteLine("|                      И о, да                      |");
            Console.WriteLine("|                   Ты не променял                  |");
            Console.WriteLine("|                                                   |");
            Console.WriteLine("|    И сотни роз не стоят ни одной твоей ромашки    |");
            Console.WriteLine("|               Ромашки летят в костёр              |");
            Console.WriteLine("|         Все ночи без тебя – они так тяжки         |");
            Console.WriteLine("|                  Мне тяжело одной                 |");
            Console.WriteLine("|         Нашу любовь не купишь за бумажки          |");
            Console.WriteLine("|            Она дороже всех твоих духов            |");
            Console.WriteLine("|     Ведь сотни роз не стоят и ромашки, ромашки    |");
            Console.WriteLine("|                                                   |");
            Console.WriteLine("|    И сотни роз не стоят ни одной твоей ромашки    |");
            Console.WriteLine("|               Ромашки летят в костёр              |");
            Console.WriteLine("|         Все ночи без тебя – они так тяжки         |");
            Console.WriteLine("|                  Мне тяжело одной                 |");
            Console.WriteLine("|         Нашу любовь не купишь за бумажки          |");
            Console.WriteLine("|            Она дороже всех твоих духов            |");
            Console.WriteLine("|     Ведь сотни роз не стоят и ромашки, ромашки    |");
            Console.WriteLine("-----------------------------------------------------");
        }
    }

    sealed class peonies : flower
    {
        private double price;

        //свойство
        public double Price
        {
            set { price = value; }
            get { return price; }
        }

        //конструкторы
        public peonies() : base() //по умолчанию
        {
            price = 0;
        }
        public peonies(string Name, string Sort, string Color, string Shape, double Price) : base(Name, Sort, Color, Shape) //с параметрами
        {
            price = Price;
        }
        public peonies(peonies p) : base(p) //копирования
        {
            price = p.price;
        }

        //переопределенный вирутальный метод
        public override string getClass()
        {
            return "Пион";
        }

        //переопределенный абстрактный метод
        public override string toString()
        {
            return $"Имя: {name}\nСорт: {sort}\nЦвет: {color}\nФорма: {shape}\nЦена: {price}";
        }

        //собственный метод
        public void gift()
        {
            Console.WriteLine("Эти пионы попали в хорошие руки!");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int menu, MENU, umen, UMEN;
            int cnt = 3, h = 0;
            double p = 0;
            string n, s, c, sh;
            bool integer = true;

            flower[] flowers = new flower[20];

            flowers[0] = new rose("Наташа", "Пиано Ред", "Желтый", "Плоская", 45);
            flowers[1] = new tulip("Ирка", "Принц Карнавал", "Красный", "Лилиецветная", 13);
            flowers[2] = new chamomile("Роза", "Персидская", "Розовый", "Крестовидно-розеточная", 17);
            flowers[3] = new peonies("Владлена", "Дюшес де Немур", "Розовый", "Помпонная", 500);

            do
            {
                Console.WriteLine("-----------------------------Меню-----------------------------");
                Console.WriteLine("| 1. Добавить цветок                                         |");
                Console.WriteLine("| 2. Посмотреть список цветочков                             |");
                Console.WriteLine("| 3. Ухаживать за цветами                                    |");
                Console.WriteLine("| 4. Совершить кое-какие действия над цветочками...          |");
                Console.WriteLine("| 0. Выход                                                   |");
                Console.WriteLine("--------------------------------------------------------------");

                if (int.TryParse(Console.ReadLine(), out menu))
                {
                    switch (menu)
                    {
                        case 1:
                            Console.Clear();

                            do
                            {
                                Console.WriteLine("----------------------------------");
                                Console.WriteLine("| Какой цветок добавить?         |");
                                Console.WriteLine("| 1. Роза                        |");
                                Console.WriteLine("| 2. Тюльпан                     |");
                                Console.WriteLine("| 3. Ромашка                     |");
                                Console.WriteLine("| 4. Пион                        |");
                                Console.WriteLine("| 0. Выход                       |");
                                Console.WriteLine("----------------------------------");

                                if (int.TryParse(Console.ReadLine(), out MENU))
                                {
                                    switch (MENU)
                                    {
                                        case 1:
                                            Console.Clear();

                                            Console.WriteLine("Введите имя для цветка: ");
                                            n = Console.ReadLine();
                                            Console.WriteLine("Введите сорт: ");
                                            s = Console.ReadLine();
                                            Console.WriteLine("Введите цвет: ");
                                            c = Console.ReadLine();
                                            Console.WriteLine("Введите форму: ");
                                            sh = Console.ReadLine();
                                            do
                                            {
                                                Console.WriteLine("Введите высоту в сантиметрах: ");
                                                if (int.TryParse(Console.ReadLine(), out int high) && high <= 80 && high >= 30)
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
                                            flowers[cnt] = new rose(n, s, c, sh, h);
                                            break;

                                        case 2:
                                            Console.Clear();

                                            Console.WriteLine("Введите имя для цветка: ");
                                            n = Console.ReadLine();
                                            Console.WriteLine("Введите сорт: ");
                                            s = Console.ReadLine();
                                            Console.WriteLine("Введите цвет: ");
                                            c = Console.ReadLine();
                                            Console.WriteLine("Введите форму: ");
                                            sh = Console.ReadLine();
                                            do
                                            {
                                                Console.WriteLine("Введите количество жучков на цветке: ");
                                                if (int.TryParse(Console.ReadLine(), out int bg) && bg <= 30 && bg >= 0)
                                                {
                                                    h = bg;
                                                    integer = true;
                                                }
                                                else
                                                {
                                                    integer = false;
                                                    Console.WriteLine("Введите целое значение от 0 до 30");
                                                }
                                            } while (integer == false);

                                            cnt++;
                                            flowers[cnt] = new tulip(n, s, c, sh, h);
                                            break;

                                        case 3:
                                            Console.Clear();

                                            Console.WriteLine("Введите имя для цветка: ");
                                            n = Console.ReadLine();
                                            Console.WriteLine("Введите сорт: ");
                                            s = Console.ReadLine();
                                            Console.WriteLine("Введите цвет: ");
                                            c = Console.ReadLine();
                                            Console.WriteLine("Введите форму: ");
                                            sh = Console.ReadLine();
                                            do
                                            {
                                                Console.WriteLine("Введите количество лепестков: ");
                                                if (int.TryParse(Console.ReadLine(), out int pl) && pl <= 20 && pl >= 5)
                                                {
                                                    h = pl;
                                                    integer = true;
                                                }
                                                else
                                                {
                                                    integer = false;
                                                    Console.WriteLine("Введите целое значение от 5 до 20");
                                                }
                                            } while (integer == false);

                                            cnt++;
                                            flowers[cnt] = new chamomile(n, s, c, sh, h);
                                            break;

                                        case 4:
                                            Console.Clear();

                                            Console.WriteLine("Введите имя для цветка: ");
                                            n = Console.ReadLine();
                                            Console.WriteLine("Введите сорт: ");
                                            s = Console.ReadLine();
                                            Console.WriteLine("Введите цвет: ");
                                            c = Console.ReadLine();
                                            Console.WriteLine("Введите форму: ");
                                            sh = Console.ReadLine();
                                            do
                                            {
                                                Console.WriteLine("Введите цену: ");
                                                if (double.TryParse(Console.ReadLine(), out double doub) && doub <= 700 && doub >= 100)
                                                {
                                                    p = doub;
                                                    integer = true;
                                                }
                                                else
                                                {
                                                    integer = false;
                                                    Console.WriteLine("Введите значение от 100 до 700");
                                                }
                                            } while (integer == false);

                                            cnt++;
                                            flowers[cnt] = new peonies(n, s, c, sh, p);
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

                        case 2:
                            Console.Clear();

                            Console.WriteLine("--------------------------------");
                            for (int i = 0; flowers[i] != null; i++)
                            {
                                Console.WriteLine(i + 1 + ". Класс: " + flowers[i].getClass() + "\n" + flowers[i].toString());
                                Console.WriteLine("--------------------------------");
                            }

                            break;

                        case 3:
                            Console.Clear();

                            do
                            {
                                Console.WriteLine("----------------------------------");
                                Console.WriteLine("| 1. Понюхать                    |");
                                Console.WriteLine("| 2. Полить                      |");
                                Console.WriteLine("| 3. Погладить                   |");
                                Console.WriteLine("| 0. Выход                       |");
                                Console.WriteLine("----------------------------------");

                                if (int.TryParse(Console.ReadLine(), out umen))
                                {
                                    switch (umen)
                                    {
                                        case 1:
                                            Console.Clear();

                                            for (int i = 0; flowers[i] != null; i++)
                                            {
                                                flowers[i].smell();
                                            }

                                            break;

                                        case 2:
                                            Console.Clear();

                                            for (int i = 0; flowers[i] != null; i++)
                                            {
                                                flowers[i].water();
                                            }

                                            break;

                                        case 3:
                                            Console.Clear();

                                            for (int i = 0; flowers[i] != null; i++)
                                            {
                                                flowers[i].stroke();
                                            }

                                            break;

                                        case 0:
                                            Console.Clear();
                                            break;
                                        default:
                                            Console.WriteLine("Пункта меню под данным номером не существует");
                                            break;
                                    }
                                }

                            } while (umen != 0);
                            break;

                        case 4:
                            Console.Clear();

                            do
                            {
                                Console.WriteLine("----------------------------------");
                                Console.WriteLine("| Какие цветы пощупать??         |");
                                Console.WriteLine("| 1. Потрогать розы              |");
                                Console.WriteLine("| 2. Опылить тюльпаны            |");
                                Console.WriteLine("| 3. Спеть про ромашки           |");
                                Console.WriteLine("| 4. Подарить пионы              |");
                                Console.WriteLine("| 0. Выход                       |");
                                Console.WriteLine("----------------------------------");

                                if (int.TryParse(Console.ReadLine(), out UMEN))
                                {
                                    switch (UMEN)
                                    {
                                        case 1:
                                            rose ros = new rose();
                                            ros.injection();
                                            break;

                                        case 2:
                                            tulip tulp = new tulip();
                                            tulp.pollinate();
                                            break;

                                        case 3:
                                            chamomile cham = new chamomile();
                                            cham.sing_a_song();
                                            break;

                                        case 4:
                                            peonies peon = new peonies();
                                            peon.gift();
                                            break;

                                        case 0:
                                            Console.Clear();
                                            break;

                                        default:
                                            Console.WriteLine("Пункта меню под данным номером не существует");
                                            break;
                                    }
                                }

                            } while (UMEN != 0);
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