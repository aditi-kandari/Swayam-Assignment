/*
Problem Statement:
------------------
Given a directed graph and two vertices `src` (source) and `dest` (destination),
find all possible paths from `src` to `dest`.

Time Complexity: O(V + E) on average per path  
Space Complexity: O(V) for recursion stack
*/

#include <iostream>
#include <vector>
using namespace std;

// DFS Helper to Find All Paths :
void dfsAllPaths(int node, int dest, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& path, vector<vector<int>>& allPaths) {
    visited[node] = true;
    path.push_back(node);

    if (node == dest) {
        allPaths.push_back(path);  // Found a valid path
    } else {
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsAllPaths(neighbor, dest, adj, visited, path, allPaths);
            }
        }
    }

    // Backtrack
    path.pop_back();
    visited[node] = false;
}

// Function to Get All Paths :
vector<vector<int>> allPathsFromSrcToDest(int V, vector<vector<int>>& adj, int src, int dest) {
    vector<bool> visited(V, false);
    vector<int> path;
    vector<vector<int>> allPaths;
    dfsAllPaths(src, dest, adj, visited, path, allPaths);
    return allPaths;
}
