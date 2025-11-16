// Aggressive Cows:
// Problem Statement: Given positions of stalls and number of cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.
// https://leetcode.com/problems/aggressive-cows/

#include <vector>
#include <algorithm>
using namespace std;

// Function to check if it is possible to place 'cows' cows in 'stalls' with at least 'minDist' distance apart
bool canPlaceCows(const vector<int>& stalls, int cows, int minDist) {
    int count = 1; // Place the first cow in the first stall
    int lastPosition = stalls[0];

    for (size_t i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - lastPosition >= minDist) {
            count++; // Place another cow
            lastPosition = stalls[i];
            if (count == cows) {
                return true; // Successfully placed all cows
            }
        }
    }
    return false; // Not enough space to place all cows
}

// Function to find the largest minimum distance to place 'cows' cows in 'stalls' using binary search
int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end()); // Sort the stall positions

    int left = 1; // Minimum possible distance
    int right = stalls.back() - stalls.front(); // Maximum possible distance
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Midpoint distance

        if (canPlaceCows(stalls, cows, mid)) {
            result = mid; // Found a valid distance, try for a larger one
            left = mid + 1;
        } else {
            right = mid - 1; // Try a smaller distance
        }
    }
    return result; // Largest minimum distance found
}
