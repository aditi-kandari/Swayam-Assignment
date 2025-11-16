// Find the longest substring without repeating characters in a given string.

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// Brute Force Approach
int lengthOfLongestSubstringBruteForce(const string& s) {
    int maxLength = 0;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        unordered_set<char> charSet;
        int currentLength = 0;

        for (int j = i; j < n; ++j) {
            if (charSet.find(s[j]) == charSet.end()) {
                charSet.insert(s[j]);
                currentLength++;
                maxLength = max(maxLength, currentLength);
            } else {
                break; // Repeating character found
            }
        }
    }
    return maxLength;
    // Time Complexity: O(n^2)
    // Space Complexity: O(min(m, n)) where m is the size of the character set
}

// Sliding Window + Hash Set Approach
int lengthOfLongestSubstringSlidingWindow(const string& s) {
    unordered_set<char> charSet;
    int left = 0, right = 0, maxLength = 0;
    int n = s.length();

    while (right < n) {
        if (charSet.find(s[right]) == charSet.end()) {
            charSet.insert(s[right]);
            right++;
            maxLength = max(maxLength, right - left);
        } else {
            charSet.erase(s[left]);
            left++;
        }
    }
    return maxLength;
    // Time Complexity: O(n)
    // Space Complexity: O(min(m, n)) where m is the size of the character set
}