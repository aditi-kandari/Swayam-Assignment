// Find the equilibrium index in an array

#include <iostream>
#include <vector>
using namespace std;
 
// Brute force approach to find equilibrium index using nested loops
int findEquilibriumIndexBruteForce(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int leftSum = 0;
        int rightSum = 0;
        // Calculate left sum
        for (int j = 0; j < i; j++) {
            leftSum += arr[j]; // summing elements to the left of index i (N time complexity)
        }
        // Calculate right sum
        for (int j = i + 1; j < n; j++) {
            rightSum += arr[j]; // summing elements to the right of index i (N time complexity)
        }
        if (leftSum == rightSum) {
            return i; // equilibrium index found
        }
    }
    return -1; // no equilibrium index found
}

// Optimal approach to find equilibrium index in a single traversal
int findEquilibriumIndexOptimal(vector<int>& arr) {
    int n = arr.size();
    int totalSum = 0;
    for (int num : arr) {
        totalSum += num; // calculating total sum of the array (N time complexity)
    }
    int leftSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum -= arr[i]; // now totalSum is the right sum for index i
        if (leftSum == totalSum) {
            return i; // equilibrium index found
        }
        leftSum += arr[i]; // update left sum for next index
    }
    return -1; // no equilibrium index found
}