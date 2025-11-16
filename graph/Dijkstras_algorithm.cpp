/*
Problem Statement:
------------------
Given a weighted, directed graph and a source vertex 'src',
find the shortest distance from 'src' to all other vertices using

Time Complexity: O(E * logV)
Space Complexity: O(V + E)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

// Dijkstra’s Algorithm :
vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(V, INT_MAX);  // Distance array
    dist[src] = 0;

    // Min-heap: (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Skip if already processed with smaller distance
        if (d > dist[node]) continue;

        // Traverse all adjacent nodes
        for (auto& edge : adj[node]) {
            int next = edge.first;
            int weight = edge.second;

            // Relax edge if shorter path found
            if (dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    return dist; // Return shortest distances from src
}
