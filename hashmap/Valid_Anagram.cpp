// Valid Anagram : Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// function to check if two strings are anagrams
bool isAnagram(const string& s, const string& t) {
    if (s.length() != t.length()) {
        return false; // If lengths differ, they cannot be anagrams
    }

    unordered_map<char, int> charCount; // Map to store character counts

    // Count characters in the first string
    for (char ch : s) {
        charCount[ch]++;
    }

    // Decrease counts based on the second string
    for (char ch : t) {
        charCount[ch]--;
        if (charCount[ch] < 0) {
            return false; // More occurrences in t than in s
        }
    }

    return true; // All counts are zero, so they are anagrams
    // O(n) time complexity, O(1) space complexity since the character set is fixed (ASCII)
}