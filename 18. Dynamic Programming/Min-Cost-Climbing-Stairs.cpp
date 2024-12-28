// Min Cost Climbing Stairs (Leetcode)
// Leetcode Link : https://leetcode.com/problems/min-cost-climbing-stairs/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        
        // Step 1: Fill the dp array with the minimum cost to reach each step
        for(int i = 2; i <= n; i++){
            dp[i] = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]);
        }
        
        // Step 2: Return the minimum cost to reach the top
        return dp[n];
    }
};