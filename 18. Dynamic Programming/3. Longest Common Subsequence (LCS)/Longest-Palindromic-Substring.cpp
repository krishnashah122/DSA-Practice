// Longest Palindromic Substring (Leetcode)
// Leetcode Link : https://leetcode.com/problems/longest-palindromic-substring/description/

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        // Step 1: Initialize a 2D DP table with false values
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        int start = 0; // Track the start index of the longest palindromic substring
        int maxLen = 1; // Track the maximum length of the palindromic substring

        // Step 2: All substrings of length 1 are palindromes
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }

        // Step 3: Check for palindromic substrings of length 2
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                start = i; // Update start index
                maxLen = 2; // Update maximum length
            }
        }

        // Step 4: Expand to check palindromic substrings of length > 2
        for(int len = 3; len <= n; len++){
            for(int i = 0; i < (n-len+1); i++){
                int j = i + len - 1; // Calculate end index of the substring

                // Check if current substring is a palindrome
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    start = i; // Update start index
                    maxLen = len; // Update maximum length
                }
            }
        }

        // Step 5: Construct & return the longest palindromic substring
        return s.substr(start, maxLen);
    }
};