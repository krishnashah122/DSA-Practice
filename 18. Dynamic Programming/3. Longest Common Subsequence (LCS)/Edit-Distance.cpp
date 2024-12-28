// Edit Distance (Leetcode)
// Leetcode Link : https://leetcode.com/problems/edit-distance/description/

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // Step 1: Initialize a DP table of size (m+1) x (n+1) with 0
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        // Step 2: Fill the first row & column of DP table
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0) dp[i][j] = j; // Insertion cost
                if(j == 0) dp[i][j] = i; // Deletion cost
            }
        }

        // Step 3: Fill DP table based on matching characters or choosing the minimum operation
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i-1] == word2[j-1]){
                    // If characters match, no operation needed
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // Choose min operation (insert, delete, replace)
                    dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                }
            }
        }

        // Step 4: Return the minimum no. of operations
        return dp[m][n];
    }
};