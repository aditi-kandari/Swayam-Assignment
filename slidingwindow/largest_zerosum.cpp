// Largest subarray with zero sum: Given an array of integers, find the length of the largest subarray with a sum of zero.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Sliding Window + Hash Map Approach
int largestZeroSumSubarray(const vector<int>& nums) {
    unordered_map<int, int> sumIndexMap;
    int maxLength = 0;
    int cumulativeSum = 0;

    for (size_t i = 0; i < nums.size(); ++i) {
        cumulativeSum += nums[i];

        if (cumulativeSum == 0) {
            maxLength = i + 1; // From start to current index
        } else {
            if (sumIndexMap.find(cumulativeSum) != sumIndexMap.end()) {
                maxLength = max(maxLength, static_cast<int>(i - sumIndexMap[cumulativeSum]));
            } else {
                sumIndexMap[cumulativeSum] = i;
            }
        }
    }
    return maxLength;
    // Time Complexity: O(n)
    // Space Complexity: O(n)
}