// Convert Min Heap to Max Heap (GFG)
// GFG Link : https://shorturl.at/f1Qi0

// Time Complexity : O(n * Logn)
// Space Complexity : O(Logn)

class Solution {
public:
    void heapify(vector<int> &arr, int idx) {
        int left = 2 * idx + 1; // Index of left child
        int right = 2 * idx + 2; // Index of right child
        int maxi = idx; // Initialize largest as root
        
        // If left child is larger than root
        if (left < arr.size() && arr[left] > arr[maxi]) {
            maxi = left;
        }
        
        // If right child is larger than the largest so far
        if (right < arr.size() && arr[right] > arr[maxi]) {
            maxi = right;
        }
        
        // If the largest is not root
        if (maxi != idx) {
            swap(arr[maxi], arr[idx]); // Swap root with the largest child
            heapify(arr, maxi); // Recursively heapify the affected sub-tree
        }
    }
    
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        int idx = N - 1; // Index of the last element
        
        // Start from the last internal node and heapify each node
        for (int i = (idx - 1) / 2; i >= 0; i--) {
            heapify(arr, i);
        }
    }
};