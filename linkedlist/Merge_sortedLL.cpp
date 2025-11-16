// Merge two sorted linked lists and return it as a new sorted list.

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* l1, Node* l2) {
    // Create a dummy node to help with the merge process
    Node dummy(0);
    Node* tail = &dummy;

    // Traverse both lists and append the smaller value to the merged list
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // If there are remaining nodes in either list, append them
    if (l1 != nullptr) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return dummy.next; // Return the merged list, which starts from dummy.next
}