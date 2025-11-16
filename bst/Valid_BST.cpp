// Check if a Binary Search Tree (BST) is valid

#include <iostream>
#include <limits>
using namespace std;
// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to validate the BST
bool isValidBSTUtil(Node* node, long minVal, long maxVal) {
    if (node == nullptr) {
        return true;
    }
    if (node->data <= minVal || node->data >= maxVal) {
        return false;
    }
    return isValidBSTUtil(node->left, minVal, node->data) &&
           isValidBSTUtil(node->right, node->data, maxVal);
}