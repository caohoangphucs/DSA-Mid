#pragma once
#include <iostream>

//For linked list
template <typename T>
struct Node {
    T data;           
    Node<T>* next;    

    Node() : data(T()), next(nullptr) {}

    Node(const T& value) : data(value), next(nullptr) {}
};
//For Double linked list
template <typename T>
struct DNode {
    T data;
    DNode<T>* prev;
    DNode<T>* next;

    DNode(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

//For binary search tree
template <typename T>
struct TreeNode {
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode() : data(T()), left(nullptr), right(nullptr) {}
    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

