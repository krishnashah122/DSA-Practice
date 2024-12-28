// Palindrome Partitioning II (Leetcode)
// Leetcode Link : https://leetcode.com/problems/palindrome-partitioning-ii/description/

// Time Complexity : O(n^3)
// Space Complexity : O(n)

class Solution {
public:
    // Function to check if substring s[i..j] is a palindrome or not
    bool isPalindrome(string &s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    int minCut(string s) {
        int n = s.size();
        // Step 1: Initialize DP array of (n+1) size with all 0
        vector<int> dp(n + 1, 0);

        // Step 2: Fill DP array from the end of the string
        for (int i = n - 1; i >= 0; i--) {
            int minimum = INT_MAX; // Track minimum cuts
            for (int j = i; j < n; j++) {
                // Step 3: If the substring s[i..j] is a palindrome, calculate cuts & update minimum cuts
                if (isPalindrome(s, i, j)) {
                    int cuts = 1 + dp[j + 1];
                    minimum = min(minimum, cuts);
                }
            }
            dp[i] = minimum; // Store the result in dp
        }

        // Step 4: Return the minimum cuts
        // dp[0] - 1 : cuts required are 1 less than the no. of segments formed
        return dp[0] - 1;
    }
};