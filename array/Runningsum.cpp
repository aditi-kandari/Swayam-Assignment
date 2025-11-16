// Running Sum of 1D Array
#include <iostream>
#include <vector>
using namespace std;

// Brute force approach to calculate running sum using extra space
vector<int> runningSumBruteForce(vector<int>& nums) {
    int n = nums.size();
    vector<int> runningSum(n);
    for (int i = 0; i < n; i++) {
        runningSum[i] = 0;
        for (int j = 0; j <= i; j++) {
            runningSum[i] += nums[j]; // summing up to the current index (N^2 time complexity)
        }
    }
    return runningSum;
}

// Optimal approach to calculate running sum in a single traversal
vector<int> runningSumOptimal(vector<int>& nums) {      
    int n = nums.size();
    vector<int> runningSum(n);
    runningSum[0] = nums[0]; // first element is the same
    for (int i = 1; i < n; i++) {
        runningSum[i] = runningSum[i - 1] + nums[i]; // adding current element to the previous sum ( N time complexity)
    }
    return runningSum;
}