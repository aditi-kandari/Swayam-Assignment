// Find the lower bound of a value in a sorted array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the lower bound of a value in a sorted array using binary search
int lowerBound(vector<int>& arr, int value) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left; // Returns the index of the first element not less than 'value'
}