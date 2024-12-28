// Shortest Common Supersequence (Leetcode)
// Leetcode Link : https://leetcode.com/problems/shortest-common-supersequence/description/

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        
        // Step 1: Initialize DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Step 2: Fill DP table to find LCS length
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        // Step 3: Construct the SCS using the DP table
        int i = m, j = n;
        string SCS;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) { // If characters match
                // Add common character once before moving diagonally up in the table
                SCS.push_back(str1[i - 1]);
                i--;
                j--;
            } else { // If characters don’t match
                if (dp[i][j - 1] > dp[i - 1][j]) {
                    // Add unique character from str2 before moving left in the table
                    SCS.push_back(str2[j - 1]);
                    j--;
                } else {
                    // Add unique character from str1 before moving up in the table
                    SCS.push_back(str1[i - 1]);
                    i--;
                }
            }
        }

        // Step 4: Add remaining characters (if any)
        while (i > 0) {
            SCS.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            SCS.push_back(str2[j - 1]);
            j--;
        }

        // Step 5: Reverse the SCS to get the correct order
        reverse(SCS.begin(), SCS.end());

        return SCS;
    }
};