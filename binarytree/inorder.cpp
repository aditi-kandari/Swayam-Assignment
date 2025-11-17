// Find the inorder traversal of a binary tree.

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

// Function to perform inorder traversal
void inorderTraversal(TreeNode* node) {
    if (node) {
        inorderTraversal(node->left.get()); // Traverse left subtree
        cout << node->value << " "; // Visit the root
        inorderTraversal(node->right.get()); // Traverse right subtree
    }
}