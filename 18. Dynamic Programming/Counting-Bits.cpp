// Counting Bits (Leetcode)
// Leetcode Link : https://leetcode.com/problems/counting-bits/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    vector<int> countBits(int n) {
        // Step 1: Initialize a 'n+1' size 'dp' vector with all values as 0
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= n; i++){
            // Step 2: Calculate the number of 1s in binary representation of i
            dp[i] = dp[i/2] + (i % 2);
        }
        return dp;
    }
};