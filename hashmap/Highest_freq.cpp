// Find the character with the highest frequency in a given string using hashmap

#include <iostream>
#include <string>
#include <map>
using namespace std;

// Function to find the character with the highest frequency
char highestFrequencyChar(const string& str) {
    map<char, int> freqMap; // Map to store frequency of each character
    for (char ch : str) {
        freqMap[ch]++; // Increment the frequency count for the character
    }

    char maxChar = '\0';
    int maxFreq = 0;
    for (const auto& pair : freqMap) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            maxChar = pair.first;
        }
    }
    return maxChar; // Return the character with the highest frequency
}