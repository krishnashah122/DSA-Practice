// Combination Sum IV (Leetcode)
// Leetcode Link : https://leetcode.com/problems/combination-sum-iv/description/

// Time Complexity : O(n * target)
// Space Complexity : O(n * target)

class Solution {
public:
    int solve(vector<int>& nums, int idx, int target, vector<vector<int>> &dp){
        // Step 1: Base case - if target is 0, one combination is found
        if(target == 0) return 1;

        // Step 2: Base case - invalid indices or negative target, no combination possible
        if(idx >= nums.size() || target < 0) return 0;

        // Step 3: Return memoized result if already computed
        if(dp[idx][target] != -1) return dp[idx][target];

        // Step 4: Recursive call for two choices - take or skip current number
        int taken = solve(nums, 0, target - nums[idx], dp); // Restart with first index
        int nottaken = solve(nums, idx+1, target, dp); // Move to the next index

        // Step 5: Memoized and return the total combinations
        return dp[idx][target] = taken + nottaken;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        // Step 6: Initialize DP table of size (n+1) x (target + 1)
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        // Step 7: Return the no. of possible combinations
        return solve(nums, 0, target, dp);
    }
};