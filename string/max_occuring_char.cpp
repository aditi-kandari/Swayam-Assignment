// Find the maximum occurring character in a string

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Brute Force Approach - O(N^2) time complexity
char maxOccurringCharBruteForce(const string& str) {
    int maxCount = 0;
    char maxChar = '\0';
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];  // Each character to count O(N)
        int count = 0;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == ch) {
                count++; // Count occurrences of ch O(N)
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxChar = ch;
        }
    }
    return maxChar;
}

// Optimal Approach - O(N) time complexity
char maxOccurringCharOptimal(const string& str) {
    unordered_map<char, int> freqMap;
    int maxCount = 0;
    char maxChar = '\0';
    for (char ch : str) {
        freqMap[ch]++; // Increment frequency count for character
        if (freqMap[ch] > maxCount) {
            maxCount = freqMap[ch];
            maxChar = ch;
        }
    }
    return maxChar; // Time Complexity: O(N)
}