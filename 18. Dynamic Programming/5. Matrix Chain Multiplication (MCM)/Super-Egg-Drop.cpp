// Super Egg Drop (Leetcode)
// Leetcode Link : https://leetcode.com/problems/super-egg-drop/description/

// Time Complexity : O(k * n * logn)
// Space Complexity : O(k * n)

class Solution {
public:
    int solve(int k, int n, vector<vector<int>> &dp){
        // Step 1: Base cases - return floor count if 0 or 1 floors, or if only 1 egg left
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;

        // Step 2: Return memoized result if already calculated
        if(dp[k][n] != -1) return dp[k][n];

        int low = 1;
        int high = n;
        int minMoves = INT_MAX - 1;
        // Step 3: Perform binary search to find minimum moves across floors
        while(low <= high){
            int mid = (low + high) / 2;

            // Step 4: Check moves when egg breaks and when it doesn’t
            int broken = dp[k-1][mid-1] != -1 ? dp[k-1][mid-1] : solve(k-1, mid-1, dp);
            int notbroken = dp[k][n-mid] != -1 ? dp[k][n-mid] : solve(k, n-mid, dp);

            // Step 5: Calculate the total moves needed for the worst-case scenario
            int moves = 1 + max(broken, notbroken);
            minMoves = min(minMoves, moves);

            // Step 6: Adjust search range based on comparison
            if(broken > notbroken){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        // Step 7: Store result in dp array and return it
        return dp[k][n] = minMoves;
    }

    int superEggDrop(int k, int n) {
        // Step 8: Initialize dp array with size (k+2) x (n+2) and values -1
        vector<vector<int>> dp(k+2, vector<int> (n+2, -1));
        return solve(k, n, dp);
    }
};