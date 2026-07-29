// Union-Find / Disjoint Set : This is the standard pattern for detecting cycles in undirected graphs, finding "Connected Components," and solving "Number of Islands" optimally. 
// Key Operations: Find (which group am I in?), Union (merge two groups).

// union_find.cpp
#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    vector<int> parent;
    vector<int> rank; // Approximate height of the tree

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        // Initially, every node is its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find with Path Compression (O(alpha(n)) ~ O(1))
    int find(int x) {
        if (parent[x] != x) {
            // Recursively find the root and point x directly to it
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    // Union by Rank (Attach smaller tree to deeper tree)
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    UnionFind uf(5); // 5 nodes: 0, 1, 2, 3, 4
    
    uf.unite(0, 1);
    uf.unite(1, 2);
    // Structure: 0-1-2 (All connected)

    cout << "Is 0 connected to 2? " << (uf.isConnected(0, 2) ? "Yes" : "No") << endl;
    cout << "Is 0 connected to 4? " << (uf.isConnected(0, 4) ? "Yes" : "No") << endl;

    return 0;
}