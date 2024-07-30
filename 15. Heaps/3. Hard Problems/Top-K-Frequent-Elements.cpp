// Top K Frequent Elements (Leetcode)
// Leetcode Link : https://leetcode.com/problems/top-k-frequent-elements/description/

// Time Complexity : O(nLogk)
// Space Complexity : O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> result;

        // Store the freq map with counts of each element
        for(auto &num : nums){
            freq[num]++;
        }

        // Use a min-heap to maintain the top k frequent elements
        for(auto &pair : freq){
            // Push the frequency and corresponding element into the min-heap
            minHeap.push({pair.second, pair.first});
            // If the min-heap size exceeds k, remove the element with the smallest frequency
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        
        // Extract the elements from the min-heap to form the result
        while(!minHeap.empty()){
            // Extract the element with the highest frequency
            result.push_back(minHeap.top().second);
            // Remove the element from the heap
            minHeap.pop();
        }

        return result;
    }
};