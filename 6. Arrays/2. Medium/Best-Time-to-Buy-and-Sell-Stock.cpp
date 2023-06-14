// Best Time to Buy and Sell Stock (Leetcode)
// Leetcode Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for(int i = 0; i < prices.size(); i++){
            int cost = prices[i] - minPrice;
            maxProfit = max(maxProfit, cost);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};