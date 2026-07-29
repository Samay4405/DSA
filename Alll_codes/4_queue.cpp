// A FIFO (First In First Out) data structure. Key Operations: Enqueue (Insert at rear), Dequeue (Remove from front). 
// Implementation: Circular Array concept is used to efficiently utilize space

// queue.cpp
#include <iostream>
using namespace std;

#define MAX_SIZE 101 // Array size

class Queue {
private:
    int A[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool IsEmpty() {
        return (front == -1 && rear == -1);
    }

    bool IsFull() {
        // Check circular condition
        return (rear + 1) % MAX_SIZE == front;
    }

    void Enqueue(int x) {
        if (IsFull()) {
            cout << "Error: Queue is Full" << endl;
            return;
        }
        if (IsEmpty()) {
            front = rear = 0;
        } else {
            // Circular increment: (i + 1) % N
            rear = (rear + 1) % MAX_SIZE;
        }
        A[rear] = x;
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Error: Queue is Empty" << endl;
            return;
        }
        if (front == rear) {
            // Only one element was present, reset to empty
            rear = front = -1;
        } else {
            // Circular increment
            front = (front + 1) % MAX_SIZE;
        }
    }

    int Front() {
        if (front == -1) {
            cout << "Error: Cannot return front from empty queue" << endl;
            return -1;
        }
        return A[front];
    }
};

int main() {
    Queue Q;
    Q.Enqueue(2);
    Q.Enqueue(4);
    Q.Enqueue(6);
    Q.Dequeue(); // Removes 2
    cout << "Front: " << Q.Front() << endl; // Output: 4
    return 0;
}