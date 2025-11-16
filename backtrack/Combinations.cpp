// Problem Statement:
// ------------------
// Given two integers n and k, return all possible combinations of k numbers 
// chosen from the range [1, n].


#include <vector>
using namespace std;

// Helper function to generate combinations using backtracking

void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
    // Base case: if combination size equals k, store it
    if (current.size() == k) {
        result.push_back(current);
        return;
    }

    // Explore further numbers
    for (int i = start; i <= n; i++) {
        current.push_back(i);              // Choose number
        backtrack(i + 1, n, k, current, result);  // Recurse for next number
        current.pop_back();                // Backtrack
    }
}

// Function to return all combinations of size k from [1..n]

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(1, n, k, current, result);
    return result;  // Return all valid combinations
}
