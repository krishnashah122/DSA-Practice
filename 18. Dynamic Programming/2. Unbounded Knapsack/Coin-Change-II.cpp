// Coin Change II (Leetcode)
// Leetcode Link : https://leetcode.com/problems/coin-change-ii/description/

// Time Complexity : O(n * amount)
// Space Complexity : O(n * amount)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // Step 1: Create a dp table of size (n+1) x (amount+1) size, initialized to 0
        vector<vector<unsigned>> dp(n + 1, vector<unsigned>(amount + 1, 0));

        // Step 2: Initialize the base case
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1; // One way to make amount 0: using no coins
        }

        // Step 3: Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (coins[i - 1] <= j) { // Check if we can include the coin
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j]; // Include or exclude
                } else {
                    dp[i][j] = dp[i - 1][j]; // Exclude the coin if it's larger than the amount
                }
            }
        }

        // Step 4: Return the number of ways to make the amount
        return dp[n][amount];
    }
};