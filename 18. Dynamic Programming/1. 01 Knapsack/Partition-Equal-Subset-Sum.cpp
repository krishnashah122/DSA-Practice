// Partition Equal Subset Sum (Leetcode)
// Leetcode Link : https://leetcode.com/problems/partition-equal-subset-sum/description/

// Time Complexity : O((sum/2) * n)
// Space Complexity : O((sum/2) * n)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        // Step 1: Calculate the total sum of elements
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        // Step 2: Check if the total sum is odd; if so, partitioning is not possible
        if(sum % 2 != 0){
            return false;
        } else {
            // Step 3: Initialize the dp table for subset sum to sum/2
            vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1));

            // Step 4: Set base cases for dp table
            for(int i = 0; i <= n; i++){
                for(int j = 0; j <= sum / 2; j++){
                    if(i == 0) dp[i][j] = false; // No elements can't form a non-zero sum
                    if(j == 0) dp[i][j] = true; // Sum 0 is possible with an empty subset
                }
            }

            // Step 5: Fill the dp table iteratively based on inclusion/exclusion of current element
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= sum / 2; j++){
                    if(nums[i - 1] <= j){ // Check if we can include the current element
                        dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j]; // Include or exclude
                    } else {
                        dp[i][j] = dp[i - 1][j]; // Exclude current element if it's larger than sum
                    }
                }
            }
            
            return dp[n][sum / 2];
        }
    }
};