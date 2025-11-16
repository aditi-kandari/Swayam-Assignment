// Find the maximum subarray sum in the array
#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach - O(N^3) time complexity
int maxSubarraySumBruteForce(const vector<int>& arr) {
    int maxSum = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int currentSum = 0; //generate sum for subarray arr[i..j]
            for (int k = i; k <= j; k++) {
                currentSum += arr[k];
            }
            maxSum = max(maxSum, currentSum); //update maxSum if currentSum is greater
        }
    }
    return maxSum;
}

// Better Approach - O(N^2) time complexity
int maxSubarraySumBetter(const vector<int>& arr) {
    int maxSum = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int currentSum = 0; //initialize currentSum for new starting index i
        for (int j = i; j < n; j++) {
            currentSum += arr[j]; //add arr[j] to currentSum
            maxSum = max(maxSum, currentSum); //update maxSum if currentSum is greater
        }
    }
    return maxSum;
}

// Optimal Approach - Kadane's Algorithm - O(N) time complexity
int maxSubarraySumOptimal(const vector<int>& arr) {
    int maxSum = INT_MIN;
    int currentSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        currentSum += arr[i]; //add current element to currentSum
        maxSum = max(maxSum, currentSum); //update maxSum if currentSum is greater
        if (currentSum < 0) {
            currentSum = 0; //reset currentSum if it becomes negative
        }
    }
    return maxSum;
}