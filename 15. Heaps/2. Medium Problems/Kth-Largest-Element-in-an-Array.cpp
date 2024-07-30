// Kth Largest Element in an Array (Leetcode)
// Leetcode Link : https://leetcode.com/problems/kth-largest-element-in-an-array/description/

// Time Complexity : O(nLogk)
// Space Complexity : O(k)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto &num : nums){
            // Add the current element to the Min Heapc
            minHeap.push(num);
            // If the size of the Min Heap exceeds k, remove the smallest element
            if(minHeap.size() > k) minHeap.pop();
        }

        // The top of the Min Heap will be the k-th largest element
        return minHeap.top();
    }
};