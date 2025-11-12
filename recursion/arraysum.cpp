// Find the Sum of Elements in an Array using Recursion

#include <iostream> 
using namespace std;
int arraySum(int arr[], int n) {
    if (n <= 0) {
        return 0; // Base case: if array size is 0, sum is 0
    }
    return arr[n - 1] + arraySum(arr, n - 1); // Recursive case
    // Time Complexity: O(n) where n is the number of elements in the array
    // Space Complexity: O(n) due to call stack
}
