
// Count the number of vowels and consonants in a given string

#include <iostream>
#include <string>
using namespace std;
pair<int, int> countVowelsAndConsonants(const string& str) {
    int vowels = 0;
    int consonants = 0;
    for (char ch : str) {
        if (isalpha(ch)) { // Check if character is an alphabet
            char lowerCh = tolower(ch); // Convert to lowercase for uniformity
            if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    return {vowels, consonants};
    // Time Complexity: O(N)
    // Space Complexity: O(1)
}
