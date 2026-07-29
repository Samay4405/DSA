// A hierarchical structure. In a BST, left child < root < right child.
// Operations: Insert, Search, Min/Max, Height, BFS (Level Order), DFS (Pre/In/Post Order), IsBST, Delete, Successor.

// bst.cpp
#include <iostream>
#include <queue> // Required for Level Order Traversal
using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

// Create new node
BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 1. Insert a Node (Recursive)
BstNode* Insert(BstNode* root, int data) {
    if (root == NULL) {
        root = GetNewNode(data);
    } 
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    } 
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

// 2. Search for a Node
bool Search(BstNode* root, int data) {
    if (root == NULL) return false;
    if (root->data == data) return true;
    else if (data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

// 3. Find Minimum Value (Go as left as possible)
BstNode* FindMin(BstNode* root) {
    while(root->left != NULL) root = root->left;
    return root;
}

// 4. Find Height of Tree (Max edges from root to leaf)
int FindHeight(BstNode* root) {
    if (root == NULL) return -1;
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

// 5. Level Order Traversal (BFS) - Uses Queue
void LevelOrder(BstNode* root) {
    if (root == NULL) return;
    queue<BstNode*> Q;
    Q.push(root);
    // While there is at least one discovered node
    while (!Q.empty()) {
        BstNode* current = Q.front();
        Q.pop(); // Remove front
        cout << current->data << " "; // Visit (print)
        if (current->left != NULL) Q.push(current->left);
        if (current->right != NULL) Q.push(current->right);
    }
}

// 6. Depth First Traversals (Pre, In, Post)
void Preorder(BstNode* root) { // Root, Left, Right
    if (root == NULL) return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(BstNode* root) { // Left, Root, Right (Sorted Order)
    if (root == NULL) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Postorder(BstNode* root) { // Left, Right, Root
    if (root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

// 7. Check if Tree is Binary Search Tree (IsBST)
bool IsBstUtil(BstNode* root, int minValue, int maxValue) {
    if (root == NULL) return true;
    if (root->data > minValue && root->data < maxValue 
        && IsBstUtil(root->left, minValue, root->data) 
        && IsBstUtil(root->right, root->data, maxValue))
        return true;
    else 
        return false;
}

// 8. Delete a Node
BstNode* Delete(BstNode* root, int data) {
    if (root == NULL) return root; 
    else if (data < root->data) root->left = Delete(root->left, data);
    else if (data > root->data) root->right = Delete(root->right, data);
    else { 
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) { 
            delete root;
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            BstNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            BstNode* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Two children
        else { 
            BstNode* temp = FindMin(root->right); // Find min in right subtree
            root->data = temp->data; // Copy value
            root->right = Delete(root->right, temp->data); // Delete duplicate
        }
    }
    return root;
}

// 9. Find Inorder Successor
BstNode* GetSuccessor(BstNode* root, int data) {
    // Search the Node - O(h)
    BstNode* current = root;
    while(current != NULL && current->data != data) {
        if(data < current->data) current = current->left;
        else current = current->right;
    }
    if(current == NULL) return NULL; // Data not found

    // Case 1: Node has right subtree -> Go deep left in right subtree
    if(current->right != NULL) {
        return FindMin(current->right);
    }
    // Case 2: No right subtree -> Deepest ancestor for which current is in left
    else {
        BstNode* successor = NULL;
        BstNode* ancestor = root;
        while(ancestor != current) {
            if(current->data < ancestor->data) {
                successor = ancestor; // Possible successor
                ancestor = ancestor->left;
            } else
                ancestor = ancestor->right;
        }
        return successor;
    }
}

int main() {
    BstNode* root = NULL;
    // Tree Creation: 15, 10, 20, 25, 8, 12
    root = Insert(root, 15); root = Insert(root, 10); root = Insert(root, 20);
    root = Insert(root, 25); root = Insert(root, 8); root = Insert(root, 12);

    cout << "Inorder Traversal: ";
    Inorder(root); // Output: 8 10 12 15 20 25
    cout << endl;

    cout << "Height: " << FindHeight(root) << endl;

    root = Delete(root, 15); // Delete root
    cout << "After Deleting 15: ";
    Inorder(root); 
    cout << endl;

    return 0;
}