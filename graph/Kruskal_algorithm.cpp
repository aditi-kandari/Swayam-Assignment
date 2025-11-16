/*
Problem Statement:

Given a connected, undirected, and weighted graph,
find the cost of its Minimum Spanning Tree (MST) using **Kruskal’s Algorithm**.

Kruskal’s algorithm sorts all edges in increasing order of weight
and picks the smallest edge that doesn’t form a cycle until all vertices
are connected.

Time Complexity: O(E * logE)
Space Complexity: O(V)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Disjoint Set (Union-Find) Implementation :
struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    // Find parent with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by rank
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[py] < rank[px]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

// Kruskal’s Algorithm :
int kruskalMST(int V, vector<vector<int>>& edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    });

    DSU dsu(V);
    int totalWeight = 0;

    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];

        // Include edge only if it doesn't form a cycle
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            totalWeight += w;
        }
    }

    return totalWeight;
}
