// Count set/unset bits in an integer 

#include <iostream>
using namespace std;

// Function to count set bits in an integer
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1; // Increment count if the last bit is set
        n >>= 1;        // Right shift n to check the next bit
    }
    return count; // Time complexity: O(number of bits in n)
}

// Function to count unset bits in an integer
int countUnsetBits(int n) {
    int count = 0;
    int totalBits = sizeof(n) * 8; // Total bits in an integer
    for (int i = 0; i < totalBits; i++) {
        if (!(n & (1 << i))) { // Check if the ith bit is unset
            count++;
        }
    }
    return count; // Time complexity: O(totalBits)
}