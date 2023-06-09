#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;
const int MAX = 100;

int minDistance(int dist[], bool visit[], int n) {
    int minDist = MAX;
    int minIndex = -1;
    for (int i = 1; i <= n; i++) {
        if (!visit[i] && dist[i] <= minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int matr[MAX][MAX], int a, int b, int n, int matrix1[MAX][MAX], int matrix2[MAX][MAX]) {
    int dist[MAX], vertex[MAX], transfer[MAX], count = 0;
    bool visited[MAX] = { false };
    for (int i = 1; i <= n; i++) {
        dist[i] = MAX;
    }
    dist[a] = 0;
    for (int i = 1; i <= n; i++) {
        int ind = minDistance(dist, visited, n);
        visited[ind] = true;
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && matr[ind][v] && dist[ind] != MAX && dist[ind] + matr[ind][v] < dist[v]) {
                dist[v] = dist[ind] + matr[ind][v];
                vertex[v] = ind;
            }
        }
    }
    cout << "Кратчайший путь из города " << a << " в город " << b << ": " << dist[b] << endl;

    int current = b;
    while (current != a) {
        transfer[count] = current;
        current = vertex[current];
        count++;
    }
    transfer[count] = a;

    cout << "Маршрут с пересадками: ";
    for (int i = count; i >= 0; i--) {
        cout << transfer[i];
        if (i > 0) {
            if (matrix1[transfer[i]][transfer[i - 1]] != 0 && matrix2[transfer[i]][transfer[i - 1]] == 0 || matrix1[transfer[i]][transfer[i - 1]] < matrix2[transfer[i]][transfer[i - 1]]) {
                cout << "(ш) ";
            }
            else if (matrix1[transfer[i]][transfer[i - 1]] == 0 && matrix2[transfer[i]][transfer[i - 1]] != 0 || matrix2[transfer[i]][transfer[i - 1]] < matrix1[transfer[i]][transfer[i - 1]]) {
                cout << "(ж) ";
            }
        }
    }
    cout << endl;
}

int main()
{
    SetConsoleOutputCP(1251);
    int n, a, b;
    int matrix1[MAX][MAX], matrix2[MAX][MAX], Matrix[MAX][MAX];

    ifstream file1("C:\\Data Structures\\pr2_3\\programm2_3 mat\\matrix1.txt");
    ifstream file2("C:\\Data Structures\\pr2_3\\programm2_3 mat\\matrix2.txt");
    if (!file1 || !file2) {
        cout << "Error opening";
        return 0;
    }
    file1 >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            file1 >> matrix1[i][j];
        }
    }
    file1.close();
    file2 >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            file2 >> matrix2[i][j];
        }
    }
    file2.close();

    cout << "---------------------------" << endl;
    cout << "Система шоссейних дорог: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------------" << endl;
    cout << "Система железных дорог: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------------" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix1[i][j] == 0 && matrix2[i][j] != 0) {
                Matrix[i][j] = matrix2[i][j];
            }
            else if (matrix1[i][j] != 0 && matrix2[i][j] == 0) {
                Matrix[i][j] = matrix1[i][j];
            }
            else if (matrix1[i][j] == 0 && matrix2[i][j] == 0) {
                Matrix[i][j] = 0;
            }
            else {
                Matrix[i][j] = min(matrix1[i][j], matrix2[i][j]);
            }
        }
    }
    cout << "Общая система всех дорог: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------------" << endl;

    do {
        cout << "Введите номер города, из которого надо найти путь (от 1 до " << n << "): ";
        cin >> a;
        if (a < 1 || a > n) {
            cout << "Город не найден" << endl;
        }
    } while (a < 1 || a > n);
    do {
        cout << "Введите номер города, до которого надо найти путь (от 1 до " << n << "): ";
        cin >> b;
        if (b < 1 || b > n) {
            cout << "Город не найден" << endl;
        }
    } while (b < 1 || b > n);
    dijkstra(Matrix, a, b, n, matrix1, matrix2);
}