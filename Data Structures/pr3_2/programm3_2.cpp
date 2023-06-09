#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <Windows.h>
#include <iomanip>

#include "OrderedDoublyLinkedList.h"
#include "BinarySearchtree.h"

using namespace std;
const int N = 200000, H = 100;

bool isNumberUnique(int num, unsigned long arr[]) { //проверка на присутствие ключа в файле
	for (int i = 0; i < N; i++) {
		if (arr[i] == num) {
			return false;
		}
	}
	return true;
}

int random(long min, long max) {
	return min + rand() % (max - min + 1);
}

int main() {
	SetConsoleOutputCP(1251);
	srand(time(nullptr));

	unsigned long arr[N];
	int keys[H], totalCmp = 0;
	char menu;
	ODLList list;
	BSTree tree;

	ifstream file("C:\\Data Structures\\pr3_2\\programm3_2\\test.txt");
	if (!file) {
		cout << "Ошибка при открытии файла" << endl;
		return 1;
	}
	for (int i = 0; i < N; ++i) {
		file >> arr[i];
	}
	file.close();

	for (int i = 0; i < 17; i++) { //числа, меньше имеющихся в файле
		keys[i] = random(0, 10000000);
	}
	for (int i = 0, j = 17; i < N && j < 67; i += 3700, j++) { //числа, имеющиеся в файле
		keys[j] = arr[i];
	}
	int a = 67;
	while (a < 84) {
		int rand = random(10000000, 100000000); //числа в промежутке с имеющимися в файле
		if (isNumberUnique(rand, arr)) {
			keys[a] = rand;
			a++;
		}
	}
	for (int i = 84; i < 100; i++) { //числа, больше имеющихся в файле
		keys[i] = random(100000000, 1000000000);
	}

	do {
		cout << "-----------------------------------------------" << endl;
		cout << "1. Упорядоченный двусвязный линейный список   |" << endl;
		cout << "2. Несбалансированное дерево бинарного поиска |" << endl;
		cout << "3. Посмотреть все ключи                       |" << endl;
		cout << "0. Выход                                      |" << endl;
		cout << "-----------------------------------------------" << endl;
		cin >> menu;
		switch (menu) {
		case '1':
			system("cls");
			totalCmp = 0;

			for (int i = 0; i < N; i++) { //загрузка в список
				list.insert_sorted(arr[i]);
			}
			cout << "----------------------------------------------------" << endl;
			cout << "|    Ключ    | Имеется в файле? | Кол-во сравнений |" << endl;
			cout << "----------------------------------------------------" << endl;
			for (int i = 0; i < H; i++) { //поиск всех ключей
				int cntCmp = 0;
				int key = keys[i];
				bool isFound = false;
				node* current = list.getBegin();

				while (current != nullptr) {
					if (current->data == key) {
						isFound = true;
						break;
					}
					current = current->next;
					cntCmp++;
				}

				cout << "|  " << left << setw(9) << key << " |       ";
				cout << left << setw(10) << (isFound ? "Да" : "Нет") << " |      ";
				cout << left << setw(12) << cntCmp << "|" << endl;
				totalCmp += cntCmp;
			}
			cout << "----------------------------------------------------" << endl;
			cout << "Всего совершено сравнений: " << totalCmp << endl;
			cout << "Среднее количество сравнений: " << totalCmp / H << endl;
			cout << "Количество затраченной памяти: " << N * sizeof(node) << endl;
			break;

		case '2':
			system("cls");
			totalCmp = 0;

			for (int i = 0; i < N; i++) { //загрузка в дерево
				tree.insert(arr[i]);
			}
			cout << "----------------------------------------------------" << endl;
			cout << "|    Ключ    | Имеется в файле? | Кол-во сравнений |" << endl;
			cout << "----------------------------------------------------" << endl;
			for (int i = 0; i < H; i++) {
				int key = keys[i];
				bool isFound = tree.search(key); //поиск всех ключей

				cout << "|  " << left << setw(9) << key << " |       ";
				cout << left << setw(10) << (isFound ? "Да" : "Нет") << " |      ";	
				cout << left << setw(12) << cntCmp2 << "|" << endl;
				totalCmp += cntCmp2;
			}
			cout << "----------------------------------------------------" << endl;
			cout << "Всего совершено сравнений: " << totalCmp << endl;
			cout << "Среднее количество сравнений: " << totalCmp / H << endl;
			cout << "Количество затраченной памяти: " << N * sizeof(Node) << endl;
			break;

		case '3':
			system("cls");

			cout << "-------------------------" << endl;
			cout << "|  #  |  Список ключей  |" << endl;
			cout << "-------------------------" << endl;

			for (int i = 0; i < H; i++) {
				int key = keys[i];
				cout << "| " << left << setw(4) << i + 1 << "|    " << left << setw(12) << key << " |" << endl;
			}
			cout << "-------------------------" << endl;
			break;

		case '0':
			break;

		default:
			cout << "Выбран несуществующий пункт меню" << endl;
		}

	} while (menu != '0');
}