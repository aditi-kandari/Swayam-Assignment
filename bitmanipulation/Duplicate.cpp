// In array having n+1 elements where each element is in the range 1 to n, find the duplicate number using bit manipulation.

#include <iostream>
#include <vector>
using namespace std;

// Function to find the duplicate number in the array
int findDuplicate(const vector<int>& nums) {
    int n = nums.size() - 1; // Since there are n+1 elements with values from 1 to n
    int duplicate = 0;

    // Iterate through each bit position
    for (int i = 0; i < 32; i++) {
        int countBitsArray = 0;
        int countBitsRange = 0;

        // Count bits in the array
        for (int num : nums) {
            if (num & (1 << i)) {
                countBitsArray++;
            }
        }

        // Count bits in the range 1 to n
        for (int j = 1; j <= n; j++) {
            if (j & (1 << i)) {
                countBitsRange++;
            }
        }

        // If count in array is greater than count in range, the duplicate has this bit set
        if (countBitsArray > countBitsRange) {
            duplicate |= (1 << i);
        }
    }

    return duplicate; // Time complexity: O(n)
}