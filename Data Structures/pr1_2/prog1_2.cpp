#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <windows.h>

using namespace std;
const int MAX = 50;

//структура блинчик
struct pancake {
    string picture;
    int number;
};

//стек
class Stack {
    pancake data[MAX];
    int ind;
public:
    Stack() {
        ind = -1;
    }

    // конструктор копирования
    Stack(const Stack& other) {
        ind = other.ind;
        for (int i = 0; i <= ind; i++) {
            data[i] = other.data[i];
        }
    }

    // перегруженный оператор присваивания
    Stack& operator= (const Stack& other) {
        if (this == &other) {
            return *this;
        }
        ind = other.ind;
        for (int i = 0; i <= ind; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }
 
    void push(pancake value) {
        if (ind == MAX - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        ind++;
        data[ind] = value;
    }

    pancake pop() {
        if (ind == -1) {
            cout << "Stack underflow" << endl;
            return pancake{ "", -1 };
        }
        pancake top = data[ind];
        ind--;
        return top;
    }

    pancake top() {
        if (ind == -1) {
            cout << "Stack is empty" << endl;
            return pancake{ "", -1 };
        }
        return data[ind];
    }

    bool empty() {
        return ind == -1;
    }

    bool full() {
        return ind == MAX - 1;
    }
};

int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    SetConsoleOutputCP(1251);
    srand(time(nullptr));

    int numofchildren, total = 0, counter = 24;
    do {
        cout << "----------------------------------" << endl;
        cout << "Введите количество внуков (2 - 4)" << endl;
        cin >> numofchildren;
        if (numofchildren < 2) {
            cout << "Мало детей.." << endl;
        }
        else if (numofchildren > 4) {
            cout << "Слишком много детей" << endl;
        }
    } while (numofchildren < 2 || numofchildren > 4);
    cout << "----------------------------------" << endl;
    system("cls");

    Stack s1;
    cout << "-------------------------------------------" << endl;
    cout << "|  Номер блина  |  Картинка  | Еще испечь |" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < 25; i++) {
        string pictures[] = { "цветочки", "грибки", "котятки" };
        int picInd = random(0, 2);
        string picture = pictures[picInd];
        pancake panc = { picture, i };
        s1.push(panc);
        cout << "|       " << left << setw(8) << i + 1 << "|  " << left << setw(10) << picture << "|     " << left << setw(7) << 49 - i << "|" << endl;
    }
    cout << "-------------------------------------------" << endl;

    int p = 25;
    for (int i = 0; i < numofchildren; i++) {
        int toEat = random(8, 15);
        int eaten = 0;
        cout << "\nВнук" << i + 1 << " может съесть " << toEat << " блинчиков" << endl;
        int t = toEat;
        cout << "--------------------------------------------------------------" << endl;
        cout << "| Прошло сек |     Cъедено     |    Испечено    | Еще испечь |" << endl;
        cout << "--------------------------------------------------------------" << endl;
        for (int j = 1; j <= t; j++) {
            if (j % 2 == 1) {
                pancake panc = s1.top();
                if (s1.empty()) {
                    cout << "Блинчики кончились (((" << endl;
                    break;
                }
                else {
                    if (panc.number - 9 > 0) {
                        cout << "|     " << left << setw(7) << j * 30 << "|  #" << panc.number + 1 << ", " << left << setw(10) << panc.picture << "|       --       |     ";
                    }
                    else {
                        cout << "|     " << left << setw(7) << j * 30 << "|  #" << panc.number + 1 << ", " << left << setw(11) << panc.picture << "|       --       |     ";
                    }
                    if (p - 9 > 0) {
                        cout << left << setw(7) << p << "|" << endl;
                    }
                    else {
                        cout << left << setw(7) << p << "|" << endl;

                    }
                    s1.pop();
                    eaten += 1;
                    total += 1;
                }
            }
            else {
                pancake panc = s1.top();
                if (s1.empty()) {
                    cout << "Блинчики кончились (((" << endl;
                    break;
                }
                else {
                    if (panc.number - 9 > -1) {
                        cout << "|     " << left << setw(7) << j * 30 << "|  #" << panc.number + 1 << ", " << left << setw(10) << panc.picture;
                    }
                    else {
                        cout << "|     " << left << setw(7) << j * 30 << "|  #" << panc.number + 1 << ", " << left << setw(11) << panc.picture;

                    }
                    s1.pop();
                    eaten += 1;
                    total += 1;
                    string pictures[] = { "цветочки", "грибки", "котятки" };
                    int picInd = random(0, 2);
                    string picture = pictures[picInd];
                    counter += 1;
                    panc = { picture, counter };
                    s1.push(panc);
                    if (p - 10 > -1) {
                        cout << "|  #" << counter + 1 << ", " << left << setw(9) << picture << "|     " << left << setw(7) << p - 1 << "|" << endl;
                    }
                    else {
                        cout << "|  #" << counter + 1 << ", " << left << setw(9) << picture << "|     " << left << setw(7) << p - 1 << "|" << endl;

                    }
                    p -= 1;
                }
            }
        }
        if (eaten == 0) {
            cout << "--------------------------------------------------------------" << endl;
            cout << "Внук" << i + 1 << " не съел ни одного блинчика :(\n" << endl;
        }
        else if (eaten < toEat) {
            cout << "--------------------------------------------------------------" << endl;
            cout << "Внуку" << i + 1 << " не хватило " << toEat - eaten << " блиничиков, чтобы наесться ;(\n" << endl;
        }
        else {
            cout << "--------------------------------------------------------------" << endl;
            cout << "Внук" << i + 1 << " съел " << eaten << " блинчиков и больше не хочет ;)\n" << endl;
        }
        system("pause");
    }
    cout << "\n----------------------------------" << endl;
    cout << "Всего было съедено " << total << " блинчиков" << endl;
    if (50 - total > 0) {
        cout << "Еще остлось " << 50 - total << " блинчиков" << endl;
        cout << "----------------------------------" << endl;
    }
    else {
        cout << "Блинчиков больше не осталось.." << endl;
        cout << "----------------------------------" << endl;
    }
}