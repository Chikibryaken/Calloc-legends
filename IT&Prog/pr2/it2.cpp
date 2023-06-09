//Герои тёмных подземелий.
//Варианты полей : имя, здоровье, уровень стресса, яркость факела
//Варианты методов : смело идти вперёд, храбро бежать назад, сражаться, привал
//Возможные классы : герой(базовый), Антиквар, Арбалетчик, Воитель, Крестоносец.

#include <iostream>
#include <string>
#define c 50

using namespace std;

class character {
protected:
    string name;
    int health;
    int stress;
    int brightness;

public:
    character();
    character(string, int, int, int);
    virtual ~character();

    void set_name(string);
    void set_health(int);
    void set_stress(int);
    void set_brightness(int);

    string get_name();
    int get_health();
    int get_stress();
    int get_brightness();

    virtual void getClass() = 0 {
        cout << "Character" << endl;
    }

    void getInfo() {
        cout << "Name: " << get_name() << ", Health: " << get_health() << ", Stress level: " << get_stress() << ", Brightness level: " << get_brightness() << endl;
    }

    void forward() {
        cout << this->get_name() << " very boldly went forward" << endl;
    }

    void back() {
        cout << this->get_name() << " brave enough to run back" << endl;
    }

    void fight() {
        cout << this->get_name() << " trying to fight" << endl;
    }

    friend ostream& operator << (ostream&, const character&);
};

class antiquarian : public character {
public:
    antiquarian();
    antiquarian(string, int, int, int);
    ~antiquarian();

    void getClass() {
        cout << "Antiquarian" << endl;
    }

    void find() {
        cout << "The antiquarian " << get_name() << " found a rare item!" << endl;
    }
};

class arbalester : public character {
public:
    arbalester();
    arbalester(string, int, int, int);
    ~arbalester();

    void getClass() override {
        cout << "Arbalester" << endl;
    }

    void shot() {
        cout << "The arbalester " << get_name() << " cleverly missed and upset :(" << endl;
    }
};

class warrior : public character {
public:
    warrior();
    warrior(string, int, int, int);
    ~warrior();

    void getClass() override {
        cout << "Warrior" << endl;
    }

    void kill() {
        cout << "The warrior " << get_name() << " beheaded three, including himself too..." << endl;
    }
};

class crusader : public character {
public:
    crusader();
    crusader(string, int, int, int);
    ~crusader();

    void getClass() override {
        cout << "Crusader" << endl;
    }

    void pray() {
        cout << "The crusader " << get_name() << " banishes freak who believes in spaghetti monster" << endl;
    }
};

int main() {
    character* chrc[c];
    string n;
    int cnt, h = 0, s = 0, b = 0;
    char menu, men, me, nemu;
    for (int i = 0; i < c; i++)
    {
        chrc[i] = nullptr;
    }
    chrc[0] = new antiquarian("Ezio Auditore", 70, 20, 30);
    chrc[1] = new antiquarian("Hendrik", 60, 15, 30);
    chrc[2] = new arbalester("Legolas", 70, 10, 25);
    chrc[3] = new arbalester("Connor Kenway", 75, 10, 25);
    chrc[4] = new warrior("Kratos", 150, 0, 50);
    chrc[5] = new warrior("Geralt z Rivii", 150, 0, 50);
    chrc[6] = new crusader("Yennefer", 100, 10, 50);
    chrc[7] = new crusader("Merlin", 100, 10, 50);
    for (int i = 0; i < c && chrc[i] != NULL; i++) {
        cnt = i + 1;
    }
    do {
        cout << "----------------------" << endl;
        cout << "1. Add a new character" << endl;
        cout << "2. Show all characters" << endl;
        cout << "3. Take action" << endl;
        cout << "4. Ultimate" << endl;
        cout << "0. Exit" << endl;
        cout << "----------------------" << endl;
        cin >> menu;
        switch (menu) {
        case '1':
            system("cls");
            do {
                cout << "-----------------------------------" << endl;
                cout << "What class to add the character to?" << endl;
                cout << "1. Antiquarian" << endl;
                cout << "2. Arbalester" << endl;
                cout << "3. Warrior" << endl;
                cout << "4. Crusader" << endl;
                cout << "0. Back" << endl;
                cout << "-----------------------------------" << endl;
                cin >> men;
                switch (men) {
                case '1':
                    cout << "-----------------------------------" << endl;
                    cout << "Enter name: ";
                    cin >> n;
                    do {
                        cout << "\nEnter number of health points: ";
                        cin >> h;
                        if (h > 200 || h < 0) {
                            cout << "Enter a value from 0 to 200" << endl;
                        }
                    } while (h > 200 || h < 0);
                    do {
                        cout << "\nEnter stress level: ";
                        cin >> s;
                        if (s > 50 || s < 0) {
                            cout << "Enter a value from 0 to 50" << endl;
                        }
                    } while (s > 50 || s < 0);
                    do {
                        cout << "\nEnter torch brightness: ";
                        cin >> b;
                        if (b > 50 || b < 0) {
                            cout << "Enter a value from 0 to 50" << endl;
                        }
                    } while (b > 50 || b < 0);
                    cout << "-----------------------------------" << endl;
                    chrc[cnt] = new antiquarian(n, h, s, b);
                    cout << "Character was added" << endl;
                    cout << "-----------------------------------" << endl;
                    cnt += 1;
                    break;
                case '2':
                    cout << "-----------------------------------" << endl;
                    cout << "Enter name: ";
                    cin >> n;
                    do {
                        cout << "\nEnter number of health points: ";
                        cin >> h;
                        if (h > 200 || h < 0) {
                            cout << "Enter a value from 0 to 200" << endl;
                        }
                    } while (h > 200 || h < 0);
                    do {
                        cout << "\nEnter stress level: ";
                        cin >> s;
                        if (s > 50 || s < 0) {
                            cout << "Enter a value from 0 to 50" << endl;
                        }
                    } while (s > 50 || s < 0);
                    do {
                        cout << "\nEnter torch brightness: ";
                        cin >> b;
                        if (b > 50 || b < 0) {
                            cout << "Enter a value from 0 to 50" << endl;
                        }
                    } while (b > 50 || b < 0);
                    cout << "-----------------------------------" << endl;
                    chrc[cnt] = new arbalester(n, h, s, b);
                    cout << "Character was added" << endl;
                    cout << "-----------------------------------" << endl;
                    cnt += 1;
                    break;
                case '3':
                    cout << "-----------------------------------" << endl;
                    cout << "Enter name: ";
                    cin >> n;
                    do {
                        cout << "\nEnter number of health points: ";
                        cin >> h;
                        if (h > 200 || h < 0) {
                            cout << "Enter a value from 0 to 200" << endl;
                        }
                    } while (h > 200 || h < 0);
                    do {
                        cout << "\nEnter stress level: ";
                        cin >> s;
                        if (s > 50 || s < 0) {
                            cout << "Enter a value from 0 to 50" << endl;
                        }
                    } while (s > 50 || s < 0);
                    do {
                        cout << "\nEnter torch brightness: ";
                        cin >> b;
                        if (b > 50 || b < 0) {
                            cout << "Enter a value from 0 to 50" << endl;
                        }
                    } while (b > 50 || b < 0);
                    cout << "-----------------------------------" << endl;
                    chrc[cnt] = new warrior(n, h, s, b);
                    cout << "Character was added" << endl;
                    cout << "-----------------------------------" << endl;
                    cnt += 1;
                    break;
                case '4':
                    cout << "-----------------------------------" << endl;
                    cout << "Enter name: ";
                    cin >> n;
                    do {
                        cout << "\nEnter number of health points: ";
                        cin >> h;
                        if (h > 200 || h < 0) {
                            cout << "Enter a value from 0 to 200" << endl;
                        }
                    } while (h > 200 || h < 0);
                    do {
                        cout << "\nEnter stress level: ";
                        cin >> s;
                        if (s > 50 || s < 0) {
                            cout << "Enter a value from 0 to 50" << endl;
                        }
                    } while (s > 50 || s < 0);
                    do {
                        cout << "\nEnter torch brightness: ";
                        cin >> b;
                        if (b > 50 || b < 0) {
                            cout << "Enter a value from 0 to 50" << endl;
                        }
                    } while (b > 50 || b < 0);
                    cout << "-----------------------------------" << endl;
                    chrc[cnt] = new crusader(n, h, s, b);
                    cout << "Character was added" << endl;
                    cout << "-----------------------------------" << endl;
                    cnt += 1;
                    break;
                case '0':
                    system("cls");
                    break;
                default: 
                    cout << "-----------------------------------" << endl;
                    cout << "Invalid choice. Try again." << endl;
                    cout << "-----------------------------------" << endl;
                }
            } while (men != '0');
            break;
        case '2':
            for (int i = 0; i < c && chrc[i] != NULL; i++) {
                cout << "----------------------------------------------------------------------" << endl;
                chrc[i]->getClass();
                chrc[i]->getInfo();
                cout << endl;
                cout << "----------------------------------------------------------------------" << endl;
            }
            break;
        case '3':
            system("cls");
            do {
                cout << "-----------------------------------" << endl;
                cout << "What action to take?" << endl;
                cout << "1. Fight" << endl;
                cout << "2. Go foward" << endl;
                cout << "3. Run back" << endl;
                cout << "0. Exit" << endl;
                cout << "-----------------------------------" << endl;
                cin >> me;
                switch (me) {
                case'1':
                    for (int i = 0; i < c && chrc[i] != NULL; i++) {
                        chrc[i]->fight();
                    }
                    break;
                case'2':
                    for (int i = 0; i < c && chrc[i] != NULL; i++) {
                        chrc[i]->forward();
                    }
                    break;
                case '3':
                    for (int i = 0; i < c && chrc[i] != NULL; i++) {
                        chrc[i]->back();
                    }
                    break;
                case '0':
                    system("cls");
                    break;
                default:
                    cout << "-----------------------------------" << endl;
                    cout << "Invalid choice. Try again." << endl;
                    cout << "-----------------------------------" << endl;
                }
            } while (me != '0');
            break;
        case '4':
            system("cls");
            do {
                cout << "-----------------------------------" << endl;
                cout << "Enter class" << endl;
                cout << "1. Antiquarian" << endl;
                cout << "2. Arbalester" << endl;
                cout << "3. Warrior" << endl;
                cout << "4. Crusader" << endl;
                cout << "0. Back" << endl;
                cout << "-----------------------------------" << endl;
                cin >> nemu;
                switch (nemu) {
                case '1':
                    for (int i = 0; i < c && chrc[i] != NULL; i++) {
                        antiquarian* antiq = dynamic_cast<antiquarian*>(chrc[i]);
                        if (antiq) {
                            cout << "--------------------------------------------" << endl;
                            cout << antiq->get_name() << endl;
                            antiq->find();
                            cout << "--------------------------------------------" << endl;
                        }
                    }
                    break;
                case '2':
                    for (int i = 0; i < c && chrc[i] != NULL; i++) {
                        arbalester* arbal = dynamic_cast<arbalester*>(chrc[i]);
                        if (arbal) {
                            cout << "--------------------------------------------" << endl;
                            cout << arbal->get_name() << endl;
                            arbal->shot();
                            cout << "--------------------------------------------" << endl;
                        }
                    }
                    break;
                case '3':
                    for (int i = 0; i < c && chrc[i] != NULL; i++) {
                        warrior* warr = dynamic_cast<warrior*>(chrc[i]);
                        if (warr) {
                            cout << "--------------------------------------------" << endl;
                            cout << warr->get_name() << endl;
                            warr->kill();
                            cout << "--------------------------------------------" << endl;
                        }
                    }
                    break;
                case '4':
                    for (int i = 0; i < c && chrc[i] != NULL; i++) {
                        crusader* crus = dynamic_cast<crusader*>(chrc[i]);
                        if (crus) {
                            cout << "--------------------------------------------" << endl;
                            cout << crus->get_name() << endl;
                            crus->pray();
                            cout << "--------------------------------------------" << endl;
                        }
                    }
                    break;
                case '0':
                    system("cls");
                    break;
                default:
                    cout << "-----------------------------------" << endl;
                    cout << "Invalid choice. Try again." << endl;
                    cout << "-----------------------------------" << endl;
                }
            } while (nemu != '0');
            break;
        case '0':
            for (int i = 0; i < c && chrc[i] != NULL; i++)
            {
                delete chrc[i];
            }
            return 0;
        default:
            cout << "-----------------------------------" << endl;
            cout << "Invalid choice. Try again." << endl;
            cout << "-----------------------------------" << endl;
        }
    } while (menu != '0');
}

//сеттеры
void character::set_name(string n) {
    name = n;
}
void character::set_health(int h) {
    health = h;
}
void character::set_stress(int s) {
    stress = s;
}
void character::set_brightness(int b) {
    brightness = b;
}

//геттеры
string character::get_name() {
    return name;
}
int character::get_health() {
    return health;
}
int character::get_stress() {
    return stress;
}
int character::get_brightness() {
    return brightness;
}

//конструкторы
//базовый
character::character() {
    this->name = "No name";
    this->health = 100;
    this->stress = 0;
    this->brightness = 50;
}
character::character(string n, int h, int s, int b) {
    this->name = n;
    this->health = h;
    this->stress = s;
    this->brightness = b;
}
character::~character() {
    cout << "Character no longer exists" << endl;
}

//антиквар
antiquarian::antiquarian() {
    this->name = "No name";
    this->health = 100;
    this->stress = 0;
    this->brightness = 50;
}
antiquarian::antiquarian(string n, int h, int s, int b) {
    this->name = n;
    this->health = h;
    this->stress = s;
    this->brightness = b;
}
antiquarian::~antiquarian() {
    cout << "Antiquarian no longer exists" << endl;
}

//арбалетчик
arbalester::arbalester() {
    this->name = "No name";
    this->health = 100;
    this->stress = 0;
    this->brightness = 50;
}
arbalester::arbalester(string n, int h, int s, int b) {
    this->name = n;
    this->health = h;
    this->stress = s;
    this->brightness = b;
}
arbalester::~arbalester() {
    cout << "Arbalester no longer exists" << endl;
}

//воитель
warrior::warrior() {
    this->name = "No name";
    this->health = 100;
    this->stress = 0;
    this->brightness = 50;
}
warrior::warrior(string n, int h, int s, int b) {
    this->name = n;
    this->health = h;
    this->stress = s;
    this->brightness = b;
}
warrior::~warrior() {
    cout << "Warrior no longer exists" << endl;
}

//крестоносец
crusader::crusader() {
    this->name = "No name";
    this->health = 100;
    this->stress = 0;
    this->brightness = 50;
}
crusader::crusader(string n, int h, int s, int b) {
    this->name = n;
    this->health = h;
    this->stress = s;
    this->brightness = b;
}
crusader::~crusader() {
    cout << "Crusader no longer exists" << endl;
};

ostream& operator << (ostream& out, const character& o) {
    cout << "Name: " << o.name << "\nHealth: " << o.health << "\nStress level: " << o.stress << "\nBrightness level: " << o.brightness << endl;
    return out;
}