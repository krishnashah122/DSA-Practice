// Kth Largest Element in a Stream (Leetcode)
// Leetcode Link : https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

// Time Complexity : O(nLogn)
// Space Complexity : O(k)

class KthLargest {
public:
    int size = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap
    KthLargest(int k, vector<int>& nums) {
        // Assign k value to the global variable size
        size = k;

        // Push all elements of nums into the minHeap
        for(auto x : nums){
            minHeap.push(x);
            // If minHeap size is exceeding k, pop smallest element to ensure minHeap has k largest elements
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        // Push the val into the minHeap
        minHeap.push(val);
        // If minHeap size if exceeding k, pop smallest element to ensure minHeap has k largest elements
        if(minHeap.size() > size){
            minHeap.pop();
        }
        // Return minHeap top as the kth largest element
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */