// Problem Statement:
// ------------------
// Given an array of distinct integers 'candidates' and an integer 'target',
// find all unique combinations of candidates where the chosen numbers sum to 'target'.
// You may use each number in 'candidates' an unlimited number of times.


#include <vector>
using namespace std;

// Helper function for backtracking

void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
    // Base case: target reached
    if (target == 0) {
        result.push_back(current);
        return;
    }

    // Explore candidates
    for (int i = start; i < candidates.size(); i++) {
        if (candidates[i] > target) continue;  // Skip if exceeds target

        current.push_back(candidates[i]);      // Choose number
        backtrack(candidates, target - candidates[i], i, current, result); // Recur (reuse same number)
        current.pop_back();                    // Backtrack
    }
}

// Function to return all unique combinations that sum to target

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(candidates, target, 0, current, result);
    return result;  // Return all valid combinations
}
