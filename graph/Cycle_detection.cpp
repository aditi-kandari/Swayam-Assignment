/*
Problem Statement :

Given a graph (either directed or undirected), determine 
whether it contains a cycle.

Time Complexity: O(V + E)
Space Complexity: O(V)
*/

#include <iostream>
#include <vector>
using namespace std;


//Cycle Detection in UNDIRECTED Graph using DFS :

bool dfsUndirected(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfsUndirected(neighbor, node, adj, visited))
                return true;
        }
        else if (neighbor != parent) {
            return true; // Cycle found
        }
    }
    return false;
}

bool hasCycleUndirected(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsUndirected(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}


//Cycle Detection in DIRECTED Graph using DFS :

bool dfsDirected(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& pathVisited) {
    visited[node] = true;
    pathVisited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfsDirected(neighbor, adj, visited, pathVisited))
                return true;
        }
        else if (pathVisited[neighbor]) {
            return true; // Found a back edge → cycle
        }
    }

    pathVisited[node] = false; // Backtrack
    return false;
}

bool hasCycleDirected(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    vector<bool> pathVisited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsDirected(i, adj, visited, pathVisited))
                return true;
        }
    }
    return false;
}
