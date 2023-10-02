/*  Вариант 24. Цветы.
    Класс для первой части – роза.
    Варианты свойств: сорт, цвет, здоровье, цена.
    Варианты методов: вдохнуть аромат, полить, насладиться, узнать,
    как ухаживать (статический).
    Возможные классы иерархии: цветок(базовый), гладиолус, пион,
    ромашка.
    Возможный интерфейс: ISmell, дополнительный класс – духи.  */

using System;
using System.Collections.Generic;

namespace pr1
{
    interface ISmell
    {
        string smell();
        string toString();
        string getClass();
    }

    class perfume : ISmell
    {
        private string name;
        private string flower;
        private double price;
        private double time;

        //свойства
        public string Name
        {
            set { name = value; }
            get { return name; }
        }
        public string Flower
        {
            set { flower = value; }
            get { return flower; }
        }
        public double Price
        {
            set { price = value; }
            get { return price; }
        }
        public double Time
        {
            set { time = value; }
            get { return time; }
        }

        //конструкторы
        public perfume() //по умолчанию
        {
            name = "";
            flower = "";
            price = 0;
            time = 0;
        }
        public perfume(string Name, string Flower, double Price, double Time) //с параметрами
        {
            name = Name;
            flower = Flower;
            price = Price;
            time = Time;
        }
        public perfume(perfume p)
        {
            name = p.name;
            flower = p.flower;
            price = p.price;
            time = p.time;
        }

        //методы интерфейса
        public string smell()
        {
            return $"Вы вдохнули аромат одеколона {name} и почувствовали привкус Советского Союза";
        }
        public string getClass()
        {
            return "Парфюм";
        }
        public string toString()
        {
            return $"Класс: {this.getClass()}\nИмя: {name}\nСделан из этих цветов: {flower}\nЦена: {price}\nДлится часов: {time}";
        }

        //собственный метод
        public void spray()
        {
            Console.WriteLine($"Теперь Вы пахнете парфюмом {name}");
        }
    }

    abstract class flower : ISmell
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
            set { color = value; }
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

        public abstract string getClass();

        //методы интерфейса
        public string smell()
        {
           return $"Цветок {this.getClass()} по имени {name} был понюхан";
        }
        public virtual string toString()
        {
            return $"Класс: {this.getClass()}\nИмя: {name}\nСорт: {sort}\nЦвет: {color}";
        }

        //другие методы
        public void water()
        {
            Console.WriteLine($"Цветок {this.getClass()} по имени {name} облился");
        }
        public void stroke()
        {
            Console.WriteLine($"Цветок {this.getClass()} по имени {name} стал выглаженым");
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

        //конструктор по умолчанию
        public rose() : base()
        {
            height = 0;
        }

        //конструктор с параметрами
        public rose(string Name, string Sort, string Color, string Shape, int H) : base(Name, Sort, Color, Shape)
        {
            height = H;
        }
        public rose(rose r) : base(r) //копирования
        {
            height = r.height;
        }

        //переопределенные методы интерфейса
        public override string getClass()
        {
            return "Роза";
        }
        public override string toString()
        {
            return $"Класс: {this.getClass()}\nИмя: {name}\nСорт: {sort}\nЦвет: {color}\nФорма: {shape}\nВысота: {height}";
        }
        public new string smell()
        {
            return $"Цветок {this.getClass()} по имени {name} был понюхан";
        }

        //собственный метод
        public void injection()
        {
            Console.WriteLine($"Эта роза ({name}) решила приКОЛОТЬся :))");
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

        //переопределенные методы интерфейса
        public override string getClass()
        {
            return "Тюльпан";
        }
        public override string toString()
        {
            return $"Класс: {this.getClass()}\nИмя: {name}\nСорт: {sort}\nЦвет: {color}\nЖучков на цветке: {bugs}";
        }

        //собственный метод
        public void pollinate()
        {
            Console.WriteLine($"Тюльпан ({name}) помер от аллергии на пыль..");
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
        public chamomile(chamomile c) : base(c)
        {
            petals = c.petals;
        }

        //переопределенные методы интерфейса
        public override string getClass()
        {
            return "Ромашка";
        }
        public override string toString()
        {
            return $"Класс: {this.getClass()} \nИмя: {name}\nСорт: {sort}\nЦвет: {color}\nФорма: {shape}\nЛепестков: {petals}";
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
        public peonies(peonies p) : base(p)
        {
            price = p.price;
        }

        //переопределенный метод интерфейса
        public override string getClass()
        {
            return "Пион";
        }
        public override string toString()
        {
            return $"Класс: {this.getClass()} \nИмя: {name}\nСорт: {sort}\nЦвет: {color}\nФорма: {shape}\nЦена: {price}";
        }

        //собственный метод
        public void gift()
        {
            Console.WriteLine($"Этот пион ({name}) попал в хорошие руки!");
        }
    }

    class Program
    {
        static void SmellObject(ISmell obj)
        {
            Console.WriteLine(obj.smell());
        }
        static void Main(string[] args)
        {
            int menu, MENU, umen, UMEN;
            int h = 0;
            double p = 0, t = 0;
            string n, s, c, sh;
            bool integer = true, need = false;

            List<ISmell> list = new List<ISmell>();

            rose Rose = new rose("Наташа", "Пиано Ред", "Желтый", "Плоская", 45);
            list.Add(Rose);
            tulip Tulip = new tulip("Ирка", "Принц Карнавал", "Красный", "Лилиецветная", 13);
            list.Add(Tulip);
            chamomile Cham = new chamomile("Роза", "Персидская", "Розовый", "Крестовидно-розеточная", 17);
            list.Add(Cham);
            peonies Peon = new peonies("Владлена", "Дюшес де Немур", "Розовый", "Помпонная", 500);
            list.Add(Peon);
            perfume Perf = new perfume("'Павел'", "Крапива", 150, 8);
            list.Add(Perf);

            do
            {
                Console.WriteLine("-----------------------------Меню-----------------------------");
                Console.WriteLine("| 1. Добавить объект в список                                |");
                Console.WriteLine("| 2. Посмотреть список объектов                              |");
                Console.WriteLine("| 3. Выполнение методов объектов                             |");
                Console.WriteLine("| 4. Выполнение функции                                      |");
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
                                Console.WriteLine("| 1. Роза                        |");
                                Console.WriteLine("| 2. Тюльпан                     |");
                                Console.WriteLine("| 3. Ромашка                     |");
                                Console.WriteLine("| 4. Пион                        |");
                                Console.WriteLine("| 5. Духи                        |");
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
                                                if (int.TryParse(Console.ReadLine(), out int integ) && integ <= 80 && integ >= 30)
                                                {
                                                    h = integ;
                                                    integer = true;
                                                }
                                                else
                                                {
                                                    integer = false;
                                                    Console.WriteLine("Введите целое значение от 30 до 80 в сантиметрах");
                                                }
                                            } while (integer == false);
                                            list.Add(new rose(n, s, c, sh, h));
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
                                                if (int.TryParse(Console.ReadLine(), out int integ) && integ <= 30 && integ >= 0)
                                                {
                                                    h = integ;
                                                    integer = true;
                                                }
                                                else
                                                {
                                                    integer = false;
                                                    Console.WriteLine("Введите целое значение от 0 до 30");
                                                }
                                            } while (integer == false);
                                            list.Add(new tulip(n, s, c, sh, h));
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
                                                if (int.TryParse(Console.ReadLine(), out int integ) && integ <= 20 && integ >= 5)
                                                {
                                                    h = integ;
                                                    integer = true;
                                                }
                                                else
                                                {
                                                    integer = false;
                                                    Console.WriteLine("Введите целое значение от 5 до 20");
                                                }
                                            } while (integer == false);
                                            list.Add(new chamomile(n, s, c, sh, h));
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
                                            list.Add(new peonies(n, s, c, sh, p));
                                            break;

                                        case 5:
                                            Console.Clear();

                                            Console.WriteLine("Введите название для парфюма: ");
                                            n = Console.ReadLine();
                                            Console.WriteLine("Введите цветок: ");
                                            s = Console.ReadLine();
                                            do
                                            {
                                                Console.WriteLine("Введите цену: ");
                                                if (double.TryParse(Console.ReadLine(), out double doub) && doub <= 1500 && doub >= 100)
                                                {
                                                    p = doub;
                                                    integer = true;
                                                }
                                                else
                                                {
                                                    integer = false;
                                                    Console.WriteLine("Введите значение от 100 до 1500");
                                                }
                                            } while (integer == false);
                                            do
                                            {
                                                Console.WriteLine("Введите время: ");
                                                if (double.TryParse(Console.ReadLine(), out double doub) && doub <= 12 && doub >= 1)
                                                {
                                                    p = doub;
                                                    integer = true;
                                                }
                                                else
                                                {
                                                    integer = false;
                                                    Console.WriteLine("Введите значение от 1 до 12");
                                                }
                                            } while (integer == false);
                                            list.Add(new perfume(n, s, p, t));
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
                            for (int i = 0; i < list.Count; i++)
                            {
                                Console.WriteLine(i + 1 + ". " + list[i].toString());
                                Console.WriteLine("--------------------------------");
                            }

                            break;

                        case 3:
                            Console.Clear();

                            do
                            {
                                Console.WriteLine("----------------------------------");
                                Console.WriteLine("| Выберите действие              |");
                                Console.WriteLine("| 1. Потрогать розы              |");
                                Console.WriteLine("| 2. Опылить тюльпаны            |");
                                Console.WriteLine("| 3. Спеть про ромашки           |");
                                Console.WriteLine("| 4. Подарить пионы              |");
                                Console.WriteLine("| 5. Пшикнуть парфюм             |");
                                Console.WriteLine("| 0. Выход                       |");
                                Console.WriteLine("----------------------------------");

                                if (int.TryParse(Console.ReadLine(), out UMEN))
                                {
                                    switch (UMEN)
                                    {
                                        case 1:
                                            for (int i = 0; i < list.Count; i++)
                                            {
                                                if (list[i] is rose)
                                                {
                                                    Console.WriteLine(i + 1 + ". " + list[i].toString() + "\nКласс: " + list[i].getClass());
                                                    Console.WriteLine("-------------------------------------");
                                                }
                                            }
                                            Console.WriteLine("Введите номер с которым хотите взаимодействовать: ");
                                            do
                                            {
                                                if (int.TryParse(Console.ReadLine(), out int sc) && sc >= 1 && sc <= list.Count + 1)
                                                {
                                                    int j = sc;

                                                    if (list[j - 1] is rose)
                                                    {
                                                        rose ROSE = (rose)list[j - 1];
                                                        ROSE.injection();
                                                        need = true;
                                                    }
                                                    else
                                                    {
                                                        Console.WriteLine("Такого варианта нет");
                                                        need = false;
                                                    }
                                                }
                                                else
                                                {
                                                    Console.WriteLine("Такого варианта нет");
                                                    need = false;
                                                }
                                            } while (need == false);
                                            break;
                                        case 2:
                                            for (int i = 0; i < list.Count; i++)
                                            {
                                                if (list[i] is tulip)
                                                {
                                                    Console.WriteLine(i + 1 + ". " + list[i].toString() + "\nКласс: " + list[i].getClass());
                                                    Console.WriteLine("-------------------------------------");
                                                }
                                            }
                                            Console.WriteLine("Введите номер с которым хотите взаимодействовать: ");
                                            do
                                            {
                                                if (int.TryParse(Console.ReadLine(), out int sc) && sc >= 1 && sc <= list.Count + 1)
                                                {
                                                    int j = sc;

                                                    if (list[j - 1] is tulip)
                                                    {
                                                        tulip TULIP = (tulip)list[j - 1];
                                                        TULIP.pollinate();
                                                        need = true;
                                                    }
                                                    else
                                                    {
                                                        Console.WriteLine("Такого варианта нет");
                                                        need = false;
                                                    }
                                                }
                                                else
                                                {
                                                    Console.WriteLine("Такого варианта нет");
                                                    need = false;
                                                }
                                            } while (need == false);
                                            break;
                                        case 3:
                                            for (int i = 0; i < list.Count; i++)
                                            {
                                                if (list[i] is chamomile)
                                                {
                                                    Console.WriteLine(i + 1 + ". " + list[i].toString() + "\nКласс: " + list[i].getClass());
                                                    Console.WriteLine("-------------------------------------");
                                                }
                                            }
                                            Console.WriteLine("Введите номер с которым хотите взаимодействовать: ");
                                            do
                                            {
                                                if (int.TryParse(Console.ReadLine(), out int sc) && sc >= 1 && sc <= list.Count + 1)
                                                {
                                                    int j = sc;

                                                    if (list[j - 1] is chamomile)
                                                    {
                                                        chamomile CHAM = (chamomile)list[j - 1];
                                                        CHAM.sing_a_song();
                                                        need = true;
                                                    }
                                                    else
                                                    {
                                                        Console.WriteLine("Такого варианта нет");
                                                        need = false;
                                                    }
                                                }
                                                else
                                                {
                                                    Console.WriteLine("Такого варианта нет");
                                                    need = false;
                                                }
                                            } while (need == false);
                                            break;
                                        case 4:
                                            for (int i = 0; i < list.Count; i++)
                                            {
                                                if (list[i] is peonies)
                                                {
                                                    Console.WriteLine(i + 1 + ". " + list[i].toString() + "\nКласс: " + list[i].getClass());
                                                    Console.WriteLine("-------------------------------------");
                                                }
                                            }
                                            Console.WriteLine("Введите номер с которым хотите взаимодействовать: ");
                                            do
                                            {
                                                if (int.TryParse(Console.ReadLine(), out int sc) && sc >= 1 && sc <= list.Count + 1)
                                                {
                                                    int j = sc;

                                                    if (list[j - 1] is peonies)
                                                    {
                                                        peonies CHAM = (peonies)list[j - 1];
                                                        CHAM.gift();
                                                        need = true;
                                                    }
                                                    else
                                                    {
                                                        Console.WriteLine("Такого варианта нет");
                                                        need = false;
                                                    }
                                                }
                                                else
                                                {
                                                    Console.WriteLine("Такого варианта нет");
                                                    need = false;
                                                }
                                            } while (need == false);
                                            break;
                                        case 5:
                                            for (int i = 0; i < list.Count; i++)
                                            {
                                                if (list[i] is perfume)
                                                {
                                                    Console.WriteLine(i + 1 + ". " + list[i].toString() + "\nКласс: " + list[i].getClass());
                                                    Console.WriteLine("-------------------------------------");
                                                }
                                            }
                                            Console.WriteLine("Введите номер с которым хотите взаимодействовать: ");
                                            do
                                            {
                                                if (int.TryParse(Console.ReadLine(), out int sc) && sc >= 1 && sc <= list.Count + 1)
                                                {
                                                    int j = sc;

                                                    if (list[j - 1] is perfume)
                                                    {
                                                        perfume PERF = (perfume)list[j - 1];
                                                        PERF.spray();
                                                        need = true;
                                                    }
                                                    else
                                                    {
                                                        Console.WriteLine("Такого варианта нет");
                                                        need = false;
                                                    }
                                                }
                                                else
                                                {
                                                    Console.WriteLine("Такого варианта нет");
                                                    need = false;
                                                }
                                            } while (need == false);
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

                        case 4:
                            Console.Clear();

                            do
                            {
                                Console.WriteLine("----------------------------------");
                                Console.WriteLine("| Выберите чего понюхать         |");
                                Console.WriteLine("| 1. Розы                        |");
                                Console.WriteLine("| 2. Тюльпаны                    |");
                                Console.WriteLine("| 3. Ромашки                     |");
                                Console.WriteLine("| 4. Пионы                       |");
                                Console.WriteLine("| 5. Парфюм                      |");
                                Console.WriteLine("| 0. Выход                       |");
                                Console.WriteLine("----------------------------------");

                                if (int.TryParse(Console.ReadLine(), out umen))
                                {
                                    switch (umen)
                                    {
                                        case 1:
                                            for (int i = 0; i < list.Count; i++)
                                            {
                                                if (list[i] is rose)
                                                {
                                                    Console.WriteLine(i + 1 + ". " + list[i].toString() + "\nКласс: " + list[i].getClass());
                                                    Console.WriteLine("-------------------------------------");
                                                }
                                            }
                                            Console.WriteLine("Введите номер с которым хотите взаимодействовать: ");
                                            do
                                            {
                                                if (int.TryParse(Console.ReadLine(), out int sc) && sc >= 1 && sc <= list.Count + 1)
                                                {
                                                    int j = sc;

                                                    if (list[j - 1] is rose)
                                                    {
                                                        SmellObject(list[j - 1]);
                                                        need = true;
                                                    }
                                                    else
                                                    {
                                                        Console.WriteLine("Такого варианта нет");
                                                        need = false;
                                                    }
                                                }
                                                else
                                                {
                                                    Console.WriteLine("Такого варианта нет");
                                                    need = false;
                                                }
                                            } while (need == false);
                                            break;

                                        case 2:
                                            for (int i = 0; i < list.Count; i++)
                                            {
                                                if (list[i] is tulip)
                                                {
                                                    Console.WriteLine(i + 1 + ". " + list[i].toString() + "\nКласс: " + list[i].getClass());
                                                    Console.WriteLine("-------------------------------------");
                                                }
                                            }
                                            Console.WriteLine("Введите номер с которым хотите взаимодействовать: ");
                                            do
                                            {
                                                if (int.TryParse(Console.ReadLine(), out int sc) && sc >= 1 && sc <= list.Count + 1)
                                                {
                                                    int j = sc;

                                                    if (list[j - 1] is tulip)
                                                    {
                                                        SmellObject(list[j - 1]);
                                                        need = true;
                                                    }
                                                    else
                                                    {
                                                        Console.WriteLine("Такого варианта нет");
                                                        need = false;
                                                    }
                                                }
                                                else
                                                {
                                                    Console.WriteLine("Такого варианта нет");
                                                    need = false;
                                                }
                                            } while (need == false);
                                            break;

                                        case 3:
                                            for (int i = 0; i < list.Count; i++)
                                            {
                                                if (list[i] is chamomile)
                                                {
                                                    Console.WriteLine(i + 1 + ". " + list[i].toString() + "\nКласс: " + list[i].getClass());
                                                    Console.WriteLine("-------------------------------------");
                                                }
                                            }
                                            Console.WriteLine("Введите номер с которым хотите взаимодействовать: ");
                                            do
                                            {
                                                if (int.TryParse(Console.ReadLine(), out int sc) && sc >= 1 && sc <= list.Count + 1)
                                                {
                                                    int j = sc;

                                                    if (list[j - 1] is chamomile)
                                                    {
                                                        SmellObject(list[j - 1]);
                                                        need = true;
                                                    }
                                                    else
                                                    {
                                                        Console.WriteLine("Такого варианта нет");
                                                        need = false;
                                                    }
                                                }
                                                else
                                                {
                                                    Console.WriteLine("Такого варианта нет");
                                                    need = false;
                                                }
                                            } while (need == false);
                                            break;

                                        case 4:
                                            for (int i = 0; i < list.Count; i++)
                                            {
                                                if (list[i] is peonies)
                                                {
                                                    Console.WriteLine(i + 1 + ". " + list[i].toString() + "\nКласс: " + list[i].getClass());
                                                    Console.WriteLine("-------------------------------------");
                                                }
                                            }
                                            Console.WriteLine("Введите номер с которым хотите взаимодействовать: ");
                                            do
                                            {
                                                if (int.TryParse(Console.ReadLine(), out int sc) && sc >= 1 && sc <= list.Count + 1)
                                                {
                                                    int j = sc;

                                                    if (list[j - 1] is peonies)
                                                    {
                                                        SmellObject(list[j - 1]);
                                                        need = true;
                                                    }
                                                    else
                                                    {
                                                        Console.WriteLine("Такого варианта нет");
                                                        need = false;
                                                    }
                                                }
                                                else
                                                {
                                                    Console.WriteLine("Такого варианта нет");
                                                    need = false;
                                                }
                                            } while (need == false);
                                            break;

                                        case 5:
                                            for (int i = 0; i < list.Count; i++)
                                            {
                                                if (list[i] is perfume)
                                                {
                                                    Console.WriteLine(i + 1 + ". " + list[i].toString() + "\nКласс: " + list[i].getClass());
                                                    Console.WriteLine("-------------------------------------");
                                                }
                                            }
                                            Console.WriteLine("Введите номер с которым хотите взаимодействовать: ");
                                            do
                                            {
                                                if (int.TryParse(Console.ReadLine(), out int sc) && sc >= 1 && sc <= list.Count + 1)
                                                {
                                                    int j = sc;

                                                    if (list[j - 1] is perfume)
                                                    {
                                                        SmellObject(list[j-1]);
                                                        need = true;
                                                    }
                                                    else
                                                    {
                                                        Console.WriteLine("Такого варианта нет");
                                                        need = false;
                                                    }
                                                }
                                                else
                                                {
                                                    Console.WriteLine("Такого варианта нет");
                                                    need = false;
                                                }
                                            } while (need == false);
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