// Container with most water :
// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
// Find two lines, which together with x-axis forms a container, such that the container contains the most water.

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach (O(n^2) time complexity)
int maxAreaBruteForce(const vector<int>& height) {
    int maxArea = 0;
    int n = height.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int area = min(height[i], height[j]) * (j - i); // Calculate area
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}

// Optimal Two-Pointer Approach (O(n) time complexity)
int maxAreaOptimal(const vector<int>& height) {
    int maxArea = 0;
    int left = 0;                  // Left pointer
    int right = height.size() - 1; // Right pointer

    while (left < right) {
        int area = min(height[left], height[right]) * (right - left); // Calculate area
        maxArea = max(maxArea, area);

        // Move the pointer pointing to the shorter line inward
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}