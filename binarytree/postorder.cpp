// Find the postorder traversal of a binary tree.

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

// Function to perform postorder traversal
void postorderTraversal(TreeNode* node) {
    if (node) {
        postorderTraversal(node->left.get()); // Traverse left subtree
        postorderTraversal(node->right.get()); // Traverse right subtree
        cout << node->value << " "; // Visit the root
    }
}