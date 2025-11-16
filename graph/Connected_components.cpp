/*
Problem Statement:
------------------
Given an undirected graph with V vertices and E edges,
find the number of connected components.

A connected component is a set of vertices that are connected
to each other by edges and not connected to any other vertex
outside the group.

Time Complexity: O(V + E)
Space Complexity: O(V)
*/

#include <iostream>
#include <vector>
using namespace std;

//DFS Helper Function :

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited);
    }
}

//Function to Count Connected Components :

int countConnectedComponents(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    int components = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited); // Explore this component
            components++;         // Increment count
        }
    }

    return components;
}
