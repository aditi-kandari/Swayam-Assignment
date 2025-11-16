// Solve the stock span problem using a stack-based approach

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> calculateStockSpan(const vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n); // Vector to store the span values
    stack<int> s; // Stack to keep track of indices of days

    for (int i = 0; i < n; i++) {
        // Pop elements from stack while the current price is higher than or equal to the price at the top index
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }
        // If stack is empty, all previous prices are less than current price
        if (s.empty()) {
            span[i] = i + 1; // Span is the entire range from day 0 to day i
        } else {
            span[i] = i - s.top(); // Span is the difference between current day and last higher price day
        }
        s.push(i); // Push current day index onto the stack
    }
    return span; // Return the calculated span values
} // Time Complexity: O(n), Space Complexity: O(n)