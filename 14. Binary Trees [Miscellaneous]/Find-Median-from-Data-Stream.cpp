// Find Median from Data Stream (Leetcode)
// Leetcode Link : https://leetcode.com/problems/find-median-from-data-stream/description/

// Time Complexity : O(Logm) where, m is the no. of elements in the heap.
// Space Complexity : O(n) where, n is the no. of elements inserted into the MediaFinder.

class MedianFinder {
public:
    priority_queue<int> maxHeap; // Max heap
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // If maxHeap is empty or num is less than or equal to the top of maxHeap, add it to maxHeap
        if(maxHeap.empty() || num < maxHeap.top()){
            maxHeap.push(num);
        }else{
            // Otherwise, add it to minHeap
            minHeap.push(num);
        }

        // Balance the heaps such that the sizes of the heaps differ by no more than 1
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if(minHeap.size() > maxHeap.size() + 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // If there are even no. of elements
        if(maxHeap.size() == minHeap.size()){
            // The median is the average of the two middle elements
            return ((maxHeap.top() + minHeap.top()) / 2.0);
        }else{
            // If there are odd no. of elements
            if(maxHeap.size() > minHeap.size()){
                // If maxHeap has more elements, the median is the top element of maxHeap
                return maxHeap.top();
            }else{
                // If minHeap has more elements, the median is the top element of minHeap
                return minHeap.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */