// Count Number of words in a given string

#include <iostream>
#include <string>
using namespace std;

int countWords(const string& str) {
    int wordCount = 0;
    bool inWord = false; // Flag to track if we are inside a word

    for (char ch : str) {
        if (isspace(ch)) {
            // If we encounter a space and were in a word, we exit the word
            if (inWord) {
                inWord = false;
            }
        } else {
            // If we encounter a non-space character and were not in a word, we enter a word
            if (!inWord) {
                inWord = true;
                wordCount++; // Increment word count
            }
        }
    }
    return wordCount;
    // Time Complexity: O(N)
    // Space Complexity: O(1)
}