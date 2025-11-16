// Koko eating bananas:
// https://leetcode.com/problems/koko-eating-bananas/

#include <vector>
#include <algorithm>
using namespace std;

// Funtion to check if Koko can eat all bananas at speed 'k' within 'h' hours
bool canEatAll(const vector<int>& piles, int k, int h) {
    int hoursNeeded = 0;
    for (int pile : piles) {
        hoursNeeded += (pile + k - 1) / k; // Equivalent to ceil(pile / k)
    }
    return hoursNeeded <= h;
}
// Function to find the minimum eating speed Koko needs to finish all bananas within 'h' hours using binary search
int minEatingSpeed(const vector<int>& piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canEatAll(piles, mid, h)) {
            result = mid; // Found a valid speed, try for a smaller one
            right = mid - 1;
        } else {
            left = mid + 1; // Increase speed
        }
    }
    return result;
}