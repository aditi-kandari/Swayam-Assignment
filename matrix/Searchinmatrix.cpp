// Search Element in a Matrix

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach: O(n*m) time complexity
bool searchElementBruteForce(const vector<vector<int>>& matrix, int target) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            if (element == target) {
                return true; // Element found
            }
        }
    }
    return false; // Element not found
}

// Optimized Approach: O(n + m) time complexity
bool searchElementOptimized(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int rows = matrix.size();
    int cols = matrix[0].size();
    int row = 0;
    int col = cols - 1;

    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            return true; // Element found
        } else if (matrix[row][col] > target) {
            col--; // Move left
        } else {
            row++; // Move down
        }
    }
    return false; // Element not found
}
