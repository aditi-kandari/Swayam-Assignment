// Search in a rotated sorted array with duplicates

#include <iostream>
#include <vector>
using namespace std;

// Function to search for a target in a rotated sorted array with duplicates using modified binary search
bool searchInRotatedSortedArrayWithDuplicates(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return true; // Target found
        }

        // If we have duplicates, we can only move the left pointer up by one
        if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
            left++;
            right--;
        }
        // Determine which side is properly sorted
        else if (nums[left] <= nums[mid]) { // Left side is sorted
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
    return false; // Target not found
}