// Delete Operation for Two Strings (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/delete-operation-for-two-strings/description/
// GFG Link : https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // Step 1: Create a DP table of size (m+1) x (n+1)
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        // Step 2: Fill the DP table to find LCS length
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i-1] == word2[j-1]){
                    // If characters match, increase the length of common subsequence
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    // If they don’t match, take the maximum length found so far
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        // Step 3: Calculate the no. of deletions and insertions needed
        int deletions = m - dp[m][n]; // word1.size() - LCS length
        int insertions = n - dp[m][n]; // word2.size() - LCS length

        // Step 4: Return the total no. of operations
        return (deletions + insertions);
    }
};