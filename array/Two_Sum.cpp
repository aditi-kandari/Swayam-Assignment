// Solve the Two sum problem
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Brute Force Approach - O(n^2) time complexity
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

// Optimized Approach using Hash Map - O(n) time complexity
vector<int> twoSumOptimized(vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // value -> index
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i]; // Find the complement
        if (numMap.find(complement) != numMap.end()) // Check if complement exists
        {
            return {numMap[complement], i}; // Return indices
        }
        numMap[nums[i]] = i; //store the index of the current number
    }
    return {};
}   