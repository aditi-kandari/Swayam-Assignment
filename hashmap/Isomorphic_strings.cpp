// Find wether two strings are isomorphic

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Function to check if two strings are isomorphic
bool areIsomorphic(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    unordered_map<char, char> mapS1toS2;
    unordered_map<char, char> mapS2toS1;

    for (size_t i = 0; i < s1.length(); ++i) {
        char char1 = s1[i];
        char char2 = s2[i];

        // Check mapping from s1 to s2
        if (mapS1toS2.find(char1) != mapS1toS2.end()) {
            if (mapS1toS2[char1] != char2) {
                return false;
            }
        } else {
            mapS1toS2[char1] = char2;
        }

        // Check mapping from s2 to s1
        if (mapS2toS1.find(char2) != mapS2toS1.end()) {
            if (mapS2toS1[char2] != char1) {
                return false;
            }
        } else {
            mapS2toS1[char2] = char1;
        }
    }

    return true;
}