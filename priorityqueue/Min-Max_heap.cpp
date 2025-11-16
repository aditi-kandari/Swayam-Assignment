// Implement min/max heap in cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

// Min-Max Heap class

class MinMaxHeap {
private:
    vector<int> heap;

    bool isMinLevel(int index) {
        int level = 0;
        while (index > 0) {
            index = (index - 1) / 2;
            level++;
        }
        return (level % 2 == 0);
    }

    void heapifyUp(int index) {
        if (index == 0) return;

        int parentIndex = (index - 1) / 2;
        if (isMinLevel(index)) {
            if (heap[index] > heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                heapifyUpMax(parentIndex);
            } else {
                heapifyUpMin(index);
            }
        } else {
            if (heap[index] < heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                heapifyUpMin(parentIndex);
            } else {
                heapifyUpMax(index);
            }
        }
    }

    void heapifyUpMin(int index) {
        while (index > 2) {
            int grandParentIndex = (index - 3) / 4;
            if (heap[index] < heap[grandParentIndex]) {
                swap(heap[index], heap[grandParentIndex]);
                index = grandParentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyUpMax(int index) {
        while (index > 2) {
            int grandParentIndex = (index - 3) / 4;
            if (heap[index] > heap[grandParentIndex]) {
                swap(heap[index], heap[grandParentIndex]);
                index = grandParentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        if (isMinLevel(index)) {
            heapifyDownMin(index);
        } else {
            heapifyDownMax(index);
        }
    }

    void heapifyDownMin(int index) {
        int size = heap.size();
        while (true) {
            int m = index;
            for (int i = 1; i <= 4; ++i) {
                int childIndex = 2 * index + i;
                if (childIndex < size && heap[childIndex] < heap[m]) {
                    m = childIndex;
                }
            }
            if (m != index) {
                swap(heap[index], heap[m]);
                if (m >= 4 * index + 3) {       
                    int parentIndex = (m - 1) / 2;
                    if (heap[m] > heap[parentIndex]) {
                        swap(heap[m], heap[parentIndex]);
                    }
                }   
                index = m;
            } else {
                break;  
            }
        }   
    }   
    void heapifyDownMax(int index) {
        int size = heap.size();
        while (true) {
            int m = index;
            for (int i = 1; i <= 4; ++i) {
                int childIndex = 2 * index + i;
                if (childIndex < size && heap[childIndex] > heap[m]) {
                    m = childIndex;
                }
            }
            if (m != index) {
                swap(heap[index], heap[m]);
                if (m >= 4 * index + 3) {       
                    int parentIndex = (m - 1) / 2;
                    if (heap[m] < heap[parentIndex]) {
                        swap(heap[m], heap[parentIndex]);
                    }
                }   
                index = m;
            } else {
                break;  
            }
        }   
    }
public:
    MinMaxHeap() {}

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int getMin() const {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    int getMax() const {
        if (heap.size() < 2) {
            throw runtime_error("Heap does not have enough elements");
        }
        if (heap.size() == 2) {
            return heap[1];
        }
        return max(heap[1], heap[2]);
    }       
    int extractMin() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minValue;
    }
    int extractMax() {
        if (heap.size() < 2) {
            throw runtime_error("Heap does not have enough elements");
        }
        int maxIndex = (heap.size() == 2) ? 1 : (heap[1] > heap[2] ? 1 : 2);
        int maxValue = heap[maxIndex];
        heap[maxIndex] = heap.back();
        heap.pop_back();
        heapifyDown(maxIndex);
        return maxValue;
    }
};

