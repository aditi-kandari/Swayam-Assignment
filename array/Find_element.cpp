// Search a given elemnt in the array and return its index if found, else return -1
#include <iostream>
#include <vector>
using namespace std;

// Brute force approach to find an element in the array using linear search
int findElementBruteForce(vector<int>& arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // element found at index i (N time complexity)
        }
    }
    return -1; // element not found
}

// Optimal approach to find an element in a sorted array using binary search
int findElementOptimal(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // to avoid potential overflow
        if (arr[mid] == target) {
            return mid; // element found at index mid (logN time complexity)
        }
        else if (arr[mid] < target) {
            left = mid + 1; // search in the right half
        }
        else {
            right = mid - 1; // search in the left half
        }
    }
    return -1; // element not found
}