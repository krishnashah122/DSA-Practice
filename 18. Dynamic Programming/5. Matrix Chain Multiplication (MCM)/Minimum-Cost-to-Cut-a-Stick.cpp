// Minimum Cost to Cut a Stick (Leetcode)
// Leetcode Link : https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

// Time Complexity : O(c^3)
// Space Complexity : O(c^2)

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // Step 1: Sort the cuts and insert boundary points (0 and n)
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0); // Add 0 as the starting point
        cuts.push_back(n); // Add n as the ending point

        int c = cuts.size();
        
        // Step 2: Initialize the DP table with zero values
        vector<vector<int>> dp(c, vector<int>(c, 0));

        // Step 3: Fill the DP table using tabulation
        // len represents the length of the stick
        for (int len = 2; len < c; len++) {
            // Step 4: Set the start index 'i' & end index 'j'
            for (int i = 0; i < c - len; i++) {
                int j = i + len;

                int minimum = INT_MAX;
                // Step 5: Calculate the minimum cost by trying each cut position k between i and j
                for (int k = i + 1; k < j; k++) {
                    int cost = (cuts[j] - cuts[i]) + dp[i][k] + dp[k][j];
                    minimum = min(minimum, cost);
                }
                
                dp[i][j] = minimum; // Update minimum cost
            }
        }

        // Step 6: Return the minimum cost
        return dp[0][c - 1];
    }
};