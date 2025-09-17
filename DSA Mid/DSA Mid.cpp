#include <iostream>
#include "searchTree.h"
#include "linkedList.h"
#include "hashTable.h"
using namespace std;
void testSearchTree() {
    BinarySearchTree<int> tree;

    // Thêm giá trị
    cout << "Adding values...\n";
    tree.addValue(10);
    tree.addValue(5);
    tree.addValue(15);
    tree.addValue(12);
    tree.addValue(20);

    cout << "In-order traversal: ";
    tree.printInOrder(tree.root);
    cout << endl;

    // Kiểm tra tồn tại
    cout << "Has 12? " << (tree.has(12) ? "Yes" : "No") << endl;
    cout << "Has 7? " << (tree.has(7) ? "Yes" : "No") << endl   ;

    // Xóa node lá
    cout << "\nRemove leaf (20)...\n";
    tree.removeValue(20);
    tree.printInOrder(tree.root);
    cout << endl;
    //Thêm lại 20
    tree.addValue(20);
    // Xóa node có 1 con
    cout << "\nRemove node with 1 child (15)...\n";
    tree.removeValue(15);
    tree.printInOrder(tree.root);
    cout << endl;

    // Xóa node có 2 con
    cout << "\nRemove node with 2 children (10)...\n";
    tree.removeValue(10);
    tree.printInOrder(tree.root);
    cout << endl;

    // Clear cây
    cout << "\nClearing tree...\n";
    tree.clear();
    cout << (tree.root == nullptr ? "Tree cleared" : "Tree not cleared") << endl;
}
void testDoubleLinkedlist() {
    DoubleLinkedlist<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.insertHead(0);
    list.insertTail(4);
    for (int i = 0; i < list.getSize(); i++) {
        cout << list.getValue(i) << ", ";//0 1 2 3 4	
    }
    cout << endl;
    list.clear();
    list.addRange({ 5,6,7,8 });
    list.insertAfter(9, list.getNode(3));//5 6 7 8 9
    list.insertBefore(4, list.getNode(0));//4 5 6 7 8 9
    list.removeAt(2);//4 5 7 8 9
    list.add(9);//4 5 7 8 9 9
    list.removeAll(9);//4 5 7 8
    list.print();
}
void testSinglyLinkedList() {
    SinglyLinkedList<int> list;
    list.add(10);
    list.add(20);
    list.insertHead(5);
    list.insertTail(30);
    list.print();   // Output: 5, 10, 20, 30,

    list.removeAt(1);
    list.print();   // Output: 5, 20, 30,
    list.removeAll(30);
    list.print();   // Output: 5, 20,
    list.addRange({ 40, 50, 60 });
    list.print();   // Output: 5, 20, 40, 50, 60,
    Node<int>* node = list.getNode(2);
    list.insert(25, node);
    list.print();   // Output: 5, 20, 40, 25, 50, 60,
    list.remove(node);
    list.print();   // Output: 5, 20, 25, 50, 60,
    list.clear();
    list.print();   // Output: (empty line)

}

void testHashTable() {
    // Tạo bảng băm cho kiểu int
    HashTable<int> ht;

    // Thêm dữ liệu
    ht.add("one", 1);
    ht.add("two", 2);
    ht.add("three", 3);

    // Lấy và in ra
    auto v1 = ht.getValue("one");
    if (v1.has_value()) {
        cout << "\"one\" = " << v1.value() << endl;
    }
    else {
        cout << "\"one\" not found" << endl;
    }

    auto v2 = ht.getValue("two");
    if (v2.has_value()) {
        cout << "\"two\" = " << v2.value() << endl;
    }
    else {
        cout << "\"two\" not found" << endl;
    }

    auto v3 = ht.getValue("three");
    if (v3.has_value()) {
        cout << "\"three\" = " << v3.value() << endl;
    }
    else {
        cout << "\"three\" not found" << endl;
    }

    // Kiểm tra một key không tồn tại
    auto v4 = ht.getValue("four");
    if (v4.has_value()) {
        cout << "\"four\" = " << v4.value() << endl;
    }
    else {
        cout << "\"four\" not found" << endl;
    }
}
int main() {
    int temp;
    testSearchTree();
	testDoubleLinkedlist();
    testSinglyLinkedList();
    testHashTable();
    cin >> temp;
}	

