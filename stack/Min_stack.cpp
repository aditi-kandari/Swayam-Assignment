// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time

#include <iostream>
#include <stack>
using namespace std;
class MinStack {
    stack<int> mainStack; // Stack to store all elements
    stack<int> minStack;  // Stack to store minimum elements
public:
    // Push element x onto stack
    void push(int x) {
        mainStack.push(x);
        // If minStack is empty or new element is smaller or equal, push it onto minStack
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }
    
    // Removes the element on top of the stack
    void pop() {
        if (mainStack.empty()) return;
        int topElement = mainStack.top();
        mainStack.pop();
        // If the popped element is the minimum, pop it from minStack as well
        if (topElement == minStack.top()) {
            minStack.pop();
        }
    }
    
    // Get the top element
    int top() {
        if (mainStack.empty()) return -1; // Return -1 if stack is empty
        return mainStack.top();
    }
    
    // Retrieve the minimum element in the stack
    int getMin() {
        if (minStack.empty()) return -1; // Return -1 if stack is empty
        return minStack.top();
    }
}; // Time Complexity: O(1) for all operations, Space Complexity: O(n) in worst case