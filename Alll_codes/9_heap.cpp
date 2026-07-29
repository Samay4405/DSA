// Heap / Priority Queue : To find the Minimum or Maximum element in $O(1)$ time. Essential for "Top K Frequent Elements"
// Note: In C++, we usually use priority_queue from STL, but understanding the array-based implementation is often asked in interviews.

// heap.cpp
#include <iostream>
#include <vector>
#include <queue> // For STL implementation
using namespace std;

// ==========================================
// 1. MANUAL MIN-HEAP IMPLEMENTATION
// Logic: Parent is always smaller than children.
// Array Representation:
// Parent(i) -> Left Child(2*i + 1), Right Child(2*i + 2)
// ==========================================

class MinHeap {
    vector<int> heap;

    // Helper: Move element up to restore heap property
    void heapifyUp(int index) {
        if (index == 0) return;
        int parentIndex = (index - 1) / 2;
        
        if (heap[index] < heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    // Helper: Move element down to restore heap property
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back(); // Replace root with last element
        heap.pop_back();       // Remove last element
        heapifyDown(0);        // Fix the order
    }

    int top() {
        if (heap.empty()) return -1;
        return heap[0];
    }
    
    bool empty() { return heap.empty(); }
};

// ==========================================
// 2. STL PRIORITY QUEUE (What you use in interviews)
// ==========================================
void stlDemo() {
    // Max Heap by default
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(30);
    cout << "Max Heap Top: " << maxHeap.top() << endl; // 30

    // Min Heap Syntax
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(30);
    cout << "Min Heap Top: " << minHeap.top() << endl; // 5
}

int main() {
    MinHeap h;
    h.push(10);
    h.push(5);
    h.push(30);
    cout << "Manual Min Heap Top: " << h.top() << endl; // 5
    
    h.pop();
    cout << "After Pop, Top: " << h.top() << endl; // 10

    cout << "--- STL Demo ---" << endl;
    stlDemo();
    return 0;
}