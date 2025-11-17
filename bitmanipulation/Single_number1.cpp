// In an array every element appears twice except for one. Find that single one.

#include <iostream>
#include <vector>
using namespace std;

// Function to find the single number in the array
int singleNumber(const vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num; // XORing all elements to find the unique one
    }
    return result; // Time complexity: O(n)
}