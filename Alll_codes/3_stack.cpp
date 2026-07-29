// A LIFO (Last In First Out) data structure. Key Operations: Push (Insert), Pop (Remove), Top (Access). 
// Applications: Balancing parentheses, Expression evaluation.

// stack.cpp
#include <iostream>
#include <stack> // C++ STL Stack library
#include <string>
using namespace std;

// --- Implementation using Array ---
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1; // Empty stack

void Push(int x) {
    if (top == MAX_SIZE - 1) {
        cout << "Error: Stack Overflow" << endl;
        return;
    }
    A[++top] = x; // Increment top and insert
}

void Pop() {
    if (top == -1) {
        cout << "Error: No element to pop" << endl;
        return;
    }
    top--; // Simply decrement top
}

int Top() {
    return A[top];
}

// --- Application: Check Balanced Parentheses ---
// Checks if opening and closing brackets match: {}, (), []
bool AreParanthesesBalanced(string exp) {
    stack<char> S; // Using STL stack for simplicity in application logic
    
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            S.push(exp[i]); // Push opening brackets
        } 
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (S.empty() || 
               (exp[i] == ')' && S.top() != '(') || 
               (exp[i] == '}' && S.top() != '{') || 
               (exp[i] == ']' && S.top() != '[')) {
                return false; // Mismatch or empty stack
            }
            S.pop(); // Match found, pop
        }
    }
    return S.empty(); // Stack must be empty if balanced
}

int main() {
    // Testing Array Implementation
    Push(2);
    Push(5);
    Push(10);
    Pop();
    cout << "Top element: " << Top() << endl; // Output: 5

    // Testing Parentheses Check
    string expression = "{()}[]";
    if (AreParanthesesBalanced(expression))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}