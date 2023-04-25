#include <iostream>
#include <windows.h>
using namespace std;

//// Линейная очередь
//class LinearQueue {
//private:
//    int front, rear, size;
//    int* arr;
//public:
//    LinearQueue(int s) {
//        front = rear = -1;
//        size = s;
//        arr = new int[size];
//    }
//    ~LinearQueue() {
//        delete[] arr;
//    }
//    bool isFull() {
//        return rear == size - 1;
//    }
//    bool isEmpty() {
//        return front == -1;
//    }
//    void enqueue(int x) {
//        if (isFull()) {
//            cout << "Очередь заполнена" << endl;
//        }
//        else {
//            if (front == -1) {
//                front = 0;
//            }
//            rear++;
//            arr[rear] = x;
//            cout << x << " поставлен в очередь" << endl;
//        }
//    }
//    void dequeue() {
//        if (isEmpty()) {
//            cout << "Очередь пуста" << endl;
//        }
//        else {
//            cout << arr[front] << " исключен из очереди" << endl;
//            front++;
//            if (front > rear) {
//                front = rear = -1;
//            }
//        }
//    }
//    void display() {
//        if (isEmpty()) {
//            cout << "Очередь пустая." << endl;
//        }
//        else {
//            cout << "Элементы очереди: ";
//            for (int i = front; i <= rear; i++) {
//                cout << arr[i] << " ";
//            }
//            cout << endl;
//        }
//    }
//};

// Циклическая очередь
class CircularQueue {
private:
    int front, rear, size;
    int* arr;
public:
    CircularQueue(int s) {
        front = rear = -1;
        size = s;
        arr = new int[size];
    }
    ~CircularQueue() {
        delete[] arr;
    }
    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear == front - 1);
    }
    bool isEmpty() {
        return front == -1;
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Очередь заполнена" << endl;
        }
        else {
            if (front == -1) {
                front = rear = 0;
            }
            else if (rear == size - 1 && front != 0) {
                rear = 0;
            }
            else {
                rear++;
            }
            arr[rear] = x;
            cout << x << " добавлен в очередь!\n" << endl;
        }
        
        cout << endl;
        system("pause");
        for (int i = 0; i < 60; i++) {
            cout << endl;
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "\nОчередь пуста." << endl;
        }
        else {
            cout << arr[front] << " исключен из очереди" << endl;
            if (front == rear) {
                front = rear = -1;
            }
            else if (front == size - 1) {
                front = 0;
            }
            else {
                front++;
            }
        }
        cout << endl;
        system("pause");
        for (int i = 0; i < 60; i++) {
            cout << endl;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Очередь пуста." << endl;
        }
        else {
            cout << "Элементы очереди: ";
            if (rear >= front) {
                for (int i = front; i <= rear; i++) {
                    cout << endl << arr[i] << " ";
                }
            }
            else {
                for (int i = front; i < size; i++) {
                    cout << endl << arr[i] << " ";
                }
                for (int i = 0; i <= rear; i++) {
                    cout << endl << arr[i] << " ";
                }
            }
            cout << endl << endl;
        }
        system("pause");
        for (int i = 0; i < 60; i++) {
            cout << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    int size;
    for (int i = 0; i < 60; i++) {
        cout << endl;
    }
    cout << "Введите размер очереди: ";
    cin >> size;

    //LinearQueue lq(size);
    CircularQueue cq(size);

    int choice, x;
    while (true) {
        cout << "\n1. Поставить элемент в очередь." << endl;
        cout << "2. Убрать элемент из очереди." << endl;
        cout << "3. Вывести всю очередь." << endl;
        cout << "4. Выйти." << endl;
        cout << "\nВыберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nВведите элемент для постановки в очередь: ";
            cin >> x;
            //lq.enqueue(x);
            cq.enqueue(x);
            break;
        case 2:
           // lq.dequeue();
            cq.dequeue();
            break;
        case 3:
            //lq.display();
            cq.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "\nОшибка. Неверное действие.\n\n";
        }
    }

    return 0;
}
