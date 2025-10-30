// Count Rows with max ones in a Binary Matrix
#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach: O(n*m) time complexity
int countRowsWithMaxOnesBruteForce(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return -1;

    int maxOnes = -1;
    int rowIndex = -1;

    for (int i = 0; i < matrix.size(); ++i) {
        int countOnes = 0;
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 1) {
                countOnes++;
            }
        }
        if (countOnes > maxOnes) {
            maxOnes = countOnes;
            rowIndex = i;
        }
    }
    return rowIndex;
}

// Optimized Approach: O(n + m) time complexity
int countRowsWithMaxOnesOptimized(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return -1;

    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxOnesRowIndex = -1;
    int j = cols - 1; // Start from the top-right corner

    for (int i = 0; i < rows; ++i) {
        while (j >= 0 && matrix[i][j] == 1) {
            j--; // Move left
            maxOnesRowIndex = i; // Update row index with max ones
        }
    }
    return maxOnesRowIndex;
}