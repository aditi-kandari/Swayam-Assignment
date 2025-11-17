// Implement the basic structure and functionalities of a binary tree in C++.

#include <iostream>
#include <memory>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int value;
    unique_ptr<TreeNode> left;
    unique_ptr<TreeNode> right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Define the BinaryTree class
class BinaryTree {
private:
    unique_ptr<TreeNode> root;

    // Helper function for inserting a value
    void insertHelper(unique_ptr<TreeNode>& node, int val) {
        if (!node) {
            node = make_unique<TreeNode>(val);
        } else if (val < node->value) {
            insertHelper(node->left, val);
        } else {
            insertHelper(node->right, val);
        }
    }

    // Helper function for in-order traversal
    void inOrderHelper(TreeNode* node) {
        if (node) {
            inOrderHelper(node->left.get());
            cout << node->value << " ";
            inOrderHelper(node->right.get());
        }
    }   
public:
    BinaryTree() : root(nullptr) {}

    // Function to insert a value into the binary tree
    void insert(int val) {
        insertHelper(root, val);
    }

    // Function to perform in-order traversal of the binary tree
    void inOrderTraversal() {
        inOrderHelper(root.get());
        cout << endl;
    }
};
