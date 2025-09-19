#include "Node.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
struct BinarySearchTree {
    TreeNode<T>* root = nullptr;

    void addValue(T value) {
        if (root == nullptr) {
            root = new TreeNode<T>;
            root->value = value;
        }
        else {
            TreeNode<T>* foundNode = search(value, root);
            if (foundNode->value == value) {
                throw runtime_error("Duplicate value not allowed in BST");
            }
            TreeNode<T>* newNode = new TreeNode<T>;
            newNode->value = value;
            if (foundNode->value < value) {
                foundNode->right = newNode;
            }
            else {
                foundNode->left = newNode;
            }
        }
    }

    void addValues(T* value, int size) {
        if (!value) throw invalid_argument("Input array is null");
        for (int i = 0; i < size; i++) addValue(value[i]);
    }

    TreeNode<T>* search(T value, TreeNode<T>* curNode) {
        if (!curNode) throw runtime_error("Search on null node!");
        if (value > curNode->value) {
            if (curNode->right != nullptr) {
                return search(value, curNode->right);
            }
        }
        else if (value < curNode->value) {
            if (curNode->left != nullptr) {
                return search(value, curNode->left);
            }
        }
        return curNode;
    }

    TreeNode<T>* search(T value) {
        if (!root) throw runtime_error("Tree is empty");
        TreeNode<T>* node = search(value, root);
        if (node != nullptr && node->value == value) {
            return node;
        }
        throw runtime_error("Value not found in BST");
    }

    void clear(TreeNode<T>* node) {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    void clear() {
        clear(root);
        root = nullptr;
    }

    bool has(T v) {
        try {
            return search(v) != nullptr;
        }
        catch (...) {
            return false;
        }
    }

    void removeValue(T v) {
        if (!root) throw runtime_error("Tree is empty");
        root = removeValue(root, v);
    }

    TreeNode<T>* removeValue(TreeNode<T>* node, T v) {
        if (!node) throw runtime_error("Value not found in BST");

        if (v < node->value) {
            node->left = removeValue(node->left, v);
            return node;
        }
        else if (v > node->value) {
            node->right = removeValue(node->right, v);
            return node;
        }

        // Found node
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        }

        if (!node->left) {
            TreeNode<T>* temp = node->right;
            delete node;
            return temp;
        }

        if (!node->right) {
            TreeNode<T>* temp = node->left;
            delete node;
            return temp;
        }

        // 2 con
        TreeNode<T>* right = node->right;
        TreeNode<T>* leftMost = right;
        while (leftMost->left) leftMost = leftMost->left;

        leftMost->left = node->left;

        delete node;
        return right;
    }

    void printInOrder(TreeNode<T>* node) {
        if (!node) return;
        printInOrder(node->left);
        cout << node->value << " ";
        printInOrder(node->right);
    }
};
