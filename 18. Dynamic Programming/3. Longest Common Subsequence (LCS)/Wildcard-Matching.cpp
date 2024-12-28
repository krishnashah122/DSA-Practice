// Wildcard Matching (Leetcode)
// Leetcode Link : https://leetcode.com/problems/wildcard-matching/description/

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        // Step 1: Initialize DP table with false values
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true; // Base case: empty pattern matches empty string

        // Step 2: Initialize the first column for non-empty strings
        for (int i = 1; i <= m; i++) {
            dp[i][0] = false;
        }

        // Step 3: Initialize the first row for patterns consisting of only '*'
        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int j = 1; j <= i; j++) {
                if (p[j - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][i] = flag;
        }

        // Step 4: Fill the DP table based on pattern matching conditions
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1]; // Match exact character or '?'
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; // '*' matches "" or more characters
                } else {
                    dp[i][j] = false; // No match
                }
            }
        }

        // Step 5: Final result indicating if the entire string matches the pattern
        return dp[m][n];
    }
};