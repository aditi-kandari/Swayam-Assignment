// Find the next greater element for each element in the array

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Brute force approach to find the next greater element
vector<int> nextGreaterElement(vector<int>& nums) { 
    int n = nums.size();
    vector<int> result(n, -1); // Initialize result array with -1

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[j] > nums[i]) {
                result[i] = nums[j];
                break; // Found the next greater element
            }
        }
    }
    return result; // Time Complexity: O(n^2), Space Complexity: O(1)
}

// Optimized approach using stack to find the next greater element
vector<int> nextGreaterElementOptimized(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1); // Initialize result array with -1
    stack<int> s; // Stack to keep track of elements

    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from stack smaller than or equal to current element
        while (!s.empty() && s.top() <= nums[i]) {
            s.pop();
        }
        // If stack is not empty, the top element is the next greater element
        if (!s.empty()) {
            result[i] = s.top();
        }
        // Push the current element onto the stack
        s.push(nums[i]);
    }
    return result; // Time Complexity: O(n), Space Complexity: O(n)
}