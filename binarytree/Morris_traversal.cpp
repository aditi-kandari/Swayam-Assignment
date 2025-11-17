// Find the morris traversal of a binary tree.

#include <iostream>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to perform Morris Inorder Traversal
void morrisInorderTraversal(TreeNode* root) {
    TreeNode* current = root;
    TreeNode* pre;

    while (current != nullptr) {
        if (current->left == nullptr) {
            cout << current->value << " ";
            current = current->right;
        } else {
            pre = current->left;
            while (pre->right != nullptr && pre->right != current) {
                pre = pre->right;
            }

            if (pre->right == nullptr) {
                pre->right = current;
                current = current->left;
            } else {
                pre->right = nullptr;
                cout << current->value << " ";
                current = current->right;
            }
        }
    }
}