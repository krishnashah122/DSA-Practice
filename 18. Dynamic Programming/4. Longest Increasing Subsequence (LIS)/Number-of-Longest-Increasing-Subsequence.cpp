// Number of Longest Increasing Subsequence (Leetcode)
// Leetcode Link : https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

// Time Complexity : O(n^2)
// Space Complexity : O(n)

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        // Step 1: DP array to store LIS ending at each index & count array to LIS count ending at each index
        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        // Step 2: Track the longest LIS found
        int LIS = 0;

        // Step 3: Loop through each element as the end of a subsequence
        for(int idx = 0; idx < n; idx++){
            // Step 4: Check previous elements to extend the subsequence
            for(int prevIdx = 0; prevIdx < idx; prevIdx++){
                // Step 5: Update dp[idx] if nums[idx] extends an increasing sequence
                if(nums[idx] > nums[prevIdx] && 1 + dp[prevIdx] > dp[idx]){
                    dp[idx] = 1 + dp[prevIdx];
                    count[idx] = count[prevIdx]; // Reset count[idx] to count[prevIdx] as new LIS is formed
                }else if(nums[idx] > nums[prevIdx] && 1 + dp[prevIdx] == dp[idx]){
                    // Step 6: If nums[idx] forms another LIS of the same length as the current max
                    count[idx] += count[prevIdx]; // Add count[prevIdx] to count[idx] as it contributes another LIS
                }
            }
            // Step 7: Update LIS with the max length found
            LIS = max(LIS, dp[idx]);
        }

        // Step 8: Calculate total number of LIS with length equal to LIS
        int noOfLIS = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == LIS){
                noOfLIS += count[i]; // Add counts of all sequences with length = LIS
            }
        }

        // Step 9: Return the total count of LIS
        return noOfLIS;
    }
};