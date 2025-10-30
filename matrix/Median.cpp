// Find median in row wise sorted matrix
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force Approach: O(n*m log(n*m)) time complexity
int findMedianBruteForce(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return -1;

    vector<int> elements;
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            elements.push_back(element);
        }
    }

    sort(elements.begin(), elements.end());
    int totalElements = elements.size();
    return elements[totalElements / 2];
}

// Optimized Approach: O(n * log(m)) time complexity
int findMedianOptimized(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return -1;

    int rows = matrix.size();
    int cols = matrix[0].size();
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    // Find the minimum and maximum elements in the matrix
    for (const auto& row : matrix) {
        minVal = min(minVal, row[0]);
        maxVal = max(maxVal, row[cols - 1]);
    }

    int desiredCount = (rows * cols + 1) / 2;

    while (minVal < maxVal) {
        int midVal = minVal + (maxVal - minVal) / 2;
        int count = 0;

        // Count how many elements are less than or equal to midVal
        for (const auto& row : matrix) {
            count += upper_bound(row.begin(), row.end(), midVal) - row.begin();
        }
        if (count < desiredCount) {
            minVal = midVal + 1;
        } else {
            maxVal = midVal;
        }
    }

    return minVal;
}