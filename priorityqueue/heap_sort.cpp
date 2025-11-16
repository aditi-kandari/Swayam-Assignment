// Inplace sort given array using heap sort

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Heap Sort function
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left; // left child is larger

    if (right < n && arr[right] > arr[largest])
        largest = right; // right child is larger

    if (largest != i) {
        swap(arr[i], arr[largest]); // swap root with largest
        heapify(arr, n, largest); // recursively heapify the affected sub-tree
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i); // build heap

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // move current root to end
        heapify(arr, i, 0); // call heapify on the reduced heap
    }
}
