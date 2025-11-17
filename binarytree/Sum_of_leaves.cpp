//Given the root of a binary tree, return the sum of all left leaves.

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to check if a node is a leaf
bool isLeaf(TreeNode* node) {
    return node != nullptr && node->left == nullptr && node->right == nullptr;
}   

// Function to calculate the sum of left leaves
int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    
    int sum = 0;
    
    // Check if the left child is a leaf
    if (isLeaf(root->left)) {
        sum += root->left->val;
    } else {
        sum += sumOfLeftLeaves(root->left);
    }
    
    // Recur for the right child
    sum += sumOfLeftLeaves(root->right);
    
    return sum;
}