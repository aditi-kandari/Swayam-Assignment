/*
Topic: Graph Traversal Algorithms (BFS and DFS):
Graph traversal means visiting all the vertices of a graph systematically.

Two main types:
1. Breadth-First Search (BFS)
   - Level-order traversal using a queue (FIFO).
   - Explores neighbors before moving to the next level.
   - Useful for finding the shortest path in unweighted graphs.

2. Depth-First Search (DFS)
   - Explores as far as possible along each branch before backtracking.
   - Implemented using recursion or stack.

Input Representation:
---------------------
We assume the graph is represented using an adjacency list.

Time Complexity:
----------------
BFS: O(V + E)
DFS: O(V + E)

Space Complexity:
-----------------
O(V) — for visited array and recursion/queue.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS Traversal
vector<int> bfsTraversal(int V, vector<vector<int>>& adj) {
    vector<int> bfs;                // Stores BFS order
    vector<bool> visited(V, false); // Track visited nodes
    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {          // Handle disconnected graphs
            visited[i] = true;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                // Traverse all adjacent nodes
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }

    return bfs;
}


//DFS Traversal
void dfsHelper(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& dfs) {
    visited[node] = true;
    dfs.push_back(node);

    // Recur for all unvisited adjacent nodes
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited, dfs);
        }
    }
}

vector<int> dfsTraversal(int V, vector<vector<int>>& adj) {
    vector<int> dfs;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) { // Handle disconnected graphs
            dfsHelper(i, adj, visited, dfs);
        }
    }

    return dfs;
}
