// check  if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum

#include <iostream>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to check if there is a root-to-leaf path with the given sum
bool hasPathSum(TreeNode* node, int targetSum) {
    if (!node) {
        return targetSum == 0; // Check if the remaining sum is zero at leaf
    }

    // Subtract the current node's value from the target sum
    targetSum -= node->value;

    // If it's a leaf node, check if the remaining sum is zero
    if (!node->left && !node->right) {
        return targetSum == 0;
    }

    // Recursively check the left and right subtrees
    return hasPathSum(node->left, targetSum) || hasPathSum(node->right, targetSum);
}