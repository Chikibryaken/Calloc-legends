#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <random>
#include <iterator>
#include <Windows.h>

#include "include/nlohmann/json.hpp"

using namespace std;

struct Struct {
    string name;
    int mainPar;
    int auxPar;
};

bool compareMain(const Struct& a, const Struct& b) {
    return a.mainPar > b.mainPar; //сравниваем вторичные параметры в убывающем порядке
}

int main() {
    SetConsoleOutputCP(1251);
    srand(time(nullptr));

	ifstream file("C:\\it'n'pr\\it4\\programm\\25.txt");
	if (!file.is_open()) {
		cout << "Ошибка при открытии файла" << endl;
		return 1;
	}

    //создание множества
	set<string> words;
	string line1;
	while (getline(file, line1, '$')) {
		words.insert(line1);
	}
    cout << "Множество создано" << endl;
    file.close();
    
    //создание словаря
    map<int, int> frequency;
    map<int, int> count;
    string line2;
    file.open("C:\\it'n'pr\\it4\\programm\\25.txt");
    while (getline(file, line2, '$')) {
        int length = line2.length();

        if (frequency.find(length) == frequency.end()) {
            frequency[length] = 1;
        }
        else {
            frequency[length]++;
        }
    }
    cout << "Словарь создан" << endl;

    for (const auto& word : words) {
        int length = word.length();
        if (count.find(length) == count.end()) {
            count[length] = 1;
        }
        else {
            count[length]++;
        }
    }

    //создание списка структур
    vector<Struct> List;
    for (int i = 0; i < 100; i++) {
        Struct strct;

        //выбор случайного слова из множества
        int randInd = rand() % words.size();
        auto it = next(words.begin(), randInd);
        strct.name = *it;

        //получение трех случайных элементов из словаря
        auto freqSize = frequency.size();
        auto randomOffset1 = rand() % freqSize;
        auto randomOffset2 = rand() % freqSize;
        auto randomOffset3 = rand() % freqSize;

        auto it1 = frequency.begin();
        auto it2 = frequency.begin();
        auto it3 = frequency.begin();

        advance(it1, randomOffset1);
        advance(it2, randomOffset2);
        advance(it3, randomOffset3);

        //вычисление основного параметра
        strct.mainPar = it1->second * it2->second * it3->second;

        //вычисление вторичного параметра
        int length = strct.name.length();
        strct.auxPar = count[length] * count[length];
        
        List.push_back(strct);
        sort(List.begin(), List.end(), compareMain);
    }

    cout << "-------------------------------------------------" << endl;
    cout << "|     Список, отсортированный по убыванию       |" << endl;
    cout << "|             основного параметра               |" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "|     Название     |   Основной   |  Вторичный  |" << endl;
    cout << "-------------------------------------------------" << endl;
    for (const auto& strct : List) {
        cout << "|  " << left << setw(16) << strct.name << "|   " << left << setw(11) << strct.mainPar << "|    " << left << setw(9) << strct.auxPar << "|" << endl;
    }
    cout << "-------------------------------------------------" << endl;
    system("pause");

    int maxAuxPar = List[0].auxPar;
    for (const auto& strct : List) {
        if (strct.auxPar > maxAuxPar) {
            maxAuxPar = strct.auxPar;
        }
    }
    vector<Struct> newList;
    copy_if(List.begin(), List.end(), back_inserter(newList), [maxAuxPar](const Struct& strct) {
        return strct.auxPar == maxAuxPar; });

    cout << "-------------------------------------------------" << endl;
    cout << "|     Новый список, содержащий максимальные     |" << endl;
    cout << "|        значения вторичного параметра          |" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "|     Название     |   Основной   |  Вторичный  |" << endl;
    cout << "-------------------------------------------------" << endl;
    for (const auto& strct : newList) {
        cout << "|  " << left << setw(16) << strct.name << "|   " << left << setw(11) << strct.mainPar << "|    " << left << setw(9) << strct.auxPar << "|" << endl;
    }
    cout << "-------------------------------------------------" << endl;
    system("pause");

    nlohmann::json jsonObj;
    for (const auto& strct : newList) {
        nlohmann::json item;
        item["name"] = strct.name;
        item["mainPar"] = strct.mainPar;
        item["auxPar"] = strct.auxPar;
        jsonObj.push_back(item);
    }

    ofstream File("output.json");
    if (!File.is_open()) {
        cout << "Ошибка при открытии файла для записи" << endl;
        return 1;
    }
    File << setw(4) << jsonObj << endl;
    File.close();
    cout << "Файл output.json успешно создан" << endl;

    //загрузка файла формата JSON
    ifstream inputFile("output.json");
    if (!inputFile.is_open()) {
        cout << "Ошибка при открытии файла" << endl;
        return 1;
    }

    //чтение JSON-объекта из файла
    nlohmann::json jsonobj;
    inputFile >> jsonobj;
    inputFile.close();

    //создание списка на основе данных из JSON-объекта
    vector<Struct> list;
    for (const auto& item : jsonobj) {
        Struct strct;
        strct.name = item["name"];
        strct.mainPar = item["mainPar"];
        strct.auxPar = item["auxPar"];
        list.push_back(strct);
    }

    //перетасовка
    random_device rd;
    default_random_engine generator(rd());
    shuffle(list.begin(), list.end(), generator);

    //вывод
    cout << "-------------------------------------------------" << endl;
    cout << "|            Перетасованный список              |" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "|     Название     |   Основной   |  Вторичный  |" << endl;
    cout << "-------------------------------------------------" << endl;
    for (const auto& strct : list) {
        cout << "|  " << left << setw(16) << strct.name << "|   " << left << setw(11) << strct.mainPar << "|    " << left << setw(9) << strct.auxPar << "|" << endl;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}