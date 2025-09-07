#include <iostream>
#include "SinglyLinkedList.h"
int main() {
    SinglyLinkedList<int> list;
    list.add(10);
    list.add(20);
    list.insertHead(5);
    list.print();   // Output: 5, 10, 20,
}
