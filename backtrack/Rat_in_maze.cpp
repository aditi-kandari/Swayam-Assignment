// A rat is placed at the starting cell (0,0) of a square maze of size N x N. 
// The maze is represented as a binary matrix where:
//     - 1 indicates a path (rat can move)
//     - 0 indicates a wall (rat cannot move)
// The rat can move in four directions: up, down, left, and right.
// The task is to find one or all possible paths from the source (0,0) 
// to the destination (N-1,N-1), using backtracking.
// Return or print all paths where 1 represents the path taken by the rat.

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>>& maze, vector<vector<int>>& visited) {
    // Check boundaries and if cell is a path and not visited
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && visited[x][y] == 0);
}

// Backtracking function

bool solveMaze(vector<vector<int>>& maze, int x, int y, int n, vector<vector<int>>& visited) {
    // Base case: destination reached
    if (x == n - 1 && y == n - 1) {
        visited[x][y] = 1;
        return true;
    }

    if (isSafe(x, y, n, maze, visited)) {
        visited[x][y] = 1;  // Mark as part of solution path

        // Move Down
        if (solveMaze(maze, x + 1, y, n, visited))
            return true;

        // Move Right
        if (solveMaze(maze, x, y + 1, n, visited))
            return true;

        // Move Up
        if (solveMaze(maze, x - 1, y, n, visited))
            return true;

        // Move Left
        if (solveMaze(maze, x, y - 1, n, visited))
            return true;

        // Backtrack — unmark this cell
        visited[x][y] = 0;
        return false;
    }

    return false;
}

int main() {
    int n = 4;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    vector<vector<int>> visited(n, vector<int>(n, 0));

    if (solveMaze(maze, 0, 0, n, visited)) {
        cout << "Path found:\n";
    } 
    else {
        cout << "No path exists.\n";
    }

    return 0;
}