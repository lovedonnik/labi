#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <ctime>

using namespace std;

void generateNumbersToFile(const string& fileName, int numCount) {
    ofstream out(fileName);
    if (out.is_open()) {
        for (int i = 0; i < numCount; i++) {
            out << rand() << endl;
        }
    }
    else {
        cout << "Не удалось создать файл " << fileName << endl;
    }
}

void readNumbersFromFile(const string& fileName, int numCount, int* numbers) {
    ifstream in(fileName);
    if (in.is_open()) {
        for (int i = 0; i < numCount && !in.eof(); i++) {
            in >> numbers[i];
        }
    }
    else {
        cout << "Не удалось открыть файл " << fileName << endl;
    }
}

void bubbleSort(int* numbers, int numCount) {
    int tmp;
    for (int i = 0; i < numCount; i++) {
        for (int j = 0; j < numCount - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                tmp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = tmp;
            }
        }
    }
}

void selectionSort(int* numbers, int numCount) {
    int tmp;
    for (int i = 0; i < numCount; i++) {
        int min_index = i;
        for (int j = i + 1; j < numCount; j++) {
            if (numbers[j] < numbers[min_index]) {
                min_index = j;
            }
        }
        tmp = numbers[i];
        numbers[i] = numbers[min_index];
        numbers[min_index] = tmp;
    }
}

void insertionSort(int* numbers, int numCount) {
    int key, j;
    for (int i = 1; i < numCount; i++) {
        key = numbers[i];
        j = i - 1;

        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }
        numbers[j + 1] = key;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    const int numCount = 100000;
    int numbers[numCount];

    // Генерация 100.000 чисел в файл.
    generateNumbersToFile("input.txt", numCount);

    // Сортировка из файла в одномерный массив.
    readNumbersFromFile("input.txt", numCount, numbers);

    // Сортировка пузырьком
    clock_t start = clock();
    bubbleSort(numbers, numCount);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "Время сортировки пузырьком: " << seconds << endl;

    ofstream Bubble("Bubble.txt");
    for (int i = 0; i < numCount; i++) {
        Bubble << numbers[i] << endl;
    }

    // Сортировка выбором
    start = clock();
    selectionSort(numbers, numCount);
    end = clock();
    double seconds1 = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "Время сортировки выбором: " << seconds1 << endl;

    ofstream Selection("Selection.txt");
    for (int i = 0; i < numCount; i++) {
        Selection << numbers[i] << endl;
    }

    // Сортировка вставками
    start = clock();
    insertionSort(numbers, numCount);
    end = clock();
    double seconds2 = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "Время сортировки вставками: " << seconds2 << endl;

    ofstream Insertion("Insertion.txt");
    for (int i = 0; i < numCount; i++) {
        Insertion << numbers[i] << endl;
    }
}
