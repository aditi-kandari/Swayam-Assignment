// Implement hashmap in cpp with basic operations: insert, delete, search

#include <iostream>
#include <list> 
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>
using namespace std;

class HashMap {
private:
    static const int hashSize = 101; // A prime number for better distribution
    vector<list<pair<int, int>>> table;

    int hashFunction(int key) {
        return key % hashSize;
    }
public:
    HashMap() {
        table.resize(hashSize);
    }
    void insert(int key, int value) {
        int hashIndex = hashFunction(key);
        auto& cell = table[hashIndex];
        for (auto& pair : cell) {
            if (pair.first == key) {
                pair.second = value; // Update existing key
                return;
            }
        }
        cell.emplace_back(key, value); // Insert new key-value pair
    }
    void remove(int key) {
        int hashIndex = hashFunction(key);
        auto& cell = table[hashIndex];
        cell.remove_if([key](const pair<int, int>& p) { return p.first == key; });
    }
    int search(int key) {
        int hashIndex = hashFunction(key);
        auto& cell = table[hashIndex];
        for (const auto& pair : cell) {
            if (pair.first == key) {
                return pair.second; // Return value if key is found
            }
        }
        return -1; // Indicate that the key was not found
    }
};
