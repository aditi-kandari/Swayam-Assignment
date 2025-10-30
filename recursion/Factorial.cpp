// Find the factorial of a number using recursion

#include <iostream>
using namespace std;
int factorial(int n) {
    if (n <= 1) {
        return 1; // Base case
    }
    return n * factorial(n - 1); // Recursive case
    // Time Complexity: O(n)
    // Space Complexity: O(n) due to call stack
}
