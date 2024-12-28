// Target Sum (Leetcode)
// Leetcode Link : https://leetcode.com/problems/target-sum/description/

// Time Complexity : O(n * s1)
// Space Complexity : O(n * s1)

class Solution {
public:
    int countSubsetSum(vector<int> &nums, int s1){
        int n = nums.size();
        // Step 1: Create a DP table to store the number of ways to achieve each sum
        vector<vector<int>> dp(n+1, vector<int> (s1+1, 0));

        // Step 2: There is one way to make sum 0 (empty subset)
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }

        // Step 3: Fill the DP table using the subset sum logic
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= s1; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j - nums[i-1]] + dp[i-1][j]; // Include or exclude current element
                }else{
                    dp[i][j] = dp[i-1][j]; // Exclude current element
                }
            }
        }

        // Step 4: Return the result from the last cell
        return dp[n][s1];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // Step 1: Calculate the total sum of the array
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }

        // Step 2: Check if partition is possible
        // 1. Target can't exceed sum
        // 2. (sum + target) must be even for valid subsets
        if(sum < abs(target) || (sum + target) % 2 != 0) return 0;

        // Step 3: Calculate the target subset sum s1
        int s1 = (sum + target) / 2;

        // Step 4: Find the number of subsets with sum equal to s1, return it
        return countSubsetSum(nums, s1);
    }
};