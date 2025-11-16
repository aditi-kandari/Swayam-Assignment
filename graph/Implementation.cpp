/*
Topic: Graph Introduction and Representation

A Graph is a collection of nodes (vertices) connected by edges.
It can be:
- Undirected or Directed
- Weighted or Unweighted

Graph Representations:
-----------------------
1. Adjacency Matrix: 
   - 2D array of size V x V.
   - matrix[i][j] = 1 if edge (i, j) exists, else 0.
   - Suitable for dense graphs.

2. Adjacency List:
   - Array (or vector) of lists.
   - adj[i] stores all nodes adjacent to vertex i.
   - Suitable for sparse graphs.

Time Complexity:
----------------
Adjacency Matrix: 
  - Space: O(V²)
  - Add Edge: O(1)
  - Check Edge: O(1)
  - Iterate Neighbors: O(V)

Adjacency List:
  - Space: O(V + E)
  - Add Edge: O(1)
  - Check Edge: O(degree(V))
  - Iterate Neighbors: O(degree(V))
*/

#include <iostream>
#include <vector>
using namespace std;

//Adjacency Matrix Representation 

class GraphMatrix {
    int V; // Number of vertices
    vector<vector<int>> adjMatrix;

public:
    GraphMatrix(int vertices) {
        V = vertices;
        adjMatrix = vector<vector<int>>(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, bool directed = false) {
        adjMatrix[u][v] = 1;
        if (!directed) adjMatrix[v][u] = 1;  // For undirected graph
    }

    vector<vector<int>> getMatrix() {
        return adjMatrix;
    }
};


//Adjacency List Representation

class GraphList {
    int V; // Number of vertices
    vector<vector<int>> adjList;

public:
    GraphList(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v, bool directed = false) {
        adjList[u].push_back(v);
        if (!directed) adjList[v].push_back(u);  // For undirected graph
    }

    vector<vector<int>> getList() {
        return adjList;
    }
};
