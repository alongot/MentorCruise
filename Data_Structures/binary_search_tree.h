#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template <typename T>
class BST {
private:
    // Node struct inside the class
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Insert helper
    Node* insert(Node* node, const T& data) {
        if (!node) return new Node(data);
        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        return node;
    }

    // Search helper
    bool contains(Node* node, const T& data) {
        if (!node) return false;
        if (data == node->data) return true;
        if (data < node->data)
            return contains(node->left, data);
        else
            return contains(node->right, data);
    }

    // Find minimum node
    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    // Delete helper
    Node* deleteNode(Node* node, const T& data) {
        if (!node) return nullptr;
        if (data < node->data)
            node->left = deleteNode(node->left, data);
        else if (data > node->data)
            node->right = deleteNode(node->right, data);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // Inorder traversal
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Destructor helper
    void destroyTree(Node* node) {
        if (!node) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}
    ~BST() {
        destroyTree(root);
    }

    void insert(const T& data) {
        root = insert(root, data);
    }

    void remove(const T& data) {
        root = deleteNode(root, data);
    }

    bool contains(const T& data) {
        return contains(root, data);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

#endif // BST_H
