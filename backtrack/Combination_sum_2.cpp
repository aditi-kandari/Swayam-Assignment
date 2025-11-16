// Problem Statement:
// ------------------
// Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used **once** in each combination.
// The solution set must not contain duplicate combinations.


#include <vector>
#include <algorithm>
using namespace std;

// Helper function for backtracking
void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
    // Base case: target reached
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < candidates.size(); i++) {
        // Skip duplicates to avoid repeated combinations
        if (i > start && candidates[i] == candidates[i - 1]) continue;

        // Stop exploring if number exceeds target
        if (candidates[i] > target) break;

        current.push_back(candidates[i]);  // Choose number
        backtrack(candidates, target - candidates[i], i + 1, current, result); // Move to next index (no reuse)
        current.pop_back();                // Backtrack
    }
}

// Function to return all unique combinations that sum to target
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());  // Sort for duplicate handling
    vector<vector<int>> result;
    vector<int> current;
    backtrack(candidates, target, 0, current, result);
    return result;  // Return all valid combinations
}
