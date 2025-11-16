// Find all repeating elements in an array
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Brute force approach to find repeating elements using nested loops
vector<int> findRepeatingBruteForce(vector<int>& arr) {
    int n = arr.size();
    vector<int> repeatingElements;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                // Check if already added to avoid duplicates in result
                if (find(repeatingElements.begin(), repeatingElements.end(), arr[i]) == repeatingElements.end()) {
                    repeatingElements.push_back(arr[i]); // adding repeating element (N^2 time complexity)
                }
            }
        }
    }
    return repeatingElements;
}

// Better approach to find repeating elements using sorting
vector<int> findRepeatingSorting(vector<int>& arr) {
    int n = arr.size();
    vector<int> sortedArr = arr; // extra space for sorted array
    sort(sortedArr.begin(), sortedArr.end()); // sorting the array (NlogN time complexity)
    vector<int> repeatingElements;
    for (int i = 1; i < n; i++) {
        if (sortedArr[i] == sortedArr[i - 1]) {
            // Check if already added to avoid duplicates in result
            if (find(repeatingElements.begin(), repeatingElements.end(), sortedArr[i]) == repeatingElements.end()) {
                repeatingElements.push_back(sortedArr[i]); // adding repeating element
            }
        }
    }
    return repeatingElements;
}

// optimal approach to find repeating elements using hash map
vector<int> findRepeatingOptimal(vector<int>& arr){
    unordered_map<int,int> freqMap;
    vector<int> repeatingElements;
    for(int num : arr){
        freqMap[num]++; // counting occurrences using hash map (N time complexity)
    }
    for(const auto& pair : freqMap){
        if(pair.second > 1){
            repeatingElements.push_back(pair.first); // adding repeating element
        }
    }
    return repeatingElements;
}
    