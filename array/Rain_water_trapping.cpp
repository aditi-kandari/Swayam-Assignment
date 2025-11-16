// Rain Water Trapping Problem :
// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it can trap after raining.

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach (O(n^2) time complexity)
int trapBruteForce(const vector<int>& height) {
    int n = height.size();
    int totalWater = 0;

    for (int i = 0; i < n; ++i) {
        int leftMax = 0, rightMax = 0;

        // Find the maximum height to the left of the current bar
        for (int j = 0; j <= i; ++j) {
            leftMax = max(leftMax, height[j]);
        }

        // Find the maximum height to the right of the current bar
        for (int j = i; j < n; ++j) {
            rightMax = max(rightMax, height[j]);
        }

        // Water trapped on top of the current bar
        totalWater += min(leftMax, rightMax) - height[i];
    }

    return totalWater;
}

// Optimal Approach using Precomputed Arrays (O(n) time complexity and O(n) space complexity)
int trapOptimal(const vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> leftMax(n), rightMax(n);
    int totalWater = 0;

    // Precompute the maximum height to the left of each bar
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // Precompute the maximum height to the right of each bar
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    // Calculate total water trapped
    for (int i = 0; i < n; ++i) {
        totalWater += min(leftMax[i], rightMax[i]) - height[i];
    }

    return totalWater;
}
