// Count Square Submatrices with All Ones (Leetcode)
// Leetcode Link : https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: Initialize a DP table of the same size as 'matrix' with all zeros
        vector<vector<int>> dp(m, vector<int> (n, 0));

        // Step 2: Fill the first row & column of DP table with values from 'matrix'
        for(int i = 0; i < m; i++) dp[i][0] = matrix[i][0];
        for(int j = 0; j < n; j++) dp[0][j] = matrix[0][j];

        // Step 3: Calculate the size of squares ending at each cell (i, j)
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    // If current cell in matrix is 0, no square ends here
                    dp[i][j] = 0;
                } else {
                    // Else, take minimum of three adjacent cells and add 1
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }

        // Step 4: Sum up all values in the DP table to get the total count of squares
        int totalSquares = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                totalSquares += dp[i][j];
            }
        }

        // Step 5: Return the total count of square submatrices
        return totalSquares;
    }
};