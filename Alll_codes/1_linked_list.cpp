// A linear data structure where elements are not stored in contiguous memory locations. The elements are linked using pointers.
//  Key Operations: Insertion (beginning, nth position), Deletion, Reversal (Iterative & Recursive), and Traversal.

// linked_list.cpp
#include <iostream>
using namespace std;

// Definition of a Node
struct Node {
    int data;           // Data part of the node
    Node* next;         // Pointer to the next node
};

// Global head pointer (for simplicity, as used in parts of the video)
Node* head = NULL; 

// Function to create a new node
Node* GetNewNode(int x) {
    Node* newNode = new Node(); // 'new' operator allocates memory in Heap (C++ syntax)
    newNode->data = x;          // Set data
    newNode->next = NULL;       // Set next to NULL
    return newNode;
}

// 1. Insert at the beginning of the list (O(1))
void InsertAtHead(int x) {
    Node* temp = GetNewNode(x);
    temp->next = head; // Point new node to the current head
    head = temp;       // Update head to point to the new node
}

// 2. Insert at nth position (O(n))
void InsertAtPosition(int data, int n) {
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;

    if (n == 1) { // Special case: Insert at head
        temp1->next = head;
        head = temp1;
        return;
    }

    Node* temp2 = head;
    // Traverse to the (n-1)th node
    for (int i = 0; i < n - 2; i++) {
        temp2 = temp2->next;
    }
    // Link new node to the nth node
    temp1->next = temp2->next; 
    // Link (n-1)th node to new node
    temp2->next = temp1;
}

// 3. Delete a node at nth position (O(n))
void Delete(int n) {
    Node* temp1 = head;
    
    if (n == 1) { // Special case: Delete head
        head = temp1->next; // Point head to the second node
        delete temp1;       // Free memory (C++ syntax, use 'free' in C)
        return;
    }

    // Traverse to (n-1)th node
    for (int i = 0; i < n - 2; i++) {
        temp1 = temp1->next;
    }
    
    Node* temp2 = temp1->next; // nth node (node to be deleted)
    temp1->next = temp2->next; // Fix the link
    delete temp2;              // Free memory
}

// 4. Reverse the linked list - Iterative Method (O(n))
void ReverseIterative() {
    Node *current, *prev, *next;
    current = head;
    prev = NULL;

    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev one step forward
        current = next;       // Move current one step forward
    }
    head = prev; // Update head to the last node
}

// 5. Print the list using Recursion
void PrintRecursive(Node* p) {
    if (p == NULL) {
        cout << endl;
        return; // Exit condition
    }
    cout << p->data << " "; // Print data
    PrintRecursive(p->next); // Recursive call for the next node
}

// 6. Reverse Print using Recursion (does not reverse the list, just prints backwards)
void ReversePrintRecursive(Node* p) {
    if (p == NULL) return;
    ReversePrintRecursive(p->next); // Go to the end first
    cout << p->data << " ";         // Print on the way back (unwinding)
}

// 7. Reverse the list using Recursion
void ReverseRecursion(Node* p) {
    if (p->next == NULL) {
        head = p; // Last node becomes the new head
        return;
    }
    ReverseRecursion(p->next);
    
    // Adjust links during unwinding
    Node* q = p->next; 
    q->next = p; 
    p->next = NULL;
}

int main() {
    // Testing the functions
    InsertAtHead(2);
    InsertAtHead(4);
    InsertAtHead(6);
    // List: 6 4 2
    
    InsertAtPosition(5, 2); 
    // List: 6 5 4 2

    Delete(3); 
    // List: 6 5 2 (Deleted node at pos 3 which was 4)

    cout << "List is: ";
    PrintRecursive(head);

    ReverseIterative();
    cout << "Reversed List: ";
    PrintRecursive(head);

    return 0;
}