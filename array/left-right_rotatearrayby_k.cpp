// Rotate the Array by K Positions to the Left and Right
#include <iostream> 
#include <vector>
using namespace std;

// Brute force approach to rotate an array by k positions to the left using extra space
vector<int> rotateArrayLeft(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> rotatedArr(n); // extra space for rotated array
    for (int i = 0; i < n; i++) {
        rotatedArr[i] = arr[(i + k) % n]; // placing elements in rotated positions (N time complexity)
    }
    return rotatedArr;
}

// Brute force approach to rotate an array by k positions to the right using extra space
vector<int> rotateArrayRight(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> rotatedArr(n); // extra space for rotated array
    for (int i = 0; i < n; i++) {
        rotatedArr[i] = arr[(i - k + n) % n]; // placing elements in rotated positions (N time complexity)
    }
    return rotatedArr;
} 
 
//Optimal approach to rotate an array by k positions to the left in-place
vector<int> rotateArrayLeftOptimal(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // in case k is greater than n
    reverse(arr.begin(), arr.begin() + k); // reverse first k elements
    reverse(arr.begin() + k, arr.end()); // reverse remaining n-k elements
    reverse(arr.begin(), arr.end()); // reverse the whole array
    return arr;
}

//Optimal approach to rotate an array by k positions to the right in-place
vector<int> rotateArrayRightOptimal(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // in case k is greater than n
    reverse(arr.begin(), arr.end()); // reverse the whole array
    reverse(arr.begin(), arr.begin() + k); // reverse first k elements
    reverse(arr.begin() + k, arr.end()); // reverse remaining n-k elements
    return arr;
}

