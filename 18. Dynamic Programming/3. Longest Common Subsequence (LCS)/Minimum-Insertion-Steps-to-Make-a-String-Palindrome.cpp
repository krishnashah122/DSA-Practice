// Minimum Insertion Steps to Make a String Palindrome (Leetcode)
// Leetcode Link : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        // Step 1: Copy 's' & reverse it to compare with the original
        string str = s;
        reverse(str.begin(), str.end());

        // Step 2: Initialize DP table of size (n+1) x (n+1)
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // Step 3: Fill the DP table to find the LCS length
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == str[j-1]){
                    // If characters match, increase the length of common subsequence
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    // If they don’t match, take the maximum length found so far
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        // Step 4: Minimum no. of insertions (i.e, s.size() - LCS length)
        return (n - dp[n][n]);
    }
};