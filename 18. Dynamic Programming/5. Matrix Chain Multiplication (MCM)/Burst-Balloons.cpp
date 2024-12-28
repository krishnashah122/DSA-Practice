// Burst Balloons (Leetcode)
// Leetcode Link : https://leetcode.com/problems/burst-balloons/description/

// Time Complexity : O(n^3)
// Space Complexity : O(n^2)

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Add 1 to both ends of nums for boundary conditions
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // Step 2: Initialize dp table with size (n+2) x (n+2) filled with 0
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

        // Step 3: Fill dp table in bottom-up manner, starting from smaller subproblems
        for(int i = n; i >= 1; i--){
            for(int j = 1; j <= n; j++){
                if(i > j) continue; // Skip invalid ranges

                int maximum = INT_MIN;
                // Step 4: Test all balloons as the last burst in range [i, j]
                for(int k = i; k <= j; k++){
                    int coins = nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    // Step 5: Track maximum coins for current range [i, j]
                    maximum = max(maximum, coins);
                }

                // Step 6: Store the maximum result in dp[i][j]
                dp[i][j] = maximum;
            }
        }
        
        // Step 7: Return the result for bursting all balloons in range [1, n]
        return dp[1][n];
    }
};