// Shortest Subarray with Sum at Least K (Leetcode)
// Leetcode Link : https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long long sum = 0;
        long long minLen = INT_MAX;
        deque<pair<long long, long long>> dq; // Deque to store pairs of (prefix sum, index)
        dq.push_back({sum, -1}); // Start with an initial pair (0, -1) to handle sums from the beginning

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];  // Update the cumulative sum with the current element

            // Maintain a monotonic deque: remove elements from the back if the current sum is smaller or equal
            while(!dq.empty() && (sum <= dq.back().first)){
                dq.pop_back();  // These elements can't form a valid subarray, so discard them
            }

            // Check if there's a valid subarray (sum - prefix sum >= k)
            while(!dq.empty() && (sum - k >= dq.front().first)){
                // Calculate the length of the subarray and update the minimum length
                minLen = min(minLen, (i - dq.front().second));
                dq.pop_front();  // Remove the front element after processing it
            }

            // Add the current prefix sum and index to the deque for future subarray checks
            dq.push_back({sum, i});
        }

        // If a valid subarray was found, return its length; otherwise, return -1
        return (minLen != INT_MAX) ? minLen : -1;
    }
};