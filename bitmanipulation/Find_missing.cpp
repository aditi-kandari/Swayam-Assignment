// In an array of integers of size n, every element is present from 0 to n with one element missing. Find that missing element using bit manipulation

#include <iostream>
#include <vector>
using namespace std;

// Function to find the missing number in the array
int findMissingNumber(const vector<int>& nums, int n) {
    int xorFull = 0;
    int xorArray = 0;

    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xorFull ^= i;
    }

    // XOR all elements in the given array
    for (int num : nums) {
        xorArray ^= num;
    }

    // The missing number is the XOR of the two results
    return xorFull ^ xorArray; // Time complexity: O(n)
}