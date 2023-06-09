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
    ODLList() { //�����������
        begin = nullptr;
        end = nullptr;
    }

    ODLList(const ODLList& other) { //����������� �����������
        begin = nullptr;
        end = nullptr;

        //���� ������, ������� ����������, �� ������
        if (other.begin != nullptr) {
            //�������� ������ �������
            node* current = other.begin;
            node* newNode = new node;
            newNode->data = current->data;
            newNode->prev = nullptr;
            newNode->next = nullptr;

            begin = newNode;
            end = newNode;

            //�������� ��������� ��������
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

    ODLList& operator=(const ODLList& other) { //������������� �������� ������������
        //��������� �� ����������������
        if (this == &other) {
            return *this;
        }

        //������� ������� ������
        node* current = begin;
        while (current != nullptr) {
            node* next = current->next;
            delete current;
            current = next;
        }
        begin = nullptr;
        end = nullptr;

        //���� ������, ������� ����������, �� ������
        if (other.begin != nullptr) {
            //�������� ������ �������
            current = other.begin;
            node* newNode = new node;
            newNode->data = current->data;
            newNode->prev = nullptr;
            newNode->next = nullptr;

            begin = newNode;
            end = newNode;

            //�������� ��������� ��������
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
            //���� ������ ������, ������������� ����� ������� ��� ������ � ����� ������
            begin = newNode;
            end = newNode;
        }
        else if (value <= begin->data) {
            //���� �������� ������ �������� ������ ��� ����� �������� ������� ��������,
            //��������� ����� ������� � ������ ������
            newNode->next = begin;
            begin->prev = newNode;
            begin = newNode;
        }
        else if (value >= end->data) {
            //���� �������� ������ �������� ������ ��� ����� �������� ���������� ��������,
            //��������� ����� ������� � ����� ������
            newNode->prev = end;
            end->next = newNode;
            end = newNode;
        }
        else {
            //���� ���������� ����� ��� ������� ������ ��������
            node* current = begin;

            while (current != nullptr && current->data < value) {
                current = current->next;
            }

            //������� ������ �������� ����� ����� ������������� ����������
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
    }

    void delete_begin() {
        if (begin == nullptr) {
            //������ ������, ������ �� ������
            return;
        }

        node* toDelete = begin;

        if (begin == end) {
            //������ �������� ������ ���� �������
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
            //������ ������, ������ �� ������
            return;
        }

        node* toDelete = end;

        if (begin == end) {
            //������ �������� ������ ���� �������
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
                //������ ������� � �������� ������
                if (current == begin) {
                    //��������� ������� �������� ������ ��������� ������
                    begin = current->next;
                    if (begin != nullptr) {
                        begin->prev = nullptr;
                    }
                    else {
                        end = nullptr;
                    }
                }
                else if (current == end) {
                    //��������� ������� �������� ��������� ��������� ������
                    end = current->prev;
                    end->next = nullptr;
                }
                else {
                    //��������� ������� ��������� ����� ����� ���������� ������
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