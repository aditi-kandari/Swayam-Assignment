// Check if nth bit is set or unset in an integer n

#include <iostream>
using namespace std;

// Function to check if the nth bit is set
bool isNthBitSet(int n, int k) {
    return (n & (1 << k)) != 0; // Check if the k-th bit is set using AND operation
} // Time complexity: O(1)
