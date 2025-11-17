// Find the subset of a given set using bit manipulation

#include <iostream>
#include <vector>
using namespace std;

// Function to generate all subsets of a given set
vector<vector<int>> generateSubsets(const vector<int>& set) {
    int n = set.size();
    vector<vector<int>> subsets;
    int totalSubsets = 1 << n; // Total subsets = 2^n

    for (int mask = 0; mask < totalSubsets; mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            // Check if the i-th bit in mask is set
            if (mask & (1 << i)) {
                subset.push_back(set[i]); // Include set[i] in the current subset
            }
        }
        subsets.push_back(subset); // Add the current subset to the list of subsets
    }
    return subsets; // Time complexity: O(n * 2^n)
}