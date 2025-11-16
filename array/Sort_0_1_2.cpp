// Sort the array consisting of only 0s, 1s and 2s in a single traversal using Dutch National Flag Algorithm.

#include <iostream>
#include <vector>
using namespace std;

// Function to sort the array 
// Intuition: Use three pointers to partition the array into three sections for 0s, 1s, and 2s.
void sort012(vector<int>& arr) {
    int low = 0;               // Pointer for next position of 0
    int mid = 0;               // Current element under consideration
    int high = arr.size() - 1; // Pointer for next position of 2

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    // The array is now sorted in-place
    // Time Complexity: O(n)
}