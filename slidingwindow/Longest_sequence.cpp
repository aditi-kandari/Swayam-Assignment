// Longest consecutive sequence in an unsorted array : 
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Sliding Window + Hash Set Approach
int longestConsecutive(const vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longestStreak = 0;

    for (const int& num : numSet) {
        // Only start counting if 'num' is the start of a sequence
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentStreak = 1;

            // Count the length of the sequence
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
    // Time Complexity: O(n)
    // Space Complexity: O(n)
}
