// Minimum Path Sum (Leetcode)
// Leetcode Link : https://leetcode.com/problems/minimum-path-sum/description/

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));

        // Step 1: Traverse each cell in the grid
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                // Step 2: Initialize the first cell
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                }else{
                    // Step 3: Calculate the minimum path sum for the current cell
                    int up = grid[i][j];
                    if(i > 0){
                        up += dp[i-1][j];
                    }else{
                        up = INT_MAX;
                    }

                    int left = grid[i][j];
                    if(j > 0){
                        left += dp[i][j-1];
                    }else{
                        left = INT_MAX;
                    }
                    
                    dp[i][j] = min(up, left); // Store the minimum path sum
                }
            }
        }
        
        // Step 4: Return the minimum path sum to reach the bottom-right cell
        return dp[m-1][n-1];
    }
};