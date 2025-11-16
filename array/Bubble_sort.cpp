// Sort the elements of an array using the Bubble Sort algorithm
#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already sorted, no need to check them
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // swapping elements
            }
        }
    }
    // Time Complexity: O(N^2) in the worst and average case, O(N) in the best case (when the array is already sorted)
    // space complexity: O(1)
}