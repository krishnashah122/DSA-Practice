// Longest Increasing Subsequence (Leetcode)
// Leetcode Link : https://leetcode.com/problems/longest-increasing-subsequence/description/

// Time Complexity : O(n^2)
// Space Complexity : O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: DP array to store LIS ending at each index
        vector<int> dp(n, 1);
        
        // Step 2: Track the longest LIS found
        int LIS = 0;

        // Step 3: Loop through each element as the end of a subsequence
        for(int idx = 0; idx < n; idx++){
            // Step 4: Check previous elements to extend the subsequence
            for(int prevIdx = 0; prevIdx < idx; prevIdx++){
                // Step 5: Update dp[idx] if nums[idx] extends an increasing sequence
                if(nums[prevIdx] < nums[idx]){
                    dp[idx] = max(dp[idx], 1 + dp[prevIdx]);
                }
            }
            // Step 6: Update LIS with the max length found
            LIS = max(LIS, dp[idx]);
        }

        // Step 7: Return LIS length
        return LIS;
    }
};