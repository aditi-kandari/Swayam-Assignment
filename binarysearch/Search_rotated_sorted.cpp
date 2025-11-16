// Search a target value in a rotated sorted array

#include <iostream>
#include <vector>
using namespace std;

// Function to search for a target in a rotated sorted array using modified binary search
int searchInRotatedSortedArray(const vector<int>& nums, int target) {  
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // Target found
        }

        // Determine which side is properly sorted
        if (nums[left] <= nums[mid]) { // Left side is sorted
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // Target is in the left sorted side
            } else {
                left = mid + 1; // Target is in the right side
            }
        } else { // Right side is sorted
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1; // Target is in the right sorted side
            } else {
                right = mid - 1; // Target is in the left side
            }
        }
    }
    return -1; // Target not found
}