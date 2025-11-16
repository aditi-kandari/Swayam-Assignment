// Count the number of subarrays with sum equal to zero in a given array.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Sliding Window + Hash Map Approach
int countZeroSumSubarrays(const vector<int>& nums) {
    unordered_map<int, int> sumFrequencyMap;
    int cumulativeSum = 0;
    int count = 0;

    // Initialize the map with sum 0 occurring once
    sumFrequencyMap[0] = 1;

    for (const int& num : nums) {
        cumulativeSum += num;

        // If cumulativeSum has been seen before, it means there are
        // subarrays ending at the current index which sum to zero
        if (sumFrequencyMap.find(cumulativeSum) != sumFrequencyMap.end()) {
            count += sumFrequencyMap[cumulativeSum];
        }

        // Record the occurrence of the cumulativeSum
        sumFrequencyMap[cumulativeSum]++;
    }
    return count;
    // Time Complexity: O(n)
    // Space Complexity: O(n)
}