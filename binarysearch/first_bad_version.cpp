// First Bad Version
// You are a product manager and currently leading a team to develop a new product.
// Unfortunately, the latest version of your product fails the quality check.
// Since each version is developed based on the previous version, all the versions after a bad version  
// are also bad. Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one,
// which causes all the following ones to be bad.

#include <iostream>
using namespace std;

// Mock API to simulate the isBadVersion function
bool isBadVersion(int version) {
    // This is a mock implementation. In a real scenario, this function would be provided.
    const int firstBad = 4; // Example: version 4 is the first bad version
    return version >= firstBad;
}

// Function to find the first bad version using binary search
int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    int result = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            result = mid; // Found a bad version, try to find an earlier one
            right = mid - 1;
        } else {
            left = mid + 1; // Move to the later versions
        }
    }
    return result;
}