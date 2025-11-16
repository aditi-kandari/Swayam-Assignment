/*
Problem Statement:
------------------
Given a weighted, directed graph with possibly negative edge weights,
find the shortest distance from a source vertex 'src' to all other vertices
using Bellman-Ford Algorithm.

If the graph contains a negative weight cycle, report it.

Time Complexity: O(V * E)
Space Complexity: O(V)
*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Bellman-Ford Algorithm :
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges (V - 1) times
    for (int i = 1; i < V; i++) {
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains a negative weight cycle\n";
            return {};
        }
    }

    return dist; // Return shortest distances from src
}
