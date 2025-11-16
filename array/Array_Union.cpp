// Find The Union of Two Sorted Arrays
#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach - O(N*M) time complexity
vector<int> unionBruteForce(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> result = arr1; // Start with all elements from arr1
    for (int i = 0; i < arr2.size(); i++) {
        bool found = false;
        for (int j = 0; j < arr1.size(); j++) {
            if (arr2[i] == arr1[j]) {
                found = true;
                break; // Element already exists in arr1
            }
        }
        if (!found) {
            result.push_back(arr2[i]); // Add unique element from arr2
        }
    }
    return result;
}

// Optimal Approach - O(N + M) time complexity
vector<int> unionOptimal(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else if (arr1[i] > arr2[j]) {
            result.push_back(arr2[j]);
            j++;
        } else {
            result.push_back(arr1[i]); // Both are equal
            i++;
            j++;
        }
    }
    // Add remaining elements from arr1
    while (i < arr1.size()) {
        result.push_back(arr1[i]);
        i++;
    }
    // Add remaining elements from arr2
    while (j < arr2.size()) {
        result.push_back(arr2[j]);
        j++;
    }
    return result; // Time Complexity: O(N + M)
}