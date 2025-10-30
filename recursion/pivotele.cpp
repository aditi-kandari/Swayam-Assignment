// Find Pivot Index in an Array using Recursion

#include <iostream>
using namespace std;

// Brute Force Approach 
int findPivotIndexBruteForce(int arr[], int n, int index = 0){
    // Base case: if index reaches the end of the array
    if(index == n){
        return -1; // No pivot index found
    }
    int leftSum = 0;
    int rightSum = 0;
    // Calculate left sum
    for(int i = 0; i < index; i++){
        leftSum += arr[i];
    }
    // Calculate right sum
    for(int i = index + 1; i < n; i++){
        rightSum += arr[i];
    }
    // Check if left sum equals right sum
    if(leftSum == rightSum){
        return index; // Pivot index found
    }
    // Recursive call to check the next index
    return findPivotIndexBruteForce(arr, n, index + 1);
    // Time Complexity: O(n^2)
    // Space Complexity: O(n) due to call stack
}


// Optimal Approach using total sum
int findPivotIndexOptimal(int arr[], int n, int totalSum, int leftSum = 0, int index = 0) {
    // Base case: if index reaches the end of the array
    if (index == n) {
        return -1; // No pivot index found
    }
    // Calculate right sum using total sum and left sum
    int rightSum = totalSum - leftSum - arr[index];
    // Check if left sum equals right sum
    if (leftSum == rightSum) {
        return index; // Pivot index found
    }
    // Recursive call: update left sum and move to the next index
    return findPivotIndexOptimal(arr, n, totalSum, leftSum + arr[index], index + 1);
    // Time Complexity: O(n)
    // Space Complexity: O(n) due to call stack
}