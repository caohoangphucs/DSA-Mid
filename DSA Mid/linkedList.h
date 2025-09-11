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


template <typename T>

struct DoubleLinkedlist {
	DNode<T>* Head = nullptr;
	DNode<T>* Tail = nullptr;
	//kiểm tra rỗng 
	bool isEmpty() {
		return Head == nullptr;
	}
	int getSize() {
		int size = 0;
		DNode<T>* cur = Head;
		while (cur) {
			size++;
			cur = cur->next;
		}
		return size;
	}
	// Lấy giá trị tại index
	T getValue(int ind) {
		DNode<T>* cur = Head;
		if (ind < 0) throw out_of_range("Index out of range");
		for (int i = 0; i < ind; i++) {
			if (!cur) throw out_of_range("Index out of range");
			cur = cur->next;
		}
		if (!cur) throw out_of_range("Index out of range");
		return cur->data;
	}
	// Chèn node vào đầu
	void insertHead(const T& value) {
		DNode<T>* newNode = new DNode<T>(value);
		if (!Head) { // danh sách rỗng
			Head = Tail = newNode;
		}
		else {
			newNode->next = Head;
			Head->prev = newNode;
			Head = newNode;
		}
	}
	//Thêm node vào cuối
	void add(const T& value) {
		DNode <T>* newNode = new DNode<T>(value);
		if (!Head) {
			Head = Tail = newNode;
		}
		else {
			Tail->next = newNode;
			newNode->prev = Tail;
			Tail = newNode;
		}
	}
	//Chèn node vào cuối
	void insertTail(const T& value) {
		add(value);
	}

	// Chèn vào vị trí index
	void insert(const T& value, int index) {
		if (index == 0) {
			insertHead(value);
			return;
		}
		DNode<T>* cur = Head;
		for (int i = 0; cur && i < index - 1; i++) {
			cur = cur->next;
		}
		if (!cur) throw out_of_range("Index out of range");
		DNode<T>* newNode = new DNode<T>(value);
		newNode->next = cur->next;
		newNode->prev = cur;
		cur->next = newNode;
		if (!(newNode->next)) Tail = newNode;
		else newNode->next->prev = newNode;
	}
	// xóa node tại index
	void removeAt(int index) {
		if (!Head) return;
		if (index < 0) throw out_of_range("Index out of range");
		if (index == 0) {
			DNode<T>* tmp = Head;
			Head = Head->next;
			if (Head) Head->prev = nullptr;
			if (tmp == Tail) Tail = nullptr;
			delete tmp;
			return;
		}
		DNode<T>* cur = Head;
		for (int i = 0; cur && i < index; i++) {
			cur = cur->next;
		}
		if (!cur) throw out_of_range("Index out of range");
		if (cur->prev) cur->prev->next = cur->next;
		if (cur->next) cur->next->prev = cur->prev;
		if (cur == Tail) Tail = cur->prev;
		delete cur;
	}
	//xóa tất cả node có giá trị value
	void removeAll(const T& value) {
		while (Head && Head->data == value) {
			DNode<T>* temp = Head;
			Head = Head->next;
			if (Head) Head->prev = nullptr;
			delete temp;
		}
		DNode<T>* cur = Head;
		while (cur) {
			if (cur->data == value) {
				DNode<T>* temp = cur;
				if (cur->prev) cur->prev->next = cur->next;
				if (cur->next) cur->next->prev = cur->prev;
				if (cur == Tail) Tail = cur->prev;
				cur = cur->next;
				delete temp;
			}
			else {
				cur = cur->next;
			}
		}
	}
	// Xóa node
	void remove(DNode<T>* node) {
		if (!node || !Head) return;
		if (node == Head) {
			DNode<T>* temp = Head;
			Head = Head->next;
			if (Head) Head->prev = nullptr;
			if (temp == Tail) Tail = nullptr;
			delete temp;
			return;
		}
		if (node == Tail) {
			DNode<T>* temp = Tail;
			Tail = Tail->prev;
			if (Tail) Tail->next = nullptr;
			if (temp == Head) Head = nullptr;
			delete temp;
			return;
		}
		if (node->prev) node->prev->next = node->next;
		if (node->next) node->next->prev = node->prev;
		delete node;
	}
	// Thêm nhiều node
	void addRange(const vector<T>& vs) {
		for (auto v : vs) add(v);
	}
	// Xóa tất cả các node
	void clear() {
		DNode<T>* cur = Head;
		while (cur) {
			DNode<T>* temp = cur;
			cur = cur->next;
			delete temp;
		}
		Head = Tail = nullptr;
	}
	// Lấy node tại index
	DNode<T>* getNode(int ind) {
		if (ind < 0) throw out_of_range("Index out of range");
		DNode<T>* cur = Head;
		for (int i = 0; cur && i < ind; i++) {
			cur = cur->next;
		}

		if (!cur) throw out_of_range("Index out of range");
		return cur;
	}
	// Chèn sau node
	void insertAfter(const T& value, DNode<T>* node) {
		if (!node) return;
		DNode<T>* newNode = new DNode<T>(value);
		newNode->next = node->next;
		newNode->prev = node;
		node->next = newNode;
		if (newNode->next) newNode->next->prev = newNode;
		else Tail = newNode;
	}
	// Chèn trước node
	void insertBefore(const T& value, DNode<T>* node) {
		if (!node) return;
		DNode<T>* newNode = new DNode<T>(value);
		newNode->next = node;

		newNode->prev = node->prev;
		if (newNode->prev)newNode->prev->next = newNode;
		else {
			Head = newNode;
		}
		node->prev = newNode;
	}

	void print() {
		DNode<T>* cur = Head;
		while (cur) {
			cout << cur->data << ", ";
			cur = cur->next;
		}
		cout << endl;
	}

};
