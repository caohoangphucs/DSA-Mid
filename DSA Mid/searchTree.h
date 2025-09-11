#include "Node.h"
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
                return; // tránh trùng
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
        for (int i = 0; i < size; i++) addValue(value[i]);
    }

    TreeNode<T>* search(T value, TreeNode<T>* curNode) {
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
        TreeNode<T>* node = search(value, root);
        if (node != nullptr && node->value == value) {
            return node;
        }
        return nullptr;
    }
    void clear(TreeNode<T>* node) {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
    void clear() {
        clear(root);
    }
    bool has(T v) {
        return search(v);
    }
    void removeValue(T v) {
        root = removeValue(root, v);
    }
    TreeNode<T>* removeValue(TreeNode<T>* node, T v) {
        if (!node) return nullptr;
        if (v < node->value) {
            node->left = removeValue(node->left, v);
            return node;
        }
        else if (v > node->value) {
            node->right = removeValue(node->right, v);
            return node;
        }

        //Found node

        //Ko co con
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        }

        //Co 1 con
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

        //2 con

        //Find leftMost
        TreeNode<T>* right = node->right;
        TreeNode<T>* leftMost = right;
        while (leftMost->left) leftMost = leftMost->left;

        //Gan node->left vao leftMost
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
