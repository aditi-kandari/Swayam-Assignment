// Merge two sorted arrays into one sorted array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force Approach (O((m+n) log(m+n)) time complexity)
vector<int> mergeBruteForce(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged;
    merged.reserve(arr1.size() + arr2.size());

    // Copy elements from both arrays
    merged.insert(merged.end(), arr1.begin(), arr1.end());
    merged.insert(merged.end(), arr2.begin(), arr2.end());

    // Sort the merged array
    sort(merged.begin(), merged.end());
    return merged;
}

// Optimal Two-Pointer Approach (O(m+n) time complexity)
vector<int> mergeOptimal(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged;
    merged.reserve(arr1.size() + arr2.size());

    int i = 0, j = 0;

    // Merge the two arrays using two pointers
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    // Copy any remaining elements from arr1
    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }

    // Copy any remaining elements from arr2
    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}