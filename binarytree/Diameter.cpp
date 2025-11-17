// Find the diameter of the binary tree.
// The diameter is defined as the length of the longest path between any two nodes in the tree.

#include <iostream>
using namespace std;    

// Define the structure for a tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Helper function to calculate the height of the tree and update the diameter
int heightAndDiameter(TreeNode* node, int& diameter) {
    if (!node) {
        return 0; // Base case: height of empty tree is 0
    }

    int leftHeight = heightAndDiameter(node->left, diameter);   // Height of left subtree
    int rightHeight = heightAndDiameter(node->right, diameter); // Height of right subtree

    // Update the diameter if the path through the current node is larger
    diameter = max(diameter, leftHeight + rightHeight);

    // Return the height of the current node
    return max(leftHeight, rightHeight) + 1;
}