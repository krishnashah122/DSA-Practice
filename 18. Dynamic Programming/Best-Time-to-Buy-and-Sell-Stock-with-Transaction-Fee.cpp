// Best Time to Buy and Sell Stock with Transaction Fee (Leetcode)
// Leetcode Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int maxProfit = 0;
        int buyPrice = prices[0];

        // Step 1: Iterate through the prices array
        for(int i = 1; i < prices.size(); i++) {
            // Step 2: Update maxProfit if selling on day i yields a higher profit
            maxProfit = max(maxProfit, prices[i] - buyPrice - fee);

            // Step 3: Update buyPrice to reflect the minimum effective buy price
            buyPrice = min(buyPrice, prices[i] - maxProfit);
        }

        // Step 4: Return the maximum profit achieved
        return maxProfit;
    }
};