#include <iostream>
#include "searchTree.h"
#include "linkedList.h"
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
    cout << "Has 7? " << (tree.has(7) ? "Yes" : "No") << endl;

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
int main() {
    testSearchTree();

}	