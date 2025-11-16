// Implement a Binary Search Tree (BST) in C++

#include <iostream>
#include <memory>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// BST class
class BST {
private:
    Node* root;

    // Helper function to insert a value
    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    // Helper function for inorder traversal
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    // Helper function to search for a value
    bool search(Node* node, int val) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == val) {
            return true;
        }
        if (val < node->data) {
            return search(node->left, val);
        } else {
            return search(node->right, val);
        }
    }
public:
    BST() : root(nullptr) {}

    // Public insert function
    void insert(int val) {
        root = insert(root, val);
    }

    // Public inorder traversal function
    void inorder() {
        inorder(root);
        cout << endl;
    }

    // Public search function
    bool search(int val) {
        return search(root, val);
    }
};
