// In an array of integers, every element appears thrice except for one. Find that single one.

#include <iostream>
#include <vector>
using namespace std;

// Function to find the single number in the array
int singleNumber(const vector<int>& nums) {
    int result = 0;
    // Iterate through each bit position
    for (int i = 0; i < 32; i++) {
        int sum = 0;
        // Sum up the i-th bits of all numbers
        for (int num : nums) {
            sum += (num >> i) & 1;
        }
        // If sum % 3 is not zero, it means the single number has a set bit at this position
        if (sum % 3 != 0) {
            result |= (1 << i);
        }
    }
    return result; // Time complexity: O(n)
}