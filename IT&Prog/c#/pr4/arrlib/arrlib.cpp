#include "arrlib.h"
#include "pch.h"

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

extern "C" __declspec(dllexport) double* fillArray() {
    srand(static_cast<double>(time(nullptr)));

    double* array = new double[50];
    double min = -500.0, max = 500.0;

    for (int i = 0; i < 50; i++) {
        double randomValue = (static_cast<double>(rand()) / RAND_MAX) * (max - min) + min;
        array[i] = randomValue;
    }

    return array;
}

extern "C" __declspec(dllexport) void deleteArr(double* arr) {
    delete[] arr;
}

extern "C" __declspec(dllexport) void outputArray(double* arr) {
    for (int i = 0; i < 50; i++) {
        cout << i + 1 << ". " << fixed << arr[i] << endl;
    }
}

extern "C" __declspec(dllexport) void sumAbs(double* arr) {

    double sumP = 0, sumN = 0, dif;

    for (int i = 0; i < 50; i++) {
        double num = arr[i];
        if (num < 0) {
            sumN += num;
        }
        else {
            sumP += num;
        }
    }

    cout << "sum of negative numbers: " << sumN << endl;
    cout << "sum of positive numbers: " << sumP << endl;

    dif = fabs(sumN) - sumP;
    cout << "module difference: " << dif << endl;
}