// Add Node to any position in a singly linked list

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to add a node at a specific position
void addNode(Node*& head, int data, int position) {
    Node* newNode = new Node(data);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position is out of bounds." << endl;
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
    // No need to return head as we are modifying it directly
    // Time Complexity: O(n) in the worst case
}
