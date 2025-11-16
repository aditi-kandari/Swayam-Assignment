// Find the upper bound of a value in a sorted array

#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the upper bound of a value in a sorted array using binary search
int upperBound(const std::vector<int>& arr, int value) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left; // Returns the index of the first element greater than 'value'
}
