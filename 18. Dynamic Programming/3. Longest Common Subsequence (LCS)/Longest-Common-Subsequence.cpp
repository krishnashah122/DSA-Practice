// Longest Common Subsequence (Leetcode)
// Leetcode Link : https://leetcode.com/problems/longest-common-subsequence/description/

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        // Step 1: Create and initialize dp table with all values 0
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        // Step 2: Fill the dp table
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                // Step 3: Check if characters match
                if(text1[i-1] == text2[j-1]){
                    // Current char can contribute to the LCS length
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    // Take the longer LCS by ignoring char from both strings
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        // Step 4: Return the LCS length
        return dp[m][n];
    }
};