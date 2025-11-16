// Remove duplicate nodes from a sorted singly linked list

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to remove duplicates from a sorted linked list
void removeDuplicates(Node* head) {
    if (head == nullptr) return;

    Node* current = head;

    // Traverse the linked list
    while (current != nullptr && current->next != nullptr) {
        // If current node's data is the same as next node's data, skip the next node
        if (current->data == current->next->data) {
            Node* nodeToDelete = current->next;
            current->next = current->next->next; // Bypass the duplicate node
            delete nodeToDelete; // Free memory
        } else {
            current = current->next; // Move to the next node
        }
    }
    // Time Complexity: O(n)
    // Space Complexity: O(1)
}