// Problem Statement:
// Given a string 's' and a dictionary of words 'wordDict',
// determine if 's' can be segmented into a space-separated sequence 
// of one or more dictionary words.

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// Function to check if the string can be segmented into dictionary words
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;  // Base case: empty string

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            // Check if substring s[j..i-1] is in dict and prefix till j is valid
            if (dp[j] && dict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;  // No need to check further
            }
        }
    }
    return dp[n];
}
