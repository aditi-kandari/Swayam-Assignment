// Count the element with maximum frequency in an array
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;        

// Brute force approach to count the max frequency element using nested loops
int countMaxFreqElement(vector<int>& arr) {
    int n = arr.size();
    int maxCount = 0;
    int maxFreqElement = arr[0];
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++; // counting occurrences of arr[i] (N^2 time complexity)
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxFreqElement = arr[i];
        }
    }
    return maxFreqElement;
}
 
// Optimal approach to count the max frequency element using hash map
int countMaxFreqElement(vector<int>& arr) { 
    unordered_map<int, int> freqMap;
    int maxCount = 0;
    int maxFreqElement = arr[0];
    for (int num : arr) {
        freqMap[num]++; // counting occurrences using hash map (N time complexity)
        if (freqMap[num] > maxCount) {
            maxCount = freqMap[num];
            maxFreqElement = num;
        }
    }
    return maxFreqElement;
}