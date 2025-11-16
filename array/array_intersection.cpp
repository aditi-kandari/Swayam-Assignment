// Find Intersection of Two Sorted Arrays

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach - O(N*M) time complexity
vector<int> intersectionBruteForce(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> result;
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2.size(); j++) {
            if (arr1[i] == arr2[j]) {
                result.push_back(arr1[i]);
                break; // To avoid duplicates in result
            }
        }
    }
    return result;
}

// Optimal Approach - O(N + M) time complexity
vector<int> intersectionOptimal(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            result.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return result; // Time Complexity: O(N + M)
}
