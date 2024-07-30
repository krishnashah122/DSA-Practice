// Implementation of Priority Queue using Binary Heap (GFG)
// GFG Link : https://shorturl.at/9JCnI

// Time Complexity : O(1)
// Space Complexity : O(1)

// User function Template for C++
// 1. parent(i): Function to return the parent node of node i
// 2. leftChild(i): Function to return index of the left child of node i
// 3. rightChild(i): Function to return index of the right child of node i
// 4. shiftUp(int i): Function to shift up the node in order to maintain the
// heap property
// 5. shiftDown(int i): Function to shift down the node in order to maintain the
// heap property.
// int s=-1, current index value of the array H[].

class Solution {
  public:
    int extractMax() {
        // your code here
        int result = H[0]; // Root node has the max element
        H[0] = H[s]; // Replace root value with the value last leaf
        s -= 1; // Decrement the size of H
        shiftDown(0); // Shift down the replace element to maintain the heap priority
        
        return result;
    }
};