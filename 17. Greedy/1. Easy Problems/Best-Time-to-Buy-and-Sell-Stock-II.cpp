// Best Time to Buy and Sell Stock II (Leetcode)
// Leetcode Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximumProfit = 0; // Initialize a variable to store the maximum profit

        // Step 1: Iterate through the prices starting from the second price
        for(int i = 1; i < prices.size(); i++) {
            // Step 2: Check if the current price is greater than the previous price
            if(prices[i-1] < prices[i]) {
                // Step 3: Add the difference between current and previous price to maximumProfit
                maximumProfit += prices[i] - prices[i-1];
            }
        }

        return maximumProfit;
    }
};