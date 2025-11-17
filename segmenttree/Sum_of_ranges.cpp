/*
Segment Tree with Lazy Propagation

Used for efficient range updates and range sum queries.

- Build: O(n)
- Update: O(log n)
- Query: O(log n)
*/

#include <iostream>
#include <vector>
using namespace std;

class LazySegmentTree {
    vector<int> seg, lazy;
    int n;

public:
    // Constructor
    LazySegmentTree(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);
        lazy.resize(4 * n, 0);
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

    // Range Update: add 'val' to all elements in [l, r]
    void updateRange(int idx, int low, int high, int l, int r, int val) {
        // Apply pending updates
        if (lazy[idx] != 0) {
            seg[idx] += (high - low + 1) * lazy[idx];
            if (low != high) {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        // No overlap
        if (r < low || high < l) return;

        // Complete overlap
        if (l <= low && high <= r) {
            seg[idx] += (high - low + 1) * val;
            if (low != high) {
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
            }
            return;
        }

        // Partial overlap
        int mid = (low + high) / 2;
        updateRange(2 * idx + 1, low, mid, l, r, val);
        updateRange(2 * idx + 2, mid + 1, high, l, r, val);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    // Range Query: sum in [l, r]
    int queryRange(int idx, int low, int high, int l, int r) {
        // Apply pending updates
        if (lazy[idx] != 0) {
            seg[idx] += (high - low + 1) * lazy[idx];
            if (low != high) {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        // No overlap
        if (r < low || high < l) return 0;

        // Complete overlap
        if (l <= low && high <= r) return seg[idx];

        // Partial overlap
        int mid = (low + high) / 2;
        int left = queryRange(2 * idx + 1, low, mid, l, r);
        int right = queryRange(2 * idx + 2, mid + 1, high, l, r);
        return left + right;
    }

    // Helper functions
    void rangeUpdate(int l, int r, int val) { updateRange(0, 0, n - 1, l, r, val); }
    int rangeSum(int l, int r) { return queryRange(0, 0, n - 1, l, r); }
};

