// Implement Queue using array in C++

#include <iostream>
using namespace std;
#define MAX 1000
class Queue {
    int front, rear, size;
    int arr[MAX];
public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }
    void enqueue(int x) {
        if (size == MAX) {
            cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        size++;
    }
    int dequeue() {
        if (size == 0) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % MAX;
        size--;
        return item;
    }
    int peek() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
    bool isEmpty() {
        return size == 0;
    }
    int getSize() {
        return size;
    }
};