// Is Subsequence (Leetcode)
// Leetcode Link : https://leetcode.com/problems/is-subsequence/description/

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();

        // Step 1: Initialize DP table with 0
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        // Step 2: Fill DP table based on matching characters
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        // Step 3: Return true if the LCS length equals s.size(), otherwise return false
        return dp[m][n] == m;
    }
};