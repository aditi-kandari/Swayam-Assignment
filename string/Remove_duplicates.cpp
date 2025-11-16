// Remove all duplicate characters from a given string

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// Brute Force Approach - O(N^2) time complexity
string removeDuplicatesBruteForce(const string& str) {
    string result;
    for (char ch : str) {
        // Check if character is already in result
        bool found = false;
        for (char resCh : result) {
            if (resCh == ch) {
                found = true;
                break;
            }
        }
        if (!found) {
            result += ch; // Append character if not found
        }
    }
    return result;
}

// Optimal Approach - O(N) time complexity
string removeDuplicatesOptimal(const string& str) {
    unordered_set<char> seen;
    string result;
    for (char ch : str) {
        // If character is not seen before, add to result and mark as seen
        if (seen.find(ch) == seen.end()) {
            seen.insert(ch);
            result += ch;
        }
    }
    return result; // Time Complexity: O(N)
}