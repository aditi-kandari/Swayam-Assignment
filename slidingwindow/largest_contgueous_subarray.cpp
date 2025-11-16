// Find the largest subarray with contiguous elements in a given array.
// Contiguous elements mean that the elements can be arranged in a sequence such that each element differs from the next by exactly 1.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Sliding Window + Hash Set Approach
int largestContiguousSubarray(const vector<int>& nums) {
    int maxLength = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        unordered_set<int> elements;
        int minElement = nums[i];
        int maxElement = nums[i];

        for (int j = i; j < n; ++j) {
            // If the element is already in the set, break (to avoid duplicates)
            if (elements.find(nums[j]) != elements.end()) {
                break;
            }
            elements.insert(nums[j]);
            minElement = min(minElement, nums[j]);
            maxElement = max(maxElement, nums[j]);

            // Check if the current subarray contains contiguous elements
            if (maxElement - minElement == j - i) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
    // Time Complexity: O(n^2)
    // Space Complexity: O(n) in the worst case for the hash set
}
