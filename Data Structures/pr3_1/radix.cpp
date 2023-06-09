#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>

using namespace std;

const int n = 10, n1 = 10000, n2 = 30000, n3 = 70000, n4 = 100000;
unsigned long int cntMain, cntAux;
long memory;

void countingSort(long arr[], int n, int exp) {
    int *output = new int[n], count[10] = { 0 };
    int i;
    for (cntAux++, i = 0; i < n; cntAux++, i++) {
        count[(arr[i] / exp) % 10]++;
        cntAux++;
    }

    for (cntAux++, i = 1; i < 10; cntAux++, i++) {
        count[i] += count[i - 1];
        cntAux++;
    }

    for (cntAux++, i = n - 1; i >= 0; cntAux++, i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        cntAux += 2;
    }

    for (cntAux++, i = 0; i < n; cntAux++, i++) {
        arr[i] = output[i];
        cntMain++;
    }
    delete[] output;
}

void radixSort(long arr[], int n) {
    cntAux = 0;
    cntMain = 0;
    int maxValue = arr[0], i, exp;
    memory = 3 * sizeof(int);
    for (cntAux++, i = 1; i < n; cntAux++, i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            cntAux++;
        }
    }

    for (cntAux++, exp = 1; maxValue / exp > 0;cntAux++, exp *= 10) {
        countingSort(arr, n, exp);
    }
    memory += (n + 11) * sizeof(int);
}

int main() {
    long arr1[n1], arr2[n2], arr3[n3], arr4[n4], s = 0;
    char menu;
    clock_t start;
    clock_t end;

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
            start = 0;
            end = 0;

            cout << "----------------------------------------------------------------------" << endl;
            cout << "1. Sorting an unordered array" << endl;
            cout << "Part of the initial array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr1[i] << " ";
            }

            start = clock();
            radixSort(arr1, n1);
            end = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr1[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(end - start) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of main assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;

            start = 0;
            end = 0;
            cout << "2. Sorting an ordered array" << endl;
            cout << "Part of the initial array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr1[i] << " ";
            }

            start = clock();
            radixSort(arr1, n1);
            end = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr1[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(end - start) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of main assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;

            start = 0;
            end = 0;
            cout << "3. Sorting an array sorted in reverse order" << endl;
            cout << "Part of the initial array:" << endl;
            s = sizeof(arr1) / sizeof(arr1[0]);
            reverse(arr1, arr1 + s);
            for (int i = 0; i < n; i++) {
                cout << arr1[i] << " ";
            }

            start = clock();
            radixSort(arr1, n1);
            end = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr1[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(end - start) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of main assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;
            file.close();
            break;
        case '2':
            for (int i = 0; i < n2; i++) {
                file >> arr2[i];
            }
            start = 0;
            end = 0;

            cout << "----------------------------------------------------------------------" << endl;
            cout << "1. Sorting an unordered array" << endl;
            cout << "Part of the initial array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr2[i] << " ";
            }

            start = clock();
            radixSort(arr2, n2);
            end = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr2[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(end - start) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of main assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;

            start = 0;
            end = 0;
            cout << "2. Sorting an ordered array" << endl;
            cout << "Part of the initial array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr2[i] << " ";
            }

            start = clock();
            radixSort(arr2, n2);
            end = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr2[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(end - start) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of main assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;

            start = 0;
            end = 0;
            cout << "3. Sorting an array sorted in reverse order" << endl;
            cout << "Part of the initial array:" << endl;
            s = sizeof(arr2) / sizeof(arr2[0]);
            reverse(arr2, arr2 + s);
            for (int i = 0; i < n; i++) {
                cout << arr2[i] << " ";
            }

            start = clock();
            radixSort(arr2, n2);
            end = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr2[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(end - start) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of main assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;
            file.close();
            break;
        case '3':
            for (long i = 0; i < n3; i++) {
                file >> arr3[i];
            }
            start = 0;
            end = 0;

            cout << "----------------------------------------------------------------------" << endl;
            cout << "1. Sorting an unordered array" << endl;
            cout << "Part of the initial array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr3[i] << " ";
            }

            start = clock();
            radixSort(arr3, n3);
            end = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr3[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(end - start) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of main assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;

            start = 0;
            end = 0;
            cout << "2. Sorting an ordered array" << endl;
            cout << "Part of the initial array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr3[i] << " ";
            }

            start = clock();
            radixSort(arr3, n3);
            end = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr3[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(end - start) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of main assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;

            start = 0;
            end = 0;
            cout << "3. Sorting an array sorted in reverse order" << endl;
            cout << "Part of the initial array:" << endl;
            s = sizeof(arr3) / sizeof(arr3[0]);
            reverse(arr3, arr3 + s);
            for (int i = 0; i < n; i++) {
                cout << arr3[i] << " ";
            }

            start = clock();
            radixSort(arr3, n3);
            end = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr3[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(end - start) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of main assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;
            file.close();
            break;
        case '4':
            for (long i = 0; i < n4; i++) {
                file >> arr4[i];
            }
            start = 0;
            end = 0;

            cout << "----------------------------------------------------------------------" << endl;
            cout << "1. Sorting an unordered array" << endl;
            cout << "Part of the initial array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr4[i] << " ";
            }

            start = clock();
            radixSort(arr4, n4);
            end = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr4[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(end - start) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of main assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;

            start = 0;
            end = 0;
            cout << "2. Sorting an ordered array" << endl;
            cout << "Part of the initial array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr4[i] << " ";
            }

            start = clock();
            radixSort(arr4, n4);
            end = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr4[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(end - start) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of main assignments: " << cntMain << endl;
            cout << "Number of auxiliary assignments: " << cntAux << endl;
            cout << "----------------------------------------------------------------------" << endl;

            start = 0;
            end = 0;
            cout << "3. Sorting an array sorted in reverse order" << endl;
            cout << "Part of the initial array:" << endl;
            s = sizeof(arr4) / sizeof(arr4[0]);
            reverse(arr4, arr4 + s);
            for (int i = 0; i < n; i++) {
                cout << arr4[i] << " ";
            }

            start = clock();
            radixSort(arr4, n4);
            end = clock();

            cout << "\n\nPart of the resulting array:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr4[i] << " ";
            }
            cout << endl;

            cout << "\nAdditional memory used: " << memory << " bytes." << endl;
            cout << "Time taken by program is : ";
            cout << double(end - start) / CLOCKS_PER_SEC;
            cout << " sec " << endl;
            cout << "Number of main assignments: " << cntMain << endl;
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