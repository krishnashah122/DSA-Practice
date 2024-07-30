// Kth Smallest (GFG)
// GFG Link : https://shorturl.at/1Z9OX

// Time Complexity : O(nLogk)
// Space Complexity : O(k)

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> maxHeap;
        
        for(int i = l; i <= r; i++){
            // Add the current element to the Max Heap
            maxHeap.push(arr[i]);
            // If the size of the Max Heap exceeds k, remove the largest element
            if(maxHeap.size() > k) maxHeap.pop();
        }
        
        // The top of the Max Heap will be the k-th smallest element
        return maxHeap.top();
    }
};