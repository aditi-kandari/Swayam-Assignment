// Check if a number is a power of two/four using bit manipulation

#include <iostream>
using namespace std;

// Function to check if n is a power of two
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0; // A number is a power of two if it has exactly one set bit
} // Time complexity: O(1)
