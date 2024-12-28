// Unique Paths II (Leetcode)
// Leetcode Link : https://leetcode.com/problems/unique-paths-ii/description/

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // Step 1: Create a DP table of (m x n) size
        vector<vector<int>> dp(m, vector<int> (n));

        // Step 2: Iterate through each cell in the grid
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // Step 3: If the cell is an obstacle, set dp[i][j] to 0
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                } else if(i == 0 && j == 0) {
                    // Step 4: Set starting point dp[0][0] to 1 (only one way to start)
                    dp[i][j] = 1;
                } else {
                    // Step 5: Calculate paths from top and left cells, if within bounds
                    int up = (i > 0) ? dp[i-1][j] : 0;
                    int left = (j > 0) ? dp[i][j-1] : 0;
                    // Step 6: Add paths from top and left cells
                    dp[i][j] = up + left;
                }
            }
        }

        // Step 7: Return the value at the bottom-right corner of the DP table
        return dp[m-1][n-1];
    }
};