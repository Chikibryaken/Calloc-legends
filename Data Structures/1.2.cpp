#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;
const int MAX = 100;

//структура оборудование
struct obor {
	int count = 0;
	double price = 0;

	obor(int c, double p) {
		count = c;
		price = p;
	}
	obor() {
		int count = 0;
		double price = 0;
	}

};



// стэк
class stack {
	obor data[MAX];
	int ind;
public:
	stack() {
		ind = -1;
	}

	// Конструктор копирования
	stack(const stack& other) {
		ind = other.ind;
		for (int i = 0; i <= ind; i++) {
			data[i] = other.data[i];
		}
	}

	// Перегрузка оператора присваивания
	stack& operator=(const stack& other) {
		if (this != &other) {
			ind = other.ind;
			for (int i = 0; i <= ind; i++) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	~stack() {
		cout << "Destructor was called" << endl;
	}

	void push(obor value) {
		if (ind == MAX - 1) {
			cout << "Stack overflow" << endl;
			return;
		}
		ind++;
		data[ind] = value;
	}

	obor pop() {
		obor top = data[ind];
		ind--;
		return top;
	}
	obor top() {
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
	srand(time(nullptr));
	char pref, menu;
	int count, countr = 0, counts = 0, summy, razn;
	double county = 0;
	double summs = 0, summr = 0, price, temp, sellsr = 0, sells = 0;
	stack s1, s2;
	obor o;

	for (int i = 0; i < 15; i++) { // заполнение стека рандомными значениями
		temp = rand() % 201 + 100;
		price = (temp / 100) + 0.03;
		count = (rand() % 12) + 1;
		obor o(count, price);
		s1.push(o);
		s2 = s1;
	}

	system("cls");
	do {
		s2 = s1;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "|  Count  |  Original Price  |" << endl;
		for (int i = 0; i < MAX; i++) { // первоначальный вывод заполненого рандомными значениями стека
			if (s2.empty() == 0) {
				o = s2.pop();
				double sum = o.count * o.price;
				cout << "|" << internal << setw(5) << o.count << "    |" << internal << setw(11) << setprecision(4) << sum << "$" << "      |" << endl;
			}
			else break;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
		cout << "------------------------------" << endl;
		cout << "Choose what to do..." << endl;
		cout << "'R'. Add new pieces" << endl;
		cout << "'S'. Sell pieces" << endl;
		cout << "0. Exit" << endl;
		cout << "------------------------------" << endl;
		cin >> menu;
		switch (tolower(menu)) {
		case 'r': {
			system("cls");
			cout << "It will be operation of buying" << endl;
			cout << "Enter count of pieces" << endl; // заполнение нового оборудования
			do {
				cin >> count;
				if (count < 1 || count > 76) cout << "Enter value from 1 to 76!!!" << endl;
			} while (count < 1 || count > 76);
			if (s1.full()) { // проверка стека на заполненность
				cout << "Can't add pieces cause of stack overflow" << endl;
				goto h;
			}
			else {
				cout << "Enter price for 1 piece" << endl;
				do {
					cin >> price;
					if (price < 1 || price > 100) cout << "Enter value from 1 to 100!!!" << endl;
				} while (price < 1 || price > 100);
				if (s1.full()) {
					cout << "Can't add pieces cause of stack overflow, added only " << countr << " pieces" << endl;
					break;
				}
				else {
					obor o(count, price); // добавление нового элемента в стек
					s1.push(o);
					countr += o.count;
				}
			}
			s2 = s1;
			cout << "You succesfully added pieces" << endl;
		h:
			system("pause");
			break;
		}
		case 's': {
			system("cls");
			s2 = s1;
			cout << "Type number of selled pieces" << endl;
			do { // ввод количества продаваемого оборудования
				cin >> counts;
				summy = counts;
				summr = 0;
				if (counts < 1 || counts > 100) cout << "Enter value from 1 to 100" << endl;
			} while (counts < 1 || counts > 100);
			cout << "Solded items: " << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "|  Count  |    Price +20%    |" << endl;
			for (int i = 0; counts > 0; i++) {
				if (s1.empty() == 0) {
					o = s1.top();
					if (o.count - counts > 0) { //если количество в стеке больше чем требуется удалить
						s1.pop();
						razn = o.count - counts;
						countr += counts;
						double sum = o.count * o.price;
						cout << "|" << internal << setw(5) << counts << "    |" << internal << setw(11) << setprecision(4) << sum << "$" << "      |" << endl;
						county += sum;
						counts -= o.count - razn;
						summr += o.price * razn * 1.2;
						obor i(razn, o.price * razn);
						s1.push(i);
						razn = 0;
					}
					else { // если количества достаточно то элемент просто удаляется
						s1.pop();
						countr += o.count;
						counts -= o.count;
						summr += o.price * o.count * 1.2;
						double sum = o.count * o.price * 1.2;
						cout << "|" << internal << setw(5) << o.count << "    |" << internal << setw(11) << setprecision(4) << sum << "$" << "      |" << endl;
						county += sum;
					}
				}
				else break;
			}
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			if (counts == 0) cout << "Succesfully sold " << summy << " pieces on summ of " << county << "$" << endl << endl; // вывод общего количества проданного товара
			else if (counts > 0) {
				cout << "Didn't enough pieces to sold all, need more " << summy - countr << " pieces" << endl; // если не хватило элементов в стеке для продажи всего товара
				goto g;
			}
			s2 = s1;
			cout << "Left theese pieces after sold: " << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "|  Count  |  Original price  |" << endl;
			for (int i = 0; i < MAX; i++) { // вывод оставшихся элементов в стеке
				if (s2.empty() == 0) {
					o = s2.pop();
					double sum = o.count * o.price;
					cout << "|" << internal << setw(5) << o.count << "    |" << internal << setw(11) << setprecision(4) << sum << "$" << "      |" << endl;
				}
				else break;
			}
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			countr = 0;
			counts = 0;
		g:
			system("pause");
			break;
		}
		case '0': {
			system("cls");
			cout << "Exiting program..." << endl;
			break;
		}
		default:
			cout << "Invalid choice try again" << endl;
			break;

		}
	} while (menu != '0');
	return 0;
}