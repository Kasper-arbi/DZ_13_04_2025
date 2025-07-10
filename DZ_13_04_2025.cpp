#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

// Задание 1: Проверка треугольника
void task1() {
    double a, b, c;
    cout << "Задание 1: Проверка треугольника\n";
    cout << "Введите три стороны треугольника: ";
    cin >> a >> b >> c;

    
    if (a + b > c && a + c > b && b + c > a) {
        cout << "Треугольник существует.\n";

       
        if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
            cout << "Треугольник прямоугольный.\n";
        }
        else {
            cout << "Треугольник не прямоугольный.\n";
        }
    }
    else {
        cout << "Треугольник не существует.\n";
    }
    cout << endl;
}

// Задание 2: Сумма чисел, кратных 3 и 5
void task2() {
    int N;
    cout << "Задание 2: Сумма чисел, кратных 3 и 5\n";
    cout << "Введите число N: ";
    cin >> N;

    int sum = 0;
    for (int i = 1; i < N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    cout << "Сумма: " << sum << endl << endl;
}

// Задание 3: Медиана массива
void task3() {
    int size;
    cout << "Задание 3: Медиана массива\n";
    cout << "Введите размер массива: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    double median;
    if (size % 2 == 0) {
        median = (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }
    else {
        median = arr[size / 2];
    }

    cout << "Медиана: " << median << endl << endl;
}

// Задание 4: Шифр Цезаря
void task4() {
    cout << "Задание 4: Шифр Цезаря\n";

    ifstream in("input.txt");
    ofstream out("output.txt");
    int key = 3; // Сдвиг для шифра Цезаря

    if (!in) {
        cout << "Ошибка открытия файла input.txt\n\n";
        return;
    }

    string line;
    while (getline(in, line)) {
        for (char& c : line) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                c = base + (c - base + key) % 26;
            }
        }
        out << line << endl;
    }

    in.close();
    out.close();
    cout << "Шифрование завершено. Результат в output.txt\n\n";
}

// Задание 5: Удаление столбца из матрицы
void task5() {
    cout << "Задание 5: Удаление столбца из матрицы\n";

    const int ROWS = 3, COLS = 4;
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int col_to_delete;
    cout << "Исходная матрица:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Введите номер столбца для удаления (0-" << COLS - 1 << "): ";
    cin >> col_to_delete;

    if (col_to_delete < 0 || col_to_delete >= COLS) {
        cout << "Неверный номер столбца!\n\n";
        return;
    }

    cout << "Матрица после удаления столбца:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (j != col_to_delete) {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    task1();
    task2();
    task3();
    task4();
    task5();

    

    
}