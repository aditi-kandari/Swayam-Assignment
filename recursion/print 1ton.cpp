// Print 1 to n using recursion

#include <iostream>
using namespace std;
void print1ToN(int n) {
    if (n == 0) {
        return; // Base case
    }
    print1ToN(n - 1); // Recursive call
    cout << n << " "; // Print after the recursive call to ensure correct order



    
    // Time Complexity: O(n)
    // Space Complexity: O(n) due to call stack
}