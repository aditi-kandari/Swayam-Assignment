// Find the kth smallest elemnt in the array using max_heap;

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// function to find the kth smallest element
int findKthSmallest(const vector<int>& nums, int k) {
    priority_queue<int> maxHeap; // max-heap

    for (int num : nums) {
        maxHeap.push(num); // insert into max-heap
        if (maxHeap.size() > k) {
            maxHeap.pop(); // remove largest element
        }
    }
    return maxHeap.top(); // kth smallest element
}