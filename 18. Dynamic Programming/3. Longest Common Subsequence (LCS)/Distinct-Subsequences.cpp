// Distinct Subsequences (Leetcode)
// Leetcode Link : https://leetcode.com/problems/distinct-subsequences/description/

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        // Step 1: Initialize DP table of size (m+1) x (n+1) with all values 0
        vector<vector<double>> dp(m+1, vector<double> (n+1, 0));

        // Step 2: Set the first column to 1 since an empty 't' can always be matched by deleting all of 's'
        for(int i = 0; i <= m; i++){
            dp[i][0] = 1;
        }

        // Step 3: Fill DP table based on subsequence matching conditions
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                // If characters match, consider both options: using and skipping the current character of 't'
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else { // If they don't match, skip the character from 's'
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        // Step 4: Return the final answer at dp[m][n]
        return dp[m][n];
    }
};