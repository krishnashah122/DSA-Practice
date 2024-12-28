// Coin Change (Leetcode)
// Leetcode Link : https://leetcode.com/problems/coin-change/description/

// Time Complexity : O(amount * n)
// Space Complexity : O(amount)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Step 1: Initialize dp array with INT_MAX to represent infinite coins needed
        vector<int> dp(amount + 1, INT_MAX);

        // Step 2: Base case, zero coins needed for amount 0
        dp[0] = 0;

        // Step 3: Loop through each amount from 1 to target amount
        for(int i = 1; i <= amount; i++){
            // Step 4: Check each coin for possible minimum coins
            for(int coin : coins){
                if(coin <= i && dp[i - coin] != INT_MAX){
                    // Step 5: Update the minimum coins needed for amount 'i'
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // Step 6: Return result or -1 if not possible to reach amount
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};