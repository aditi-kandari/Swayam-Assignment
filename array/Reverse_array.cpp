// Reverse the Array.
// Brute force approach to reverse an array in C++ using extra space
#include <iostream>
#include <vector>
using namespace std;
vector<int> reverseArray(vector<int>& arr){
    int n=arr.size();
    vector<int> reversedArr(n); // extra space for reversed array
    for(int i=0;i<n;i++){
        reversedArr[i]=arr[n-i-1];
    }
    return reversedArr;
}

// Optimal approach to reverse an array in C++ in-place
vector<int> reverseArrayInPlace(vector<int>& arr){
    int left=0;
    int right=arr.size()-1;
    while(left<right){
        swap(arr[left],arr[right]); // swapping elements in the original array
        left++;
        right--;
    }
    return arr;
}
