// Find the smaller element to the left for each element in the array

#include <iostream>
#include <vector>
using namespace std;

// Brute force approach to find the smaller element to the left
vector<int> smallerLeft(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1); // Initialize result array with -1

    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (nums[j] < nums[i]) {
                result[i] = nums[j];
                break; // Found the smaller element to the left
            }
        }
    }
    return result; // Time Complexity: O(n^2), Space Complexity: O(1)
}

// Optimized approach using stack to find the smaller element to the left
vector<int> smallerLeftOptimized(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1); // Initialize result array with -1
    vector<int> s; // Using vector as a stack

    for (int i = 0; i < n; i++) {
        // Pop elements from stack greater than or equal to current element
        while (!s.empty() && s.back() >= nums[i]) {
            s.pop_back();
        }
        // If stack is not empty, the top element is the smaller element to the left
        if (!s.empty()) {
            result[i] = s.back();
        }
        // Push the current element onto the stack
        s.push_back(nums[i]);
    }
    return result; // Time Complexity: O(n), Space Complexity: O(n)
}