// Count the number of set bits in the integers from 0 to n and return them as an array

#include <iostream>
#include <vector>
using namespace std;

// Function to count set bits for numbers from 0 to n
vector<int> countBits(int n) {
    vector<int> result(n + 1, 0); // Initialize a vector of size n+1 with all elements as 0
    for (int i = 1; i <= n; i++) {
        result[i] = result[i >> 1] + (i & 1); // Use the relation: countBits(i) = countBits(i/2) + (i % 2)
    }
    return result; // Time complexity: O(n)
}