/*
Segment Tree for Range Maximum Query
------------------------------------
Supports:
1️⃣ Build Tree for max in interval
2️⃣ Query max in range [L, R]
3️⃣ Update single element

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
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    // Build tree (stores max of each segment)
    void build(int idx, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    // Query maximum in range [l, r]
    int query(int idx, int low, int high, int l, int r) {
        if (r < low || high < l) return INT_MIN;              // No overlap
        if (l <= low && high <= r) return seg[idx];           // Complete overlap
        int mid = (low + high) / 2;                           // Partial overlap
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return max(left, right);
    }

    // Update element at position pos
    void update(int idx, int low, int high, int pos, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (pos <= mid) update(2 * idx + 1, low, mid, pos, val);
        else update(2 * idx + 2, mid + 1, high, pos, val);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    // Helper functions
    int rangeMaxQuery(int l, int r) { return query(0, 0, n - 1, l, r); }
    void pointUpdate(int pos, int val) { update(0, 0, n - 1, pos, val); }
};

/*
Example:
vector<int> arr = {2, 5, 1, 4, 9, 3};
SegmentTree st(arr);
cout << st.rangeMaxQuery(1, 4); // Output: 9
st.pointUpdate(2, 10);
cout << st.rangeMaxQuery(1, 4); // Output: 10
*/
