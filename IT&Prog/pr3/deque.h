#include <iostream>

using namespace std;

//узел двусвязного списка
template <typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;
};

//класс дек
template <typename T>
class Deque {
    Node<T>* front;
    Node<T>* rear;
    int size;

public:
    //конструктор
    Deque(int max_size) {
        front = rear = NULL;
        size = 0;
    }

    //конструктор копирования
    Deque(const Deque& other) {
        front = rear = NULL;
        size = 0;
        Node<T>* current = other.front;
        while (current != NULL) {
            pushRear(current->data);
            current = current->next;
        }
    }

    //добавление элемента в начало
    void pushFront(T data) {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = front;

        if (isEmpty()) {
            rear = newNode;
        }
        else {
            front->prev = newNode;
        }
        front = newNode;
        size++;
    }

    //удаления элемента из начала
    void popFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        Node<T>* temp = front;

        if (front == rear) {
            front = rear = NULL;
        }
        else {
            front = front->next;
            front->prev = NULL;
        }

        delete temp;
        size--;
    }

    //добавления элемента в конец
    void pushRear(T data) {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->prev = rear;
        newNode->next = NULL;

        if (isEmpty()) {
            front = newNode;
        }
        else {
            rear->next = newNode;
        }
        rear = newNode;
        size++;
    }

    //удаления элемента из конца
    void popRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        Node<T>* temp = rear;

        if (front == rear) {
            front = rear = NULL;
        }
        else {
            rear = rear->prev;
            rear->next = NULL;
        }

        delete temp;
        size--;
    }

    //получения первого элемента
    T getFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return T();
        }
        return front->data;
    }

    //получения последнего элемента
    T getRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return T();
        }
        return rear->data;
    }

    //проверки, пустой ли дек
    bool isEmpty() {
        return front == NULL;
    }

    //получения размера дека
    int getSize() {
        return size;
    }

    //перегруженный оператор присваивания
    Deque<T>& operator=(const Deque& other) {
        if (this != &other) { //проверяем, что не присваиваем объект самому себе
            //удаляем все элементы текущего дека
            while (!isEmpty()) {
                popFront();
            }

            //копируем элементы из другого дека
            Node<T>* current = other.front;
            while (current != NULL) {
                pushRear(current->data);
                current = current->next;
            }
        }
        return *this;
    }
};