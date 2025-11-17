/*
Segment Tree for Range Sum Query

Time Complexity:
- Build: O(n)
- Query: O(log n)
- Update: O(log n)
*/

#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> seg;
    int n;

public:
    // Constructor → initializes tree and builds from array
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    // Build the segment tree
    void build(int idx, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    // Query sum in range [l, r]
    int query(int idx, int low, int high, int l, int r) {
        if (r < low || high < l) return 0;               // No overlap
        if (l <= low && high <= r) return seg[idx];      // Complete overlap
        int mid = (low + high) / 2;                      // Partial overlap
        return query(2 * idx + 1, low, mid, l, r) + query(2 * idx + 2, mid + 1, high, l, r);
    }

    // Update single element at index 'pos'
    void update(int idx, int low, int high, int pos, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (pos <= mid) update(2 * idx + 1, low, mid, pos, val);
        else update(2 * idx + 2, mid + 1, high, pos, val);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    // Helper functions for user
    int rangeSum(int l, int r) { return query(0, 0, n - 1, l, r); }
    void pointUpdate(int pos, int val) { update(0, 0, n - 1, pos, val); }
};


