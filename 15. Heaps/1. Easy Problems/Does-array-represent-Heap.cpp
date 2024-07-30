// Does array represent Heap (GFG)
// GFG Link : https://shorturl.at/gM9pv

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for(int i = 0; i < n; i++){
            // Check if left child exists and is greater than current node
            if((2 * i + 1 < n) && arr[i] < arr[(2 * i) + 1]){
                return false;
            }
            
            // Check if right child exists and is greater than current node
            if((2 * i + 2 < n) && arr[i] < arr[(2 * i) + 2]){
                return false;
            }
        }
        
        // If no violations found, it is a Max Heap
        return true;
    }
};