// patterns_basics.cpp
// This file covers the LOGIC templates you need for your Roadmap
// specifically for Searching, Sorting, and Recursion patterns.

#include <iostream>
#include <vector>
#include <algorithm> // For sort()
#include <unordered_map> // For Hash Maps
using namespace std;

// ==========================================
// PHASE 1: SEARCHING & SORTING PATTERNS
// ==========================================

// 1. Binary Search (O(log n))
// PREREQUISITE: Array must be sorted.
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids overflow

        if (arr[mid] == target)
            return mid; // Found
        else if (arr[mid] < target)
            left = mid + 1; // Target is in the right half
        else
            right = mid - 1; // Target is in the left half
    }
    return -1; // Not found
}

// 2. Two Pointers Pattern (O(n))
// Example: Check if array has a pair that sums to target (Sorted Array)
bool twoPointersSum(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == target) return true;
        else if (currentSum < target) left++; // Need bigger sum
        else right--; // Need smaller sum
    }
    return false;
}

// ==========================================
// PHASE 4: HASHING USAGE (STL)
// ==========================================
// In interviews, you don't build a Hash Map from scratch. 
// You use `unordered_map` (C++) or `HashMap` (Java).

void hashMapDemo() {
    // Key: Integer, Value: String
    unordered_map<int, string> map;

    // Insert
    map[1] = "Apple";
    map[2] = "Banana";

    // Lookup (O(1) average)
    if (map.find(1) != map.end()) {
        cout << "Found key 1: " << map[1] << endl;
    }

    // Frequency Counter Pattern (Crucial for Roadmap Phase 4)
    string text = "hello";
    unordered_map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }
}

// ==========================================
// PHASE 6: GRAPH TRAVERSAL (DFS Template)
// ==========================================
// Standard template for "Number of Islands" or "Clone Graph"

void DFS(int node, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;
    cout << node << " "; // Process node

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

// ==========================================
// PHASE 8: RECURSION (Backtracking Template)
// ==========================================
// Example: Generate all subsets (Power Set)
// Input: [1, 2] -> [], [1], [2], [1, 2]

void solveSubsets(vector<int>& nums, vector<int>& output, int index) {
    // Base Case: Processed all elements
    if (index >= nums.size()) {
        cout << "{ ";
        for(int x : output) cout << x << " ";
        cout << "}" << endl;
        return;
    }

    // Exclude current element
    solveSubsets(nums, output, index + 1);

    // Include current element
    output.push_back(nums[index]);
    solveSubsets(nums, output, index + 1);
    
    // Backtrack (remove the element to return to previous state)
    output.pop_back(); 
}

int main() {
    // Test Binary Search
    vector<int> sortedArr = {1, 3, 5, 7, 9, 11};
    cout << "Binary Search Index of 7: " << binarySearch(sortedArr, 7) << endl;

    // Test Recursion (Subsets)
    vector<int> nums = {1, 2};
    vector<int> output;
    cout << "Subsets:" << endl;
    solveSubsets(nums, output, 0);

    return 0;
}