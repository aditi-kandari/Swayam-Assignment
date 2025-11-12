// Find the intersection of two arrays using hashmap
// Given two arrays, return their intersection.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;        
vector<int> arrayIntersection(const vector<int>& nums1, const vector<int>& nums2) {
    unordered_map<int, int> countMap; // Map to store frequency of elements in nums1
    vector<int> intersection; // Vector to store the intersection result

    // Count the frequency of each element in nums1
    for (int num : nums1) {
        countMap[num]++;
    }

    // Find the intersection with nums2
    for (int num : nums2) {
        if (countMap[num] > 0) {
            intersection.push_back(num); // Add to intersection
            countMap[num]--; // Decrease the count to handle duplicates
        }
    }
    return intersection; // Return the intersection result
    // O(n + m) time complexity, O(min(n, m)) space complexity
}