// Calculate frequency of each character in a given string
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Brute Force Approach - O(N^2) time complexity
unordered_map<char, int> frequencyBruteForce(const string& str) {
    unordered_map<char, int> freqMap;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (freqMap.find(ch) == freqMap.end()) { // If character not already counted
            int count = 0;
            for (int j = 0; j < str.length(); j++) {
                if (str[j] == ch) {
                    count++;
                }
            }
            freqMap[ch] = count; // Store frequency in map
        }
    }
    return freqMap;
}

// Optimal Approach - O(N) time complexity
unordered_map<char, int> frequencyOptimal(const string& str) {
    unordered_map<char, int> freqMap;
    for (char ch : str) {
        freqMap[ch]++; // Increment frequency count for character
    }
    return freqMap; // Time Complexity: O(N)
}