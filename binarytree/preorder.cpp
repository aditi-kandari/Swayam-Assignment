// Find the preorder traversal of a binary tree.

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

// Function to perform preorder traversal
void preorderTraversal(TreeNode* node) {
    if (node) {
        cout << node->value << " "; // Visit the root
        preorderTraversal(node->left.get()); // Traverse left subtree
        preorderTraversal(node->right.get()); // Traverse right subtree
    }
}