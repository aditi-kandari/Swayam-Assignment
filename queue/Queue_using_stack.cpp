// Implement queue using stacks in C++

#include <iostream>
#include <stack>
using namespace std;

// Queue class using two stacks
class QueueUsingStacks {
    stack<int> stack1, stack2;

    // Helper function to transfer elements from stack1 to stack2
    void transferStack1ToStack2() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
public:
    // Enqueue operation
    void enqueue(int x) {
        stack1.push(x);
    }
    // Dequeue operation
    int dequeue() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                cout << "Queue Underflow\n";
                return -1;
            }
            transferStack1ToStack2();
        }
        int item = stack2.top();
        stack2.pop();
        return item;
    }
    // Peek operation
    int peek() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                cout << "Queue is empty\n";
                return -1;
            }
            transferStack1ToStack2();
        }
        return stack2.top();
    }
    // Check if the queue is empty
    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
    // Get the size of the queue
    int getSize() {
        return stack1.size() + stack2.size();
    }
};
