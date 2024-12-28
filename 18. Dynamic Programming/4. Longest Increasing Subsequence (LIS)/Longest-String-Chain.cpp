// Longest String Chain (Leetcode)
// Leetcode Link : https://leetcode.com/problems/longest-string-chain/description/

// Time Complexity : O(n^2)
// Space Complexity : O(n)

class Solution {
public:
    bool check(string &s1, string &s2){
        // Step 1: Check if s1 has exactly one more character than s2
        if (s1.size() != s2.size() + 1) return false;

        // Step 2: Check if s2 is a predecessor of s1 by comparing characters
        int i = 0;
        int j = 0;
        while (i < s1.size()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        // Step 3: If all characters in s2 were matched in s1, return true
        return (i == s1.size() && j == s2.size());
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        // Step 4: Sort words by length in ascending order
        sort(words.begin(), words.end(), [&](string &s1, string &s2) {
            return s1.size() < s2.size();
        });

        // Step 5: Initialize dp array to store longest chain ending at each word
        vector<int> dp(n, 1);
        int maxi = 0;

        // Step 6: Build the longest chain by iterating over each word
        for (int idx = 0; idx < n; idx++) {
            for (int prev = 0; prev < idx; prev++) {
                // Step 7: Check if words[prev] can be a predecessor of words[idx]
                if (check(words[idx], words[prev]) && 1 + dp[prev] > dp[idx]) {
                    dp[idx] = 1 + dp[prev];
                }
            }
            // Step 8: Update the maximum chain length
            maxi = max(maxi, dp[idx]);
        }

        // Step 9: Return the maximum chain length found
        return maxi;
    }
};