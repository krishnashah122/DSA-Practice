// Longest Common Substring (GFG)
// GFG Link : https://shorturl.at/sL6WI

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        int m = str1.size();
        int n = str2.size();
        
        // Step 1: Initialize DP table with all values as 0
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        int longest = 0;
        
        // Step 2: Fill DP table by comparing characters
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1]; // Increase count if characters match
                    longest = max(longest, dp[i][j]); // Update longest
                } else {
                    dp[i][j] = 0; // Reset to 0 if characters do not match
                }
            }
        }
        
        // Step 3: Return the length of the longest common substring
        return longest;
    }
};