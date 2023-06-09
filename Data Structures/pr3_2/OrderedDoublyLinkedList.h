#include <iostream>

using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

class ODLList {
private:
    node* begin;
    node* end;

public:
    ODLList() { //конструктор
        begin = nullptr;
        end = nullptr;
    }

    ODLList(const ODLList& other) { //конструктор копирования
        begin = nullptr;
        end = nullptr;

        //если список, который копируется, не пустой
        if (other.begin != nullptr) {
            //копируем первый элемент
            node* current = other.begin;
            node* newNode = new node;
            newNode->data = current->data;
            newNode->prev = nullptr;
            newNode->next = nullptr;

            begin = newNode;
            end = newNode;

            //копируем остальные элементы
            current = current->next;
            while (current != nullptr) {
                node* newNode = new node;
                newNode->data = current->data;
                newNode->prev = end;
                newNode->next = nullptr;

                end->next = newNode;
                end = newNode;
                current = current->next;
            }
        }
    }

    ODLList& operator=(const ODLList& other) { //перегруженный оператор присваивания
        //проверяем на самоприсваивание
        if (this == &other) {
            return *this;
        }

        //очищаем текущий список
        node* current = begin;
        while (current != nullptr) {
            node* next = current->next;
            delete current;
            current = next;
        }
        begin = nullptr;
        end = nullptr;

        //если список, который копируется, не пустой
        if (other.begin != nullptr) {
            //копируем первый элемент
            current = other.begin;
            node* newNode = new node;
            newNode->data = current->data;
            newNode->prev = nullptr;
            newNode->next = nullptr;

            begin = newNode;
            end = newNode;

            //копируем остальные элементы
            current = current->next;
            while (current != nullptr) {
                newNode = new node;
                newNode->data = current->data;
                newNode->prev = end;
                newNode->next = nullptr;

                end->next = newNode;
                end = newNode;
                current = current->next;
            }
        }

        return *this;
    }

    void insert_sorted(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (begin == nullptr) {
            //если список пустой, устанавливаем новый элемент как начало и конец списка
            begin = newNode;
            end = newNode;
        }
        else if (value <= begin->data) {
            //если значение нового элемента меньше или равно значению первого элемента,
            //вставляем новый элемент в начало списка
            newNode->next = begin;
            begin->prev = newNode;
            begin = newNode;
        }
        else if (value >= end->data) {
            //если значение нового элемента больше или равно значению последнего элемента,
            //вставляем новый элемент в конец списка
            newNode->prev = end;
            end->next = newNode;
            end = newNode;
        }
        else {
            //ищем правильное место для вставки нового элемента
            node* current = begin;

            while (current != nullptr && current->data < value) {
                current = current->next;
            }

            //вставка нового элемента между двумя существующими элементами
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
    }

    void delete_begin() {
        if (begin == nullptr) {
            //список пустой, ничего не делаем
            return;
        }

        node* toDelete = begin;

        if (begin == end) {
            //список содержит только один элемент
            begin = nullptr;
            end = nullptr;
        }
        else {
            begin = begin->next;
            begin->prev = nullptr;
        }

        delete toDelete;
    }

    void delete_end() {
        if (end == nullptr) {
            //список пустой, ничего не делаем
            return;
        }

        node* toDelete = end;

        if (begin == end) {
            //список содержит только один элемент
            begin = nullptr;
            end = nullptr;
        }
        else {
            end = end->prev;
            end->next = nullptr;
        }
        delete toDelete;
    }

    void delete_el(int key) {
        node* current = begin;

        while (current != nullptr) {
            if (current->data == key) {
                //найден элемент с заданным ключом
                if (current == begin) {
                    //удаляемый элемент является первым элементом списка
                    begin = current->next;
                    if (begin != nullptr) {
                        begin->prev = nullptr;
                    }
                    else {
                        end = nullptr;
                    }
                }
                else if (current == end) {
                    //удаляемый элемент является последним элементом списка
                    end = current->prev;
                    end->next = nullptr;
                }
                else {
                    //удаляемый элемент находится между двумя элементами списка
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                break;
            }
            current = current->next;
        }
    }

    node* getBegin() const {
        return begin;
    }

    void print() const {
        node* current = begin;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_back() const {
        node* current = end;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};