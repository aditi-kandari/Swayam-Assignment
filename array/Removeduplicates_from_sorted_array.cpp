// Remove the duplicates from a sorted array in-place such that each element appears only once

#include <iostream> 
#include <vector>
using namespace std;
 
// Brute force approach to remove duplicates using extra space
int removeDuplicatesBruteForce(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> temp; // extra space for unique elements
    temp.push_back(nums[0]);
    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1]) {
            temp.push_back(nums[i]); // adding unique elements to temp
        }
    }
    for (int i = 0; i < temp.size(); i++) {
        nums[i] = temp[i]; // copying back to original array
    }
    return temp.size(); // new length of array with unique elements
}

// Optimal approach to remove duplicates in-place
int removeDuplicatesOptimal(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int uniqueIndex = 1; // index to place the next unique element
    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[uniqueIndex] = nums[i]; // placing unique element at uniqueIndex
            uniqueIndex++;
        }
    }
    return uniqueIndex; // new length of array with unique elements
}