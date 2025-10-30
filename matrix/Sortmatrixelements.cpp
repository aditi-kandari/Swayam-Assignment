// Sort the elements of a matrix in ascending order

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force Approach: O(n*m log(n*m)) time complexity
vector<vector<int>> sortMatrixBruteForce(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> elements;

    // Flatten the matrix into a single vector
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            elements.push_back(element);
        }
    }

    // Sort the flattened vector
    sort(elements.begin(), elements.end());

    // Reconstruct the sorted matrix
    vector<vector<int>> sortedMatrix(rows, vector<int>(cols));
    int index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sortedMatrix[i][j] = elements[index++];
        }
    }

    return sortedMatrix;
}

// Optimized Approach: O(n*m) time complexity using Counting Sort (suitable for small range of elements)
vector<vector<int>> sortMatrixOptimized(const vector<vector<int>>& matrix, int minVal, int maxVal) {
    if (matrix.empty()) return {};

    int rows = matrix.size();
    int cols = matrix[0].size();
    int range = maxVal - minVal + 1;
    vector<int> count(range, 0);

    // Count occurrences of each element
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            count[element - minVal]++;
        }
    }

    // Reconstruct the sorted matrix
    vector<vector<int>> sortedMatrix(rows, vector<int>(cols));
    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (count[i] > 0) {
            sortedMatrix[index / cols][index % cols] = i + minVal;
            index++;
            count[i]--;
        }
    }

    return sortedMatrix;
}