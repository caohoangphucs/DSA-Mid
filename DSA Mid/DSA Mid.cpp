#include <iostream>
#include "searchTree.h"
#include "linkedList.h"
#include "hashTable.h"
#include <cstdlib>
using namespace std;

string temp;

void testSearchTree() {
    cout << "=== Test Search Tree ===" << endl;
    BinarySearchTree<int> tree;

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
    getline(cin, temp);
    system("cls");
}

void testDoubleLinkedlist() {
    cout << "=== Test Double Linked List ===" << endl;
    DoubleLinkedlist<int> list;

    cout << "Adding values 1, 2, 3...\n";
    list.add(1);
    list.add(2);
    list.add(3);

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
    list.addRange({ 5,6,7,8 });
    list.print();

    cout << "InsertAfter(9, node(3))...\n";
    list.insertAfter(9, list.getNode(3)); // 5 6 7 8 9
    list.print();

    cout << "InsertBefore(4, node(0))...\n";
    list.insertBefore(4, list.getNode(0)); // 4 5 6 7 8 9
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

    getline(cin, temp);
    system("cls");
}

void testSinglyLinkedList() {
    cout << "=== Test Singly Linked List ===" << endl;
    SinglyLinkedList<int> list;

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
    list.addRange({ 40, 50, 60 });
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

    cout << "GetValue(\"one\"): ";
    auto v1 = ht.getValue("one");
    cout << (v1.has_value() ? to_string(v1.value()) : "not found") << endl;

    cout << "GetValue(\"two\"): ";
    auto v2 = ht.getValue("two");
    cout << (v2.has_value() ? to_string(v2.value()) : "not found") << endl;

    cout << "GetValue(\"three\"): ";
    auto v3 = ht.getValue("three");
    cout << (v3.has_value() ? to_string(v3.value()) : "not found") << endl;

    cout << "GetValue(\"four\"): ";
    auto v4 = ht.getValue("four");
    cout << (v4.has_value() ? to_string(v4.value()) : "not found") << endl;

    getline(cin, temp);
    system("cls");
}

int main() {
    testSearchTree();
    testSinglyLinkedList();
    testDoubleLinkedlist();
    testHashTable();
}
