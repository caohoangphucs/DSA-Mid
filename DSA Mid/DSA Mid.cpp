#include <iostream>
#include "searchTree.h"
#include "linkedList.h"
#include "hashTable.h"
#include <cstdlib>
using namespace std;

string temp;

#include <iostream>
#include <string>
using namespace std;

void testSearchTree() {
    cout << "=== Test Search Tree ===" << endl;
    BinarySearchTree<int> tree;
    string temp;

    try {
        cout << "Adding values: 10, 5, 15, 12, 20...\n";
        tree.addValue(10);
        tree.addValue(5);
        tree.addValue(15);
        tree.addValue(12);
        tree.addValue(20);

        cout << "In-order traversal: ";
        tree.printInOrder(tree.root);
        cout << endl;

        cout << "Check existence: \n";
        cout << "Has 12? " << (tree.has(12) ? "Yes" : "No") << endl;
        cout << "Has 7? " << (tree.has(7) ? "Yes" : "No") << endl;

        cout << "\nRemove leaf (20)...\n";
        tree.removeValue(20);
        tree.printInOrder(tree.root);
        cout << endl;

        tree.addValue(20);
        cout << "\nRemove node with 1 child (15)...\n";
        tree.removeValue(15);
        tree.printInOrder(tree.root);
        cout << endl;

        cout << "\nRemove node with 2 children (10)...\n";
        tree.removeValue(10);
        tree.printInOrder(tree.root);
        cout << endl;

        cout << "\nClearing tree...\n";
        tree.clear();
    }
    catch (const exception& e) {
        cerr << "[Exception caught] " << e.what() << endl;
    }

    // dừng màn hình chờ nhập Enter
    getline(cin, temp);
    system("cls");
}


void testDoubleLinkedlist() {
    cout << "=== Test Double Linked List ===" << endl;
    DoubleLinkedlist<int> list;
    try {

        cout << "Adding values 1,  3...\n";
        list.add(1);
        list.add(3);
        cout << "Insert 2 at index 1\n";
        list.insert(2, 1);

        cout << "Insert head (0) and tail (4)...\n";
        list.insertHead(0);
        list.insertTail(4);

        cout << "Current list: ";
        for (int i = 0; i < list.getSize(); i++) {
            cout << list.getValue(i) << ", ";
        }
        cout << endl;

        cout << "Clear list, then add range {5,6,7,8}...\n";
        list.clear();
		int a[] = { 5,6,7,8 };
		int n = sizeof(a) / sizeof(a[0]);
        list.addRange(a, n);
        list.print();

        cout << "InsertAfter(9, node(3))...\n";
        list.insertAfter(9, list.getNode(3)); // 5 6 7 8 9
        list.print();
        cout << "Remove(node(3))...\n";
        list.remove(list.getNode(3));

        cout << "InsertBefore(4, node(0))...\n";
        list.insertBefore(4, list.getNode(0));
        list.print();

        cout << "RemoveAt(2)...\n";
        list.removeAt(2); // remove index 2
        list.print();

        cout << "Add(9)...\n";
        list.add(9);
        list.print();

        cout << "RemoveAll(9)...\n";
        list.removeAll(9);
        list.print();
    }catch (const exception& e) {
        cerr << "[Exception caught] " << e.what() << endl;
	}

    getline(cin, temp);
    system("cls");
}

void testSinglyLinkedList() {
    cout << "=== Test Singly Linked List ===" << endl;
    SinglyLinkedList<int> list;
try{
    cout << "Adding 10, 20...\n";
    list.add(10);
    list.add(20);

    cout << "InsertHead(5), InsertTail(30)...\n";
    list.insertHead(5);
    list.insertTail(30);

    cout << "Current list: ";
    list.print();

    cout << "RemoveAt(1)...\n";
    list.removeAt(1);
    list.print();

    cout << "RemoveAll(30)...\n";
    list.removeAll(30);
    list.print();

    cout << "AddRange({40, 50, 60})...\n";
    int arr[] = {40,50,60};
	int n = sizeof(arr) / sizeof(arr[0]);
    list.addRange(arr, n);
    list.print();

    cout << "GetNode(2) and insert(25)...\n";
    Node<int>* node = list.getNode(2);
    list.insert(25, node);
    list.print();

    cout << "Remove(node at index 2)...\n";
    list.remove(node);
    list.print();

    cout << "Clear list...\n";
    list.clear();
    list.print();
    }
catch (const exception& e) {
        cerr << "[Exception caught] " << e.what() << endl;
}
    getline(cin, temp);
    system("cls");
}

void testHashTable() {
    cout << "=== Test Hash Table ===" << endl; 
    HashTable<int> ht;

    cout << "Adding {\"one\":1, \"two\":2, \"three\":3}...\n";
    ht.add("one", 1);
    ht.add("two", 2);
    ht.add("three", 3);
        // In toàn bộ bảng
        cout << "=== HashTable===" << endl;
    ht.print();

    // Lấy và in ra giá trị theo key
    for (auto key : { "one", "two", "three", "four" }) {
        auto v = ht.getValue(key);
        if (v.has_value()) {
            cout << "\"" << key << "\" = " << v.value() << endl;
        }
        else {
            cout << "\"" << key << "\" not found" << endl;
        }
    }

    // Tìm key theo value
    auto k1 = ht.getKey(2);
    if (k1.has_value()) {
        cout << "Key for value 2: \"" << k1.value() << "\"" << endl;
    }
    else {
        cout << "Not found key for value 2" << endl;
    }

    // Xóa một phần tử
    ht.remove("two");
    cout << "\n=== After remove \"two\" ===" << endl;
    ht.print();

    getline(cin, temp);
    system("cls");
    
}
int main() {
    testSearchTree();
    testSinglyLinkedList();
    testDoubleLinkedlist();
    testHashTable();
}
