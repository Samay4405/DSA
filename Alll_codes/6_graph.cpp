// A collection of Nodes (Vertices) and Edges. Representations:

// 1. Adjacency Matrix: Efficient for dense graphs, fast lookup O(1), but uses O(V^2) space.

// 2. Adjacency List: Efficient for sparse graphs, uses O(V+E) space.

// graph.cpp
#include <iostream>
#include <vector>
using namespace std;

// --- 1. Adjacency Matrix Representation ---
// Good for Dense Graphs. Space: O(V^2).
// edgeLookup: O(1)
void adjacencyMatrix() {
    int V = 5; // Number of vertices (0 to 4)
    // 5x5 Matrix initialized to 0
    int adjMatrix[5][5] = {0}; 

    // Add Edge 0-1
    adjMatrix[0][1] = 1;
    adjMatrix[1][0] = 1; // For undirected graph

    // Add Edge 0-4
    adjMatrix[0][4] = 1;
    adjMatrix[4][0] = 1;

    cout << "Adjacency Matrix check (0 connected to 1?): " << adjMatrix[0][1] << endl;
}

// --- 2. Adjacency List Representation ---
// Good for Sparse Graphs. Space: O(V + E).
// Uses an array of linked lists (or vectors in C++)
void adjacencyList() {
    int V = 5;
    vector<int> adjList[V]; // Array of Vectors

    // Add Edge 0-1
    adjList[0].push_back(1);
    adjList[1].push_back(0);

    // Add Edge 0-4
    adjList[0].push_back(4);
    adjList[4].push_back(0);

    // Print neighbors of Node 0
    cout << "Neighbors of Node 0: ";
    for (int x : adjList[0]) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    cout << "--- Adjacency Matrix ---" << endl;
    adjacencyMatrix();
    
    cout << "\n--- Adjacency List ---" << endl;
    adjacencyList();
    
    return 0;
}