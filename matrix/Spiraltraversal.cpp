// Print the elements of a matrix in spiral order

#include <iostream>
#include <vector>
using namespace std;
void spiralTraversal(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; ++i) {
            cout << matrix[top][i] << " ";
        }
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; ++i) {
            cout << matrix[i][right] << " ";
        }
        right--;

        if (top <= bottom) {
            // Traverse from right to left
            for (int i = right; i >= left; --i) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        if (left <= right) {
            // Traverse from bottom to top
            for (int i = bottom; i >= top; --i) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
    cout << endl;
}
