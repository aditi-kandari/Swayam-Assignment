/*
Problem Statement:

Given a directed graph and two vertices `src` (source) and `dest` (destination),
determine whether there exists a path from `src` to `dest`.

Time Complexity: O(V + E)
Space Complexity: O(V)
*/

#include <iostream>
#include <vector>
using namespace std;

//DFS Helper :
bool dfs(int node, int dest, vector<vector<int>>& adj, vector<bool>& visited) {
    if (node == dest) return true;  // Path found
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, dest, adj, visited))
                return true;        // Path found in recursion
        }
    }
    return false;
}

//Function to Check Path Existence :
bool hasPath(int V, vector<vector<int>>& adj, int src, int dest) {
    vector<bool> visited(V, false);
    return dfs(src, dest, adj, visited);
}
