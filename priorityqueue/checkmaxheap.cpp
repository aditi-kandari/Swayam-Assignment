// You are given the root of a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

#include <iostream>
#include <vector>   
#include <algorithm>
#include <memory>
using namespace std;

// structure of binary tree:
struct Node{
    int val;
    Node* left;
    Node* right; 
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

// function to check if binary tree is max-heap
bool isMaxHeapUtil(Node* root) {
    if (!root) return true; // An empty tree is a max-heap

    if (root->left) {
        if (root->val < root->left->val) return false; // violate max-heap property
    }
    if (root->right) {
        if (root->val < root->right->val) return false; // violate max-heap property
    }

    return isMaxHeapUtil(root->left) && isMaxHeapUtil(root->right); // check recursively for left and right subtrees
}
