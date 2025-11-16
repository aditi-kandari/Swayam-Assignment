// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

#include <iostream>
#include <vector>
#include <unordered_map>   
#include <queue>
using namespace std;

// function to find the k most frequent elements
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequencyMap;
    for (int num : nums) {
        frequencyMap[num]++;
    }

    // Min-heap to store the k most frequent elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (const auto& entry : frequencyMap) {
        minHeap.push({entry.second, entry.first});
        if (minHeap.size() > k) {
            minHeap.pop(); // remove the least frequent element
        }
    }

    vector<int> result;
    // extract elements from the min-heap
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    
    return result; // return the k most frequent elements
}
