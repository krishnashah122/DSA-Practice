// Maximum Length of Pair Chain (Leetcode)
// Leetcode Link : https://leetcode.com/problems/maximum-length-of-pair-chain/description/

// Time Complexity : O(n^2)
// Space Complexity : O(n)

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        // Step 1: Initialize dp table of size (n+1) to store the longest chain length ending at each index
        vector<int> dp(n+1, 1); // Initialize all with 1, as the minimum chain length is 1

        // Step 2: Sort the pairs based on the first element
        sort(pairs.begin(), pairs.end());

        int longestChain = 1; // Initialize the longest chain length to 1, as the minimum chain length is 1
        // Step 3: Iterate through all pairs and calculate the longest chain
        for(int idx = 0; idx < n; idx++){
            for(int prevIdx = 0; prevIdx < idx; prevIdx++){
                // Step 4: Check if the current pair can form a chain with the previous pair
                if(pairs[prevIdx][1] < pairs[idx][0]){
                    dp[idx] = max(dp[idx], 1 + dp[prevIdx]);
                }
            }
            // Step 5: Update the length of the longest chain
            longestChain = max(longestChain, dp[idx]);
        }

        // Step 6: Return the longest chain length
        return longestChain;
    }
};