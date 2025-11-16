/*
Problem Statement:

Given a 2D grid consisting of '1's (land) and '0's (water),
find the number of islands.

An island is surrounded by water and is formed by connecting
adjacent lands horizontally or vertically.
*/

#include <iostream>
#include <vector>
using namespace std;

// DFS Helper Function :
void dfs(int i, int j, vector<vector<char>>& grid, int m, int n) {

    // Boundary and water check
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
        return;

    grid[i][j] = '0'; // Mark as visited (sink the island)

    // Explore 4 directions
    dfs(i + 1, j, grid, m, n);
    dfs(i - 1, j, grid, m, n);
    dfs(i, j + 1, grid, m, n);
    dfs(i, j - 1, grid, m, n);
}

// Function to Count Islands :
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();

    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {   // Found new island
                dfs(i, j, grid, m, n); // Mark all connected land
                count++;
            }
        }
    }
    return count;
}
