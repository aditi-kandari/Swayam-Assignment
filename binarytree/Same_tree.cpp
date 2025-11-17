// Check if two binary trees are the same

#include <iostream>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to check if two binary trees are the same
bool isSameTree(TreeNode* p, TreeNode* q) {
    // Both nodes are null, trees are the same
    if (!p && !q) {
        return true;
    }
    // One of the nodes is null, trees are not the same
    if (!p || !q) {
        return false;
    }
    // Check current node values and recursively check left and right subtrees
    return (p->value == q->value) &&
           isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}