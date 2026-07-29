// Merge Sort: Safest choice. Guaranteed $O(n \log n)$ time complexity.
// It splits the array in half recursively and then "merges" the sorted halves.
//  Quick Sort: Often faster in practice but trickier. It picks a "pivot" element and partitions the array (smaller items to left, larger to right).

// sorting_algorithms.cpp
#include <iostream>
#include <vector>
using namespace std;

// ==========================================
// 1. MERGE SORT (Divide and Conquer)
// Time Complexity: O(n log n) - Best/Avg/Worst
// Space Complexity: O(n) - Requires temporary array
// ==========================================

// Helper function to merge two sorted subarrays:
// A[left..mid] and A[mid+1..right]
void Merge(vector<int>& arr, int left, int mid, int right) {
    int i = left;       // Starting index of left subarray
    int j = mid + 1;    // Starting index of right subarray
    vector<int> temp;   // Temporary vector to store merged result

    // Compare elements from both halves and store the smaller one
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements from the left half (if any)
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from the right half (if any)
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy the sorted elements back into original array
    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

// Main Recursive Function
void MergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return; // Base case: 1 or 0 elements

    int mid = left + (right - left) / 2;

    // Recursively sort first and second halves
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    Merge(arr, left, mid, right);
}


// ==========================================
// 2. QUICK SORT (Divide and Conquer)
// Time Complexity: O(n log n) Avg, O(n^2) Worst
// Space Complexity: O(log n) stack space
// ==========================================



// Helper function to place pivot in correct position
// Returns the index of the pivot
int Partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]); // Swap it to the "smaller" side
        }
    }
    // Finally, place the pivot in the correct position (after smaller elements)
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Main Recursive Function
void QuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = Partition(arr, low, high);

        // Separately sort elements before partition and after partition
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}


// ==========================================
// UTILITIES
// ==========================================

void PrintVector(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    // --- Test Merge Sort ---
    vector<int> arr1 = {12, 11, 13, 5, 6, 7};
    cout << "Original Array: ";
    PrintVector(arr1);

    MergeSort(arr1, 0, arr1.size() - 1);
    cout << "Merge Sorted:   ";
    PrintVector(arr1);

    cout << "-----------------" << endl;

    // --- Test Quick Sort ---
    vector<int> arr2 = {10, 7, 8, 9, 1, 5};
    cout << "Original Array: ";
    PrintVector(arr2);

    QuickSort(arr2, 0, arr2.size() - 1);
    cout << "Quick Sorted:   ";
    PrintVector(arr2);

    return 0;
}