/*
Problem Statement:

Given a 2D grid where:
- 0 represents land
- 1 represents water

A "closed island" is a group of 0s completely surrounded by 1s on all sides
(including diagonally not allowed) and does not touch the boundary.

Return the number of closed islands.

Time Complexity: O(M * N)
Space Complexity: O(M * N)
*/

#include <iostream>
#include <vector>
using namespace std;

// DFS Helper Function :
bool dfs(int i, int j, vector<vector<int>>& grid, int m, int n) {
    // If we reach boundary → not closed
    if (i < 0 || j < 0 || i >= m || j >= n)
        return false;

    if (grid[i][j] == 1)
        return true; // Water cell → valid boundary path

    grid[i][j] = 1; // Mark as visited

    // Explore 4 directions
    bool up = dfs(i - 1, j, grid, m, n);
    bool down = dfs(i + 1, j, grid, m, n);
    bool left = dfs(i, j - 1, grid, m, n);
    bool right = dfs(i, j + 1, grid, m, n);

    // If all directions return true → island is closed
    return up && down && left && right;
}

// Function to Count Closed Islands :
int closedIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) { // Found unvisited land
                if (dfs(i, j, grid, m, n))
                    count++; // Count only fully closed islands
            }
        }
    }

    return count;
}
