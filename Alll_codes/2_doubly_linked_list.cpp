// A linked list where each node has a pointer to both the previous and the next node, allowing traversal in both directions.

// doubly_linked_list.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev; // Pointer to previous node
};

Node* head = NULL; // Global head

// Create a new node
Node* GetNewNode(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at Head
void InsertAtHead(int x) {
    Node* newNode = GetNewNode(x);
    if (head == NULL) {
        head = newNode;
        return;
    }
    // Update head's previous pointer
    head->prev = newNode; 
    // Point new node's next to current head
    newNode->next = head; 
    // Update head
    head = newNode; 
}

// Print list forward
void Print() {
    Node* temp = head;
    cout << "Forward: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Print list backward
void ReversePrint() {
    Node* temp = head;
    if (temp == NULL) return; // Empty list

    // Go to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Traverse backward using prev pointer
    cout << "Reverse: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    InsertAtHead(2);
    InsertAtHead(4);
    InsertAtHead(6);
    // List: 6 4 2
    
    Print();
    ReversePrint();
    return 0;
}