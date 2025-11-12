// Solve the two-sum problem using a hash map for efficient lookup
// Given an array of integers and a target sum, return indices of the two numbers such that they add up to the target.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // Map to store number and its index
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i}; // Return indices of the two numbers
        }
        numMap[nums[i]] = i; // Store the index of the current number
    }
    return {}; // Return empty vector if no solution is found
    // O(n) time complexity, O(n) space complexity
}