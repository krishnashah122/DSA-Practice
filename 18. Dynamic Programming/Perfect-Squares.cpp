// Perfect Squares (Leetcode)
// Leetcode Link : https://leetcode.com/problems/perfect-squares/description/

// Time Complexity : O(n * sqrt(n))
// Space Complexity : O(n)

class Solution {
public:
    int numSquares(int n) {
        // Step 1: Initialize DP array of (n+1) size to store minimum counts for each value up to n
        vector<int> dp(n+1, 0);

        // Step 2: Fill the DP table iteratively
        for(int i = 1; i <= n; i++){
            int minCount = INT_MAX;

            // Step 3: Check all square numbers less than or equal to i
            for(int j = 1; j*j <= i; j++){
                int result = 1 + dp[i - j*j];
                minCount = min(minCount, result);
            }

            // Step 4: Store the minimum count for i
            dp[i] = minCount;
        }

        // Step 5: Return the least no. of perfect squares for n
        return dp[n];
    }
};