// Search a node in singly linked list

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Optimize approach : O(n) time complexity
bool searchNode(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return true; // Key found
        }
        current = current->next;
    }
    return false; // Key not found
}