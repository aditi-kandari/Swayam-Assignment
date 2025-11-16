// Sort the array using Selection Sort algorithm
#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the minimum is the first element of unsorted part
        // Find the index of the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }
        // Swap the found minimum element with the first element of unsorted part
        swap(arr[i], arr[minIndex]);
    }
    // Time Complexity: O(N^2) for all cases (best, average, worst)
    // Space Complexity: O(1) as it is an in-place sorting algorithm
}