// Maximum Sum of Distinct Subarrays With Length K (Leetcode)
// Leetcode Link : https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

// Time Complexity : O(n)
// Space Complexity : O(k)

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long sum = 0;
        map<int, int> mp;

        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right]; // Add the current element to the sum
            mp[nums[right]]++;  // Increment the count of the current element in the map

            // If the window size exceeds `k`, shrink the window by moving the left pointer
            if(k < (right - left + 1)) {
                // If the element at the left pointer exists in the map, reduce its frequency
                if(mp.find(nums[left]) != mp.end()) {
                    mp[nums[left]]--;
                    // If the frequency of the leftmost element becomes 0, erase it from the map
                    if(mp[nums[left]] == 0) mp.erase(nums[left]);
                }
                // Subtract the leftmost element from the sum and move the left pointer to the right
                sum -= nums[left];
                left++;
            }

            // If the window size is exactly `k` and all elements in the window are unique (map size == k)
            if(k == (right - left + 1) && k == mp.size()) {
                maxSum = max(maxSum, sum); // Update the maximum sum found so far
            }
        }

        return maxSum;
    }
};