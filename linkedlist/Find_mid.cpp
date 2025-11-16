// Find the middle node of a singly linked list

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Brute Force Approach: O(n) time complexity and O(1) space complexity
Node* findMiddleBruteForce(Node* head) {
    if (head == nullptr) return nullptr;

    int count = 0;
    Node* current = head;

    // Count the number of nodes in the linked list
    while (current != nullptr) {
        count++;
        current = current->next;
    }

    int midIndex = count / 2;
    current = head;

    // Traverse to the middle node
    for (int i = 0; i < midIndex; ++i) {
        current = current->next;
    }

    return current; // Return the middle node
}

// Optimized Approach: O(n) time complexity and O(1) space complexity (Turtle and Hare Algorithm)
Node* findMiddleOptimized(Node* head) {
    if (head == nullptr) return nullptr;

    Node* slow = head;
    Node* fast = head;

    // Move fast pointer two steps and slow pointer one step
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // Slow pointer will be at the middle node
}