// Find the maximum and minimum element in the array.
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
// Brute force approach to find max and min in an array using extra space
pair<int,int> findMaxMinBruteForce(vector<int>& arr){
    int n=arr.size();
    vector<int> sortedArr=arr; // extra space for sorted array
    sort(sortedArr.begin(),sortedArr.end()); // sorting the array (NlogN time complexity)
    int maxElement=sortedArr[n-1]; 
    int minElement=sortedArr[0];
    return {maxElement,minElement};
} 

// Optimal approach to find max and min in an array in a single traversal (no sorting)
pair<int,int> findMaxMinOptimal(vector<int>& arr){
    int maxElement=arr[0];
    int minElement=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]>maxElement){
            maxElement=arr[i]; // finding the maximum
        }
        else if(arr[i]<minElement){
            minElement=arr[i]; // finding the minimum
        }
    }
    return {maxElement,minElement};
}

