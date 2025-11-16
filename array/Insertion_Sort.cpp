// Sort The elements of an array using the Insertion Sort algorithm
#include <iostream>
#include <vector>
using namespace std;
void insertionsort(vector<int> arr){
    int n=arr.size();
    // Traverse through 1 to n
    for(int i=1;i<n;i++){
        int key=arr[i]; // current element to be inserted
        int j=i-1;
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j]; // shifting element to the right
            j--;
        }
        arr[j+1]=key; // placing key at its correct position
    }
    // Time Complexity: O(N^2) in the worst and average case, O(N) in the best case (when the array is already sorted)
    // Space Complexity: O(1) as it is an in-place sorting algorithm
}