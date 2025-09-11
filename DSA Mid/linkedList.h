#pragma once
#include "Node.h"
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
struct SinglyLinkedList {
    Node<T>* Head = nullptr;
    Node<T>* Tail = nullptr;

    // Lấy giá trị tại index
    T getValue(int ind) {
        Node<T>* curNode = Head;
        for (int i = 0; i < ind; i++) {
            if (!curNode) throw out_of_range("Index out of range");
            curNode = curNode->next;
        }
        return curNode->data;
    }

    // Thêm node vào cuối
    void add(const T& v) {
        Node<T>* newNode = new Node<T>(v);
        if (!Head) {
            Head = Tail = newNode;
        }
        else {
            Tail->next = newNode;
            Tail = newNode;
        }
    }

    // Chèn vào vị trí index
    void insert(const T& v, int ind) {
        if (ind == 0) {
            insertHead(v);
            return;
        }

        Node<T>* cur = Head;
        for (int i = 0; cur && i < ind - 1; i++) {
            cur = cur->next;
        }
        if (!cur) throw out_of_range("Index out of range");

        Node<T>* newNode = new Node<T>(v);
        newNode->next = cur->next;
        cur->next = newNode;
        if (newNode->next == nullptr) Tail = newNode;
    }

    // In danh sách
    void print() {
        Node<T>* curNode = Head;
        while (curNode) {
            cout << curNode->data << ", ";
            curNode = curNode->next;
        }
        cout << "\n";
    }

    // --- Homework functions ---

    int getSize() {
        int size = 0;
        Node<T>* curNode = Head;
        while (curNode) {
            size++;
            curNode = curNode->next;
        }
        return size;
    }

    void removeAt(int ind) {
        if (!Head) return;

        if (ind == 0) {
            Node<T>* temp = Head;
            Head = Head->next;
            if (!Head) Tail = nullptr;
            delete temp;
            return;
        }

        Node<T>* cur = Head;
        for (int i = 0; cur && cur->next; i++) {
            if (i == ind - 1) {
                Node<T>* temp = cur->next;
                cur->next = temp->next;
                if (temp == Tail) Tail = cur;
                delete temp;
                return;
            }
            cur = cur->next;
        }
    }

    void removeAll(const T& v) {
        while (Head && Head->data == v) {
            Node<T>* temp = Head;
            Head = Head->next;
            delete temp;
        }

        Node<T>* cur = Head;
        while (cur && cur->next) {
            if (cur->next->data == v) {
                Node<T>* temp = cur->next;
                cur->next = temp->next;
                if (temp == Tail) Tail = cur;
                delete temp;
            }
            else {
                cur = cur->next;
            }
        }
    }

    void addRange(const vector<T>& vs) {
        for (auto v : vs) add(v);
    }

    void clear() {
        Node<T>* cur = Head;
        while (cur) {
            Node<T>* temp = cur;
            cur = cur->next;
            delete temp;
        }
        Head = Tail = nullptr;
    }

    Node<T>* getNode(int ind) {
        int curInd = 0;
        Node<T>* cur = Head;
        while (cur && curInd < ind) {
            cur = cur->next;
            curInd++;
        }
        if (!cur) throw out_of_range("Index out of range");
        return cur;
    }

    void insert(const T& v, Node<T>* varNode) {
        if (!varNode) return;
        Node<T>* newNode = new Node<T>(v);
        newNode->next = varNode->next;
        varNode->next = newNode;
        if (newNode->next == nullptr) Tail = newNode;
    }

    void remove(Node<T>* varNode) {
        if (!Head || !varNode) return;

        if (varNode == Head) {
            Head = Head->next;
            if (Tail == varNode) Tail = Head;
            delete varNode;
            return;
        }

        Node<T>* cur = Head;
        while (cur && cur->next != varNode) {
            cur = cur->next;
        }

        if (cur && cur->next == varNode) {
            cur->next = varNode->next;
            if (varNode == Tail) Tail = cur;
            delete varNode;
        }
    }

    void insertHead(const T& v) {
        Node<T>* newNode = new Node<T>(v);
        newNode->next = Head;
        Head = newNode;
        if (!Tail) Tail = Head;
    }

    void insertTail(const T& v) {
        Node<T>* newNode = new Node<T>(v);
        if (!Head) {
            Head = Tail = newNode;
        }
        else {
            Tail->next = newNode;
            Tail = newNode;
        }
    }
};
