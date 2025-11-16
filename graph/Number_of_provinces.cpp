/*
Problem Statement:
------------------
There are 'n' cities connected by some number of roads.
A province is a group of directly or indirectly connected cities,
and no other cities outside the group are connected to them.

You are given an n x n matrix `isConnected` where:
- isConnected[i][j] = 1 if city i and city j are directly connected
- isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Time Complexity: O(N²)
Space Complexity: O(N)
*/

#include <iostream>
#include <vector>
using namespace std;

// DFS Helper Function :
void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited, int n) {
    visited[node] = true;

    for (int j = 0; j < n; j++) {
        // If city j is connected and not visited, explore it
        if (isConnected[node][j] == 1 && !visited[j]) {
            dfs(j, isConnected, visited, n);
        }
    }
}

// Function to Count Number of Provinces :
int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, isConnected, visited, n);  // Explore all cities in this province
            provinces++;                       // Increment province count
        }
    }

    return provinces;
}
