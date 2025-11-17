// Find the height of a binary tree.

#include <iostream>
#include <memory>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};  

// Function to calculate the height of the binary tree
int height(TreeNode* node) {
    if (!node) {
        return 0; // Base case: height of empty tree is 0
    } else {
        int leftHeight = height(node->left);   // Height of left subtree
        int rightHeight = height(node->right); // Height of right subtree
        return max(leftHeight, rightHeight) + 1;     // Height of tree is max of left/right heights plus 1 for root
    }
}