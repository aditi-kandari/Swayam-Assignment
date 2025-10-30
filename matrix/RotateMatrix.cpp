// Rotate the matrix by 90 degrees clockwise

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach: O(n*m) time complexity and O(n*m) space complexity
vector<vector<int>> rotateMatrixBruteForce(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> rotatedMatrix(cols, vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rotatedMatrix[j][rows - 1 - i] = matrix[i][j];
        }
    }

    return rotatedMatrix;
}

// Optimized Approach: O(n*m) time complexity and O(1) space complexity
void rotateMatrixOptimized(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;

    int n = matrix.size();
    int m = matrix[0].size();

    // Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < m; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
