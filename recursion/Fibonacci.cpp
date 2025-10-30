// Find the nth Fibonnacci number using recursion

#include <iostream>
using namespace std;
int fibonacci(int n) {
    if (n <= 0) {
        return 0; // Base case: Fibonacci(0) = 0
    }
    if (n == 1) {
        return 1; // Base case: Fibonacci(1) = 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    // Time Complexity: O(2^n)
    // Space Complexity: O(n) due to call stack
}