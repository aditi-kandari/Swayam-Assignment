// Find the missing number in an array containing n distinct numbers from 0 to n using hashmap

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int findMissingNumber(const vector<int>& nums) {
    unordered_map<int, bool> numMap; // Map to track presence of numbers
    int n = nums.size();

    // Mark all numbers present in the array
    for (int num : nums) {
        numMap[num] = true;
    }

    // Check for the missing number in the range 0 to n
    for (int i = 0; i <= n; ++i) {
        if (numMap.find(i) == numMap.end()) {
            return i; // Return the missing number
        }
    }
    return -1; // This line should never be reached
    // O(n) time complexity, O(n) space complexity
}