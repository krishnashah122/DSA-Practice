// Shortest Common Supersequence - Length (GFG)
// GFG Link : https://shorturl.at/2OEGw

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        // Step 1: Initialize DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Step 2: Fill DP table to find LCS length
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (X[i - 1] == Y[j - 1]) { // If characters match
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else { // If characters don’t match
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        
        // Step 3: Calculate and return length of SCS [i.e, X.size() + Y.size() - LCS]
        return ((m + n) - dp[m][n]);
    }
};