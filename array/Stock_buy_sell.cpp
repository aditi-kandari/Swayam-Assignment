// Solve the Stock Buy and Sell problem
// Given an array where the ith element is the price of a given stock on day i,
// find the maximum profit you can achieve by making as many transactions as you like
// (i.e., buy one and sell one share of the stock multiple times).

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach - O(n^2) time complexity
int maxProfitBruteForce(vector<int>& prices) {
    int n = prices.size();
    int maxProfit = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (prices[j] > prices[i]) {
                maxProfit += prices[j] - prices[i];
            }
        }
    }
    return maxProfit;
}

// Optimized Approach - O(n) time complexity
int maxProfitOptimized(vector<int>& prices) {
    int n = prices.size();
    int maxProfit = 0;
    for (int i = 1; i < n; ++i) {
        if (prices[i] > prices[i - 1])// If selling today is profitable
        {
            maxProfit += prices[i] - prices[i - 1]; // Accumulate profit
        }
    }
    return maxProfit;
}
