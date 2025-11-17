// Check if two binary trees are the symmetric

#include <iostream>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};  

// Helper function to check if two trees are mirror images
bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) {
        return true; // Both nodes are null, they are mirrors
    }
    if (!t1 || !t2) {
        return false; // One of the nodes is null, not mirrors
    }
    // Check if current nodes are equal and their subtrees are mirrors
    return (t1->value == t2->value) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}