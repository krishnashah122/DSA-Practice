// Triangle (Leetcode)
// Leetcode Link : https://leetcode.com/problems/triangle/description/

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Step 1: Create a DP table of (n x n) size with all 0
        vector<vector<int>> dp(n, vector<int> (n, 0));

        // Step 2: Initialize the last row of dp with the last row of triangle
        for(int j = 0; j < n; j++) dp[n-1][j] = triangle[n-1][j];

        // Step 3: Fill the dp array from bottom to top
        for(int i = n-2; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {
                // Step 4: Calculate the sum by moving straight down & diagonally one by one
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];

                // Step 5: Store the minimum of both paths in dp table
                dp[i][j] = min(down, diagonal);
            }
        }

        // Step 6: Return the minimum path sum from the top of the triangle
        return dp[0][0];
    }
};