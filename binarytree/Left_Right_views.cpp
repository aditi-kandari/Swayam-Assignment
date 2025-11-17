// Find the left,right views of a binary tree.

#include <iostream>
#include <vector>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to find the left view of the binary tree
void leftViewUtil(TreeNode* node, int level, int& maxLevel, vector<int>& view) {
    if (!node) {
        return;
    }

    // If this is the first node of its level
    if (level > maxLevel) {
        view.push_back(node->value);
        maxLevel = level;
    }

    // Recur for left and right subtrees
    leftViewUtil(node->left, level + 1, maxLevel, view);
    leftViewUtil(node->right, level + 1, maxLevel, view);
}

vector<int> leftView(TreeNode* root) {
    vector<int> view;
    int maxLevel = 0;
    leftViewUtil(root, 1, maxLevel, view);
    return view;
}


// Function to find the right view of the binary tree
void rightViewUtil(TreeNode* node, int level, int& maxLevel, vector<int>& view) {
    if (!node) {
        return;
    }

    // If this is the first node of its level
    if (level > maxLevel) {
        view.push_back(node->value);
        maxLevel = level;
    }

    // Recur for right and left subtrees
    rightViewUtil(node->right, level + 1, maxLevel, view);
    rightViewUtil(node->left, level + 1, maxLevel, view);
}

vector<int> rightView(TreeNode* root) {
    vector<int> view;
    int maxLevel = 0;
    rightViewUtil(root, 1, maxLevel, view);
    return view;
}
