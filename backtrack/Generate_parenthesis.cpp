// Problem Statement:
// ------------------
// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed (balanced) parentheses.


#include <vector>
#include <string>
using namespace std;

// Helper function for backtracking
void backtrack(int n, int open, int close, string current, vector<string>& result) {
    // Base case: when the current string is complete
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    // Add '(' if we can still place an open bracket
    if (open < n)
        backtrack(n, open + 1, close, current + "(", result);

    // Add ')' if we can close a previously opened bracket
    if (close < open)
        backtrack(n, open, close + 1, current + ")", result);
}

// Function to generate all valid parentheses combinations
vector<string> generateParenthesis(int n) {
    vector<string> result;
    backtrack(n, 0, 0, "", result);
    return result;  // Return all valid combinations
}
