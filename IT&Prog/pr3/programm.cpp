#include <iostream>
#include "deque.h"
#include "template.h"

using namespace std;

int main() {
	const int size = 6;
	int s = 0, x = 0;
	int arr1[] = { 5, 2, -3, 6, -10, 8 };
	unsigned int arr2[] = { 7, 14, 2, 24, 12, 5 };

	Deque<int> deque1(size), deque2(size);
	Deque<unsigned> deque3(size), deque4(size);
	int front1 = 0, rear1 = 0;
	unsigned front2 = 0, rear2 = 0;
	char menu, nemu, unem, men, nem;
	do {
		cout << "---------------------------------------------------------------" << endl;
		cout << "1. Sorting                                                     |" << endl;
		cout << "2. Test deque (nodes)                                          |" << endl;
		cout << "0. Exit                                                        |" << endl;
		cout << "---------------------------------------------------------------" << endl;
		cin >> menu;
		switch (menu) {
		case '1':
			system("cls");
			do {
				cout << "---------------------------------------------------------------" << endl;
				cout << "1. Sort elements in descending order in an int array          |" << endl;
				cout << "2. Sort elements in descending order in an unsigned int array |" << endl;
				cout << "0. Back                                                       |" << endl;
				cout << "---------------------------------------------------------------" << endl;
				cin >> nemu;
				switch (nemu) {
				case '1':
					cout << "---------------------------------------------------------------" << endl;
					cout << "Int array: " << endl;
					printArray(arr1, size);
					sortArray(arr1, size);
					cout << "Sorted int array: " << endl;
					printArray(arr1, size);
					break;

				case '2':
					cout << "---------------------------------------------------------------" << endl;
					cout << "Unsigned int array: " << endl;
					printArray(arr2, size);
					sortArray(arr2, size);
					cout << "Sorted unsigned int array: " << endl;
					printArray(arr2, size);
					break;

				case '0':
					system("cls");
					break;

				default:
					cout << "!!!!! INVALID CHOICE !!!!! TRY AGAINE !!!!!" << endl;
				}
			} while (nemu != '0');
			break;

		case '2':
			system("cls");
			do {
				cout << "---------------------------------------------------------------" << endl;
				cout << "1. Test int deque                                             |" << endl;
				cout << "2. Test unsigned int deque                                    |" << endl;
				cout << "0. Back                                                       |" << endl;
				cout << "---------------------------------------------------------------" << endl;
				cin >> unem;
				switch (unem) {
				case '1':
					cout << "---------------------------------------------------------------" << endl;
					do {
						cout << "Enter size deque: ";
						cin >> s;
						if (s < 1) {
							cout << "Too small value\n";
						}
					} while (s < 1);
					cout << "Enter " << s << " int elements: " << endl;
					for (int i = 0; i < s; i++) {
						cin >> x;
						deque1.pushRear(x);
					}
					deque2 = deque1;
					cout << "Deque after push: " << endl;
					while (!deque2.isEmpty()) {
						cout << deque2.getFront() << " ";
						deque2.popFront();
					}

					do {
						cout << "\n---------------------------------------------------------------" << endl;
						cout << "1. Pop front" << endl;
						cout << "2. Pop rear" << endl;
						cout << "3. Print deque" << endl;
						cout << "4. Full or empty" << endl;
						cout << "0. Back" << endl;
						cout << "---------------------------------------------------------------" << endl;
						cin >> men;
						switch (men) {
						case '1':
							front1 = deque1.getFront();
							deque1.popFront();
							cout << "Popped element: " << endl;
							cout << "Front: " << front1 << endl;
							break;

						case '2':
							rear1 = deque1.getRear();
							deque1.popRear();
							cout << "Popped element: " << endl;
							cout << "Rear: " << rear1 << endl;
							break;

						case'3':
							deque2 = deque1;
							cout << "Deque: " << endl;
							while (!deque2.isEmpty()) {
								cout << deque2.getFront() << " ";
								deque2.popFront();
							}
							cout << "\nPopped elements: " << endl;
							cout << "Front: " << front1 << endl;
							cout << "Rear: " << rear1 << endl;
							break;

						case'4':
							if (deque1.isEmpty()) {
								cout << "Deque is empty" << endl;
							}
							else {
								cout << "Deque is not empty" << endl;
							}
							break;

						case'0':
							system("cls");
							break;

						default:
							cout << "!!!!! INVALID CHOICE !!!!! TRY AGAINE !!!!!" << endl;
						}
					} while (men != '0');
					break;

				case '2':
					cout << "---------------------------------------------------------------" << endl;
					do {
						cout << "Enter size deque: ";
						cin >> s;
						if (s < 1) {
							cout << "Too small value" << endl;
						}
					} while (s < 1);
					cout << "Enter " << s << " int elements: " << endl;
					for (int i = 0; i < s; i++) {
						do {
							cin >> x;
							if (x < 0) {
								cout << "Too small value" << endl;
							}
							else {
								deque3.pushRear(x);
							}
						} while (x < 0);
					}
					cout << "Deque after push: " << endl;
					deque4 = deque3;
					while (!deque4.isEmpty()) {
						cout << deque4.getFront() << " ";
						deque4.popFront();
					}

					do {
						cout << "\n---------------------------------------------------------------" << endl;
						cout << "1. Pop front" << endl;
						cout << "2. Pop rear" << endl;
						cout << "3. Print deque and last popped elements" << endl;
						cout << "4. Full or empty" << endl;
						cout << "0. Back" << endl;
						cout << "---------------------------------------------------------------" << endl;
						cin >> men;
						switch (men) {
						case '1':
							front2 = deque3.getFront();
							deque3.popFront();
							cout << "Popped element: " << endl;
							cout << "Front: " << front2 << endl;
							break;

						case '2':
							rear2 = deque3.getRear();
							deque3.popRear();
							cout << "Popped element: " << endl;
							cout << "Rear: " << rear2 << endl;
							break;

						case'3':
							deque4 = deque3;
							cout << "Deque: " << endl;
							while (!deque4.isEmpty()) {
								cout << deque4.getFront() << " ";
								deque4.popFront();
							}
							cout << "\nPopped elements: " << endl;
							cout << "Front: " << front2 << endl;
							cout << "Rear: " << rear2 << endl;
							break;

						case'4':
							if (deque3.isEmpty()) {
								cout << "Deque is empty" << endl;
							}
							else {
								cout << "Deque is not empty" << endl;
							}
							break;

						case'0':
							system("cls");
							break;

						default:
							cout << "!!!!! INVALID CHOICE !!!!! TRY AGAINE !!!!!" << endl;
						}
					} while (men != '0'); 
					break;

				case '0':
					system("cls");
					break;

				default:
					cout << "!!!!! INVALID CHOICE !!!!! TRY AGAINE !!!!!" << endl;
				}
			} while (unem != '0');
			break;

		case '0':
			cout << "--------------------- Exiting programm.... --------------------" << endl;
			break;

		default:
			cout << "!!!!! INVALID CHOICE !!!!! TRY AGAINE !!!!!" << endl;
		}
	} while (menu != '0');
}
