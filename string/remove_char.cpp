// Remove all the characters except alphabets from a given string

#include <iostream>
#include <string>
using namespace std;
string removeNonAlphabets(const string& str) {
    string result;
    for (char ch : str) {
        if (isalpha(ch)) { // Check if character is an alphabet
            result += ch; // Append alphabetic character to result
        }
    }
    return result;
    // Time Complexity: O(N)
    // Space Complexity: O(N) for the result string
}