#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;                         // In c++ it would be 'Node* next;'
};
struct Node* head = NULL;                      // Global head pointer for the linked list
void Insert(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
    newNode->data = x;                      // Set data for new node
    newNode->next = head;                   // New node points to current head
    head = newNode;                         // Update head to new node
}
void print(){
    struct Node* temp = head;                 // Temporary pointer to traverse the list
    printf("Linked List: ");
    while(temp != NULL){                      // Traverse until the end of the list
        printf("%d -> ", temp->data);        // Print current node's data
        temp = temp->next;                    // Move to the next node
    }
    printf("NULL\n");                        // Indicate the end of the list
}

int main(){
    head = NULL;                             // Initialize head to NULL (empty list)
    printf("How many numbers you want to insert at the beginning: ");
    int n, x, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Enter number : ");
        scanf("%d", &x);
        Insert(x);
        print();
    }
}

