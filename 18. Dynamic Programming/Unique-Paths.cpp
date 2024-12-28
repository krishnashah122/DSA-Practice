// Unique Paths (Leetcode)
// Leetcode Link : https://leetcode.com/problems/unique-paths/description/

// Time Complexity : O(m*n)
// Space Complexity : O(m*n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Step 1: Initialize dp table with all values as 1, since there's only one way 
        // to reach any cell in the first row or first column (either always right or always down).
        vector<vector<int>> dp(m, vector<int> (n, 1));

        // Step 2: Fill the dp table using previously computed values.
        for(int i = 1; i < m; i++){ // Start from second row
            for(int j = 1; j < n; j++){ // Start from second column
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; // Sum of paths from top and left cells
            }
        }

        return dp[m-1][n-1];
    }
};