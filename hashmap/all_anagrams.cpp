// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Function to find all anagrams of p in s
vector<int> findAnagrams(const string& s, const string& p) {
    vector<int> result;
    if (s.length() < p.length()) {
        return result;
    }

    unordered_map<char, int> pCount, sCount;
    for (char c : p) {
        pCount[c]++;
    }

    int windowSize = p.length();
    for (int i = 0; i < s.length(); ++i) {
        sCount[s[i]]++;

        // Remove the character going out of the window
        if (i >= windowSize) {
            char charToRemove = s[i - windowSize];
            if (sCount[charToRemove] == 1) {
                sCount.erase(charToRemove);
            } else {
                sCount[charToRemove]--;
            }
        }

        // Compare maps to check for an anagram
        if (sCount == pCount) {
            result.push_back(i - windowSize + 1);
        }
    }

    return result;
}


