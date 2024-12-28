// Palindromic Substrings (Leetcode)
// Leetcode Link : https://leetcode.com/problems/palindromic-substrings/description/

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int palindromes = 0; // Palindromic substrings counter

        // Step 1: Initialize a 2D DP table with false values
        vector<vector<bool>> dp(n, vector<bool> (n, false));

        // Step 2: All substrings of length 1 are palindromes
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            palindromes++; // Increment counter
        }

        // Step 3: Check for palindromic substrings of length 2
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                palindromes++; // Increment counter
            }
        }

        // Step 4: Expand to check palindromic substrings of length > 2
        for(int len = 3; len <= n; len++){
            for(int i = 0; i < (n-len+1); i++){
                int j = i + len - 1; // Calculate end index of the substring

                // Check if current substring is a palindrome
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    palindromes++; // Increment counter
                }
            }
        }

        // Step 5: Return the no. of palindromic substrings
        return palindromes;
    }
};