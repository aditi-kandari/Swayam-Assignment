// Toggle the k-th bit of a given integer n

#include <iostream>
using namespace std;

// Function to toggle the k-th bit of n
int toggleKthBit(int n, int k) {
    return n ^ (1 << k); // Toggle the k-th bit using XOR operation
} // Time complexity: O(1)