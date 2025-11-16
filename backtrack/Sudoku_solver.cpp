// Problem Statement:
// ------------------
// You are given a 9x9 Sudoku board represented by a 2D vector 'board',
// where each cell contains a digit '1'-'9' or '.' for an empty cell.

// The task is to fill the empty cells so that:
// 1. Each row contains digits 1-9 with no repetition.
// 2. Each column contains digits 1-9 with no repetition.
// 3. Each of the nine 3x3 sub-boxes contains digits 1-9 with no repetition.

// Assume the input board has only one valid solution.


#include <vector>
using namespace std;

// Function to check if placing a number is valid
bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        // Check row and column
        if (board[row][i] == num || board[i][col] == num)
            return false;

        // Check 3x3 subgrid
        int subRow = 3 * (row / 3) + i / 3;
        int subCol = 3 * (col / 3) + i % 3;
        if (board[subRow][subCol] == num)
            return false;
    }
    return true;
}

// Recursive backtracking function to solve Sudoku
bool solve(vector<vector<char>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {  // Empty cell found
                for (char num = '1'; num <= '9'; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;     // Place number
                        if (solve(board)) return true; // Recurse
                        board[row][col] = '.';     // Backtrack
                    }
                }
                return false;  // No valid number found, trigger backtrack
            }
        }
    }
    return true;  // All cells filled successfully
}

// Function to solve Sudoku board
void solveSudoku(vector<vector<char>>& board) {
    solve(board);  // Modifies board in place with the valid solution
}
