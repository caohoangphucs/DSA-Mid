#pragma once
#include <iostream>

template <typename T>
struct Node {
    T data;           
    Node<T>* next;    

    Node() : data(T()), next(nullptr) {}

    Node(const T& value) : data(value), next(nullptr) {}
};


template <typename T>
struct TreeNode {
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode() : data(T()), left(nullptr), right(nullptr) {}
    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};