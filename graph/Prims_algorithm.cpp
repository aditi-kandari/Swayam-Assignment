/*
Problem Statement:

Given a connected, undirected, and weighted graph,
find the cost of its Minimum Spanning Tree (MST) using Prim’s Algorithm.

A Minimum Spanning Tree (MST) connects all vertices with the minimum
possible total edge weight, without forming cycles.

Time Complexity: O(E * logV)
Space Complexity: O(V + E)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Edge Representation
struct Edge {
    int weight;
    int node;
    Edge(int w, int n) : weight(w), node(n) {}
};

// Comparator for Min-Heap :
struct compare {
    bool operator()(Edge a, Edge b) {
        return a.weight > b.weight; // Min-heap based on weight
    }
};

// Prim’s Algorithm :
int primsMST(int V, vector<vector<pair<int, int>>>& adj) {
    vector<bool> inMST(V, false);  // Track included vertices
    priority_queue<Edge, vector<Edge>, compare> pq;

    pq.push(Edge(0, 0));  // Start from vertex 0 with weight 0
    int totalWeight = 0;

    while (!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();

        int u = curr.node;
        int w = curr.weight;

        if (inMST[u]) continue;  // Skip if already in MST
        inMST[u] = true;
        totalWeight += w;

        // Traverse adjacent vertices
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!inMST[v]) {
                pq.push(Edge(weight, v));
            }
        }
    }

    return totalWeight;
}
