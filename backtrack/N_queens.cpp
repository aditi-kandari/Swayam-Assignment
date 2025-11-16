// Problem Statement:
// ------------------
// The N-Queens problem is to place N queens on an N x N chessboard 
// such that no two queens attack each other.
// Rules:
// - A queen can attack another queen if they share the same row, column, or diagonal.
// - The goal is to find all valid configurations of queens on the board.


#include <vector>
#include <string>
using namespace std;

// Helper function to check if placing a queen is safe

bool isSafe(int row, int col, int n, vector<string>& board) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

// Recursive backtracking function
void solve(int row, int n, vector<string>& board, vector<vector<string>>& result) {
    // Base case: All queens placed
    if (row == n) {
        result.push_back(board);
        return;
    }

    // Try placing queen in each column
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n, board)) {
            board[row][col] = 'Q';        // Place queen
            solve(row + 1, n, board, result); // Recur for next row
            board[row][col] = '.';        // Backtrack
        }
    }
}

// Function to return all possible N-Queens solutions

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    solve(0, n, board, result);
    return result;  // Return all valid board configurations
}
