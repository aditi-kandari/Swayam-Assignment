// Find the top view of a binary tree

#include <iostream>
#include <map>
#include <queue>
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

// Function to find the top view of a binary tree
void topView(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Map to store the first node at each horizontal distance
    map<int, int> topViewMap;
    // Queue to perform level order traversal
    queue<pair<TreeNode*, int>> q; // Pair of node and its horizontal distance

    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        TreeNode* node = front.first;
        int hd = front.second;

        // If this horizontal distance is not already present in the map
        if (topViewMap.find(hd) == topViewMap.end()) {
            topViewMap[hd] = node->val;
        }

        // Enqueue left and right children with updated horizontal distances
        if (node->left) {
            q.push({node->left, hd - 1});
        }
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }

    // Print the top view
    for (const auto& pair : topViewMap) {
        cout << pair.second << " ";
    }
    cout << endl;
}