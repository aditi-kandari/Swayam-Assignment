// Bulls and Cows : Given two numbers, the secret number and the friend's guess,
// return a hint to the friend about how many digits are in the correct position
// (bulls) and how many digits are in the wrong position (cows).

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Sliding Window + Hash Map Approach
string getHint(const string& secret, const string& guess) {
    vector<int> count(10, 0);
    int bulls = 0, cows = 0;

    for (size_t i = 0; i < secret.length(); ++i) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            if (count[secret[i] - '0'] < 0) cows++;
            if (count[guess[i] - '0'] > 0) cows++;
            count[secret[i] - '0']++;
            count[guess[i] - '0']--;
        }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
    // Time Complexity: O(n)
    // Space Complexity: O(1) since the size of the count array is fixed (10 digits)
}
