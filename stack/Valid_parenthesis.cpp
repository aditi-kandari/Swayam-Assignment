// Check the validity of a string of parentheses

#include <iostream>
#include <stack>
using namespace std;

// Function to check if the parentheses are valid
bool isValidParenthesis(const string& s) {
    stack<char> st; // Stack to keep track of opening parentheses

    for (char ch : s) {
        // If it's an opening bracket, push it onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } 
        // If it's a closing bracket, check for matching opening bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) {
                return false; // No matching opening bracket
            }
            char top = st.top();
            st.pop();
            // Check if the types of brackets match
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // Mismatched brackets
            }
        }
    }
    return st.empty(); // If stack is empty, all brackets were matched
}   // Time Complexity: O(n), Space Complexity: O(n)