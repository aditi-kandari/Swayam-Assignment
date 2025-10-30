//  count the number of digits in n that divide n evenly 

#include <iostream>
using namespace std;
int countDividingDigits(int n, int originalN) {
    // Base case: if n is 0, return 0
    if (n == 0) {
        return 0;
    }
    int lastDigit = n % 10; // Extract the last digit
    int count = 0;
    // Check if the last digit is not zero and divides originalN evenly
    if (lastDigit != 0 && originalN % lastDigit == 0) {
        count = 1; // Increment count if it divides evenly
    }
    // Recursive call with the remaining digits
    return count + countDividingDigits(n / 10, originalN);
    // Time Complexity: O(d) where d is the number of digits in n
    // Space Complexity: O(d) due to call stack
}