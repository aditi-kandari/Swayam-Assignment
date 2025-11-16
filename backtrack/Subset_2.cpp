// Problem Statement:
// ------------------
// Given an integer array 'nums' that may contain duplicates,
// return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. 
// Return the subsets in any order.

#include <vector>
#include <algorithm>
using namespace std;

// Helper function for backtracking
void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);  // Add current subset to result

    for (int i = start; i < nums.size(); i++) {
        // Skip duplicates at the same recursion level
        if (i > start && nums[i] == nums[i - 1])
            continue;

        current.push_back(nums[i]);                   // Include current element
        backtrack(i + 1, nums, current, result);      // Recurse for next elements
        current.pop_back();                           // Backtrack (remove last element)
    }
}

// Function to return all unique subsets
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());  // Sort to handle duplicates
    vector<vector<int>> result;
    vector<int> current;
    backtrack(0, nums, current, result);
    return result;  // Return all unique subsets
}
