// Rotate the given linked list to the left by k places

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to rotate the linked list to the left by k places
Node* rotateLeft(Node* head, int k) {
    if (head == nullptr || k == 0) return head;

    // Compute the length of the linked list
    Node* current = head;
    int length = 1; // Start with 1 to count the head node
    while (current->next != nullptr) {
        current = current->next;
        length++;
    }

    // If k is greater than length, rotate only the remainder
    k = k % length;
    if (k == 0) return head; // No rotation needed

    // Connect the last node to the head to make it circular
    current->next = head;

    // Find the new tail: (length - k)th node
    Node* newTail = head;
    for (int i = 1; i < length - k; ++i) {
        newTail = newTail->next;
    }

    // The new head is the next of new tail
    Node* newHead = newTail->next;

    // Break the circular link
    newTail->next = nullptr;

    return newHead; // Return the new head of the rotated list
    // Time Complexity: O(n)
    // Space Complexity: O(1)
}