// Set Matrix Zeroes : Given an m x n integer matrix, if an element is 0, set its entire row and column to 0's.

#include <iostream>
#include <vector>
using namespace std;

// Using hashmap to track rows and columns to be zeroed
void setMatrixZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if (m == 0) return;
    int n = matrix[0].size();

    vector<bool> rows(m, false);
    vector<bool> cols(n, false);

    // First pass to find all rows and columns that need to be zeroed
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    // Second pass to set the identified rows and columns to zero
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (rows[i] || cols[j]) {
                matrix[i][j] = 0;
            }
        }
    }
    // Time Complexity: O(m * n)
    // Space Complexity: O(m + n)
}

// Optimized approach using constant space
void setMatrixZeroesOptimized(vector<vector<int>>& matrix) {    
    int m = matrix.size();
    if (m == 0) return;
    int n = matrix[0].size();
    bool firstRowZero = false;
    bool firstColZero = false;

    // Check if first row has any zero
    for (int j = 0; j < n; ++j) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

    // Check if first column has any zero
    for (int i = 0; i < m; ++i) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }

    // Use first row and column as markers
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set matrix cells to zero based on markers
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero out the first row if needed
    if (firstRowZero) {
        for (int j = 0; j < n; ++j) {
            matrix[0][j] = 0;
        }
    }

    // Zero out the first column if needed
    if (firstColZero) {
        for (int i = 0; i < m; ++i) {
            matrix[i][0] = 0;
        }
    }
    // Time Complexity: O(m * n)
    // Space Complexity: O(1)
}
