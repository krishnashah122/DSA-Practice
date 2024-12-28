// Minimum Falling Path Sum (Leetcode)
// Leetcode Link : https://leetcode.com/problems/minimum-falling-path-sum/description/

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int result = INT_MAX; // Initialize the result with a very large value

        // Step 1: Create a DP table of (n x n) size with all 0
        vector<vector<int>> dp(n, vector<int> (n, 0));

        // Step 2: Initialize the first row of the DP table with the first row of the matrix
        for(int j = 0; j < n; j++) dp[0][j] = matrix[0][j];

        // Step 3: Fill the DP table row by row starting from the second row
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                // Step 4: Calculate the minimum path sum for the current cell from
                int down = matrix[i][j] + dp[i-1][j]; // Downward cell

                int lDiagonal = matrix[i][j]; // Left diagonal cell
                if(j-1 >= 0){
                    lDiagonal += dp[i-1][j-1];
                } else {
                    lDiagonal += 1e8; // Add a large value if out of bounds
                }
                
                int rDiagonal = matrix[i][j]; // Right diagonal cell
                if(j+1 < n){
                    rDiagonal += dp[i-1][j+1];
                } else {
                    rDiagonal += 1e8; // Add a large value if out of bounds
                }

                // Step 5: Store the minimum value of the three options in the DP table
                dp[i][j] = min(down, min(lDiagonal, rDiagonal));
            }
        }

        // Step 6: Find the minimum value in the last row of the DP table
        for(int j = 0; j < n; j++){
            result = min(result, dp[n-1][j]);
        }

        // Step 7: Return the minimum value
        return result;
    }
};