#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>

using namespace std;

const int n = 10, n1 = 10000, n2 = 30000, n3 = 70000, n4 = 100000;
unsigned long long int cntMain, cntAux;
int memory;

void bubbleSort(long arr[], int n) {
    memory = 0;
    cntAux = 0;
    cntMain = 0;
    int i, j, temp;
    for (cntAux++, i = 0; i < n - 1; cntAux++, i++) {
        for (cntAux++, j = 0; j < n - i - 1; cntAux++, j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                cntMain += 3;
            }
        }
    }
    memory = 3 * sizeof(int);
}

int main() {
    long arr1[n1], arr2[n2], arr3[n3], arr4[n4], s = 0;
    char menu;
    clock_t startTime = 0;
    clock_t endTime = 0;

    do {
        ifstream file("C:\\Data Structures\\pr3_1\\programm3_1\\test_numbers.txt");
        cout << "----------------------------------------------------------------------" << endl;
        cout << "1. Sort 10000 elements" << endl;
        cout << "2. Sort 30000 elements" << endl;
        cout << "3. Sort 70000 elements" << endl;
        cout << "4. Sort 100000 elements" << endl;
        cout << "0. Exit" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cin >> menu;
        switch (menu) {
        case '1':
            for (int i = 0; i < n1; i++) {
                file >> arr1[i];
            }
            startTime = 0;
            endTime = 0;

            cout << "----------------------------------------------------------------------" << endl;
            cout << "1. Sorting an unordered array" << endl;
            cout << "Part of the initial array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr1[i] << " ";
            }

            startTime = clock();
            bubbleSort(arr1, n1);
            endTime = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr1[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(endTime - startTime) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;

            startTime = 0;
            endTime = 0;
            cout << "2. Sorting an ordered array" << endl;
            cout << "Part of the initial array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr1[i] << " ";
            }

            startTime = clock();
            bubbleSort(arr1, n1);
            endTime = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr1[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(endTime - startTime) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;

            startTime = 0;
            endTime = 0;
            cout << "3. Sorting an array sorted in reverse order" << endl;
            cout << "Part of the initial array:" << endl;
            s = sizeof(arr1) / sizeof(arr1[0]);
            reverse(arr1, arr1 + s);
            for (int i = 0; i < n; i++) {
                cout << arr1[i] << " ";
            }

            startTime = clock();
            bubbleSort(arr1, n1);
            endTime = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr1[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(endTime - startTime) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;
            file.close();
            break;
        case '2':
            for (int i = 0; i < n2; i++) {
                file >> arr2[i];
            }
            startTime = 0;
            endTime = 0;

            cout << "----------------------------------------------------------------------" << endl;
            cout << "1. Sorting an unordered array" << endl;
            cout << "Part of the initial array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr2[i] << " ";
            }

            startTime = clock();
            bubbleSort(arr2, n2);
            endTime = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr2[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(endTime - startTime) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;

            startTime = 0;
            endTime = 0;
            cout << "2. Sorting an ordered array" << endl;
            cout << "Part of the initial array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr2[i] << " ";
            }

            startTime = clock();
            bubbleSort(arr2, n2);
            endTime = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr2[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(endTime - startTime) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;

            startTime = 0;
            endTime = 0;
            cout << "3. Sorting an array sorted in reverse order" << endl;
            cout << "Part of the initial array:" << endl;
            s = sizeof(arr2) / sizeof(arr2[0]);
            reverse(arr2, arr2 + s);
            for (int i = 0; i < n; i++) {
                cout << arr2[i] << " ";
            }

            startTime = clock();
            bubbleSort(arr2, n2);
            endTime = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr2[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(endTime - startTime) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;
            file.close();
            break;
        case '3':
            for (int i = 0; i < n3; i++) {
                file >> arr3[i];
            }
            startTime = 0;
            endTime = 0;

            cout << "----------------------------------------------------------------------" << endl;
            cout << "1. Sorting an unordered array" << endl;
            cout << "Part of the initial array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr3[i] << " ";
            }

            startTime = clock();
            bubbleSort(arr3, n3);
            endTime = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr3[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(endTime - startTime) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;

            startTime = 0;
            endTime = 0;
            cout << "2. Sorting an ordered array" << endl;
            cout << "Part of the initial array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr3[i] << " ";
            }

            startTime = clock();
            bubbleSort(arr3, n3);
            endTime = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr3[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(endTime - startTime) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;

            startTime = 0;
            endTime = 0;
            cout << "3. Sorting an array sorted in reverse order" << endl;
            cout << "Part of the initial array:" << endl;
            s = sizeof(arr3) / sizeof(arr3[0]);
            reverse(arr3, arr3 + s);
            for (int i = 0; i < n; i++) {
                cout << arr3[i] << " ";
            }

            startTime = clock();
            bubbleSort(arr3, n3);
            endTime = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr3[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(endTime - startTime) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;
            file.close();
            break;
        case '4':
            for (long i = 0; i < n4; i++) {
                file >> arr4[i];
            }
            startTime = 0;
            endTime = 0;

            cout << "----------------------------------------------------------------------" << endl;
            cout << "1. Sorting an unordered array" << endl;
            cout << "Part of the initial array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr4[i] << " ";
            }

            startTime = clock();
            bubbleSort(arr4, n4);
            endTime = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr4[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(endTime - startTime) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;

            startTime = 0;
            endTime = 0;
            cout << "2. Sorting an ordered array" << endl;
            cout << "Part of the initial array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr4[i] << " ";
            }
            startTime = clock();
            bubbleSort(arr4, n4);
            endTime = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr4[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(endTime - startTime) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;

            startTime = 0;
            endTime = 0;
            cout << "3. Sorting an array sorted in reverse order" << endl;
            cout << "Part of the initial array:" << endl;
            s = sizeof(arr4) / sizeof(arr4[0]);
            reverse(arr4, arr4 + s);
            for (int i = 0; i < n; i++) {
                cout << arr4[i] << " ";
            }

            startTime = clock();
            bubbleSort(arr4, n4);
            endTime = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr4[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(endTime - startTime) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;
            file.close();
            break;
        case '0':
            break;
        default:
            cout << "Invalide choice" << endl;
        }
    } while (menu != '0');
}