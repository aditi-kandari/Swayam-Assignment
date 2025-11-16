// find the kth largest element in an array using a min-heap

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// function to find the kth largest element
int findKthLargest(const vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap

    for (int num : nums) {
        minHeap.push(num); // insert into min-heap
        if (minHeap.size() > k) {
            minHeap.pop(); // remove smallest element
        }
    }
    return minHeap.top(); // kth largest element
} 