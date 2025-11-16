// Add two numbers represented by linked list in reverse order

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to add two numbers represented by linked lists
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummyHead = new Node(0); // Dummy node to simplify addition
    Node* current = dummyHead;
    int carry = 0;

    // Traverse both lists
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry; // Start with carry from previous addition

        if (l1 != nullptr) {
            sum += l1->data; // Add value from first list
            l1 = l1->next;   // Move to next node
        }

        if (l2 != nullptr) {
            sum += l2->data; // Add value from second list
            l2 = l2->next;   // Move to next node
        }

        carry = sum / 10; // Calculate new carry
        current->next = new Node(sum % 10); // Create new node with the digit
        current = current->next; // Move to the next node
    }

    Node* resultHead = dummyHead->next; // Result list starts from next of dummy
    delete dummyHead; // Free the dummy node
    return resultHead; // Return the head of the resultant linked list
}