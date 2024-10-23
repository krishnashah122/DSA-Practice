// Maximum Ice Cream Bars (Leetcode)
// Leetcode Link : https://leetcode.com/problems/maximum-ice-cream-bars/description/

// Time Complexity : O(n + nLogn)
// Space Complexity : O(1)

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Step 1: Sort the ice cream costs in ascending order.
        sort(costs.begin(), costs.end());

        int iceCreams = 0;
        // Step 2: Loop through the sorted costs & buy only if you have enough coins else break the loop.
        for(int i = 0; i < costs.size(); i++){
            if(coins < costs[i]) break;
            iceCreams++;
            coins -= costs[i]; // Deduct the cost from available coins.
        }

        return iceCreams;
    }
};